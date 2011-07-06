function [recall, precision, Dd] = LMrecallPrecision(Dgt, Dd, objects)
% Plots a precision-recall curve.
%
% It uses two matlab structs:
% Dgt = groundtruth dataset
% Dd =  detection dataset
% 
% The groundtruth dataset is a struct that can be the result of a query.
% The detection struct, is the output of a detector. It is supposed to have
% the same structure than the groundtruth dataset. It should be as if a
% human had labeled the images.
% There should be an additional field indicating the detectors confidende:
% detection.annotation.object.confidence
%
% So, the detector should generate a struct with the next fields:
%            detection(n).annotation.filename =  STRING
%            detection(n).annotation.folder   =  STRING 
%            detection(n).annotation.object(kn).name =  STRING
%            detection(n).annotation.object(kn).confidence =  DOUBLE
%            detection(n).annotation.object(kn).polygon.pt(i).x = STRING
%            detection(n).annotation.object(kn).polygon.pt(i).y = STRING
%
%  where i = 1:4 for the four corners of the bounding box
%  kn loops on all the objects present on image n
%  n loops on the images on the dataset
%
% For images in Dgt that are not present in Dd, we will count all the
% instances as missed.
%
% In the output, we will add a field to the struct indicating if it is a
% correct detection, a false alarm, or a missed target.
%


Nclasses = length(objects);

NimagesGt = length(Dgt);
NimagesD = length(Dd);

if NimagesGt~=NimagesD
    error('Both database structs should be computed on the same images. D1 and D2 have different number of images.');
end

last = NimagesD;

% Inititalize score array
for c = 1:Nclasses
     score{c} = [];
     correct{c} = [];
end

for i = 1:NimagesGt
    i
    % Find in Dd the image from the groundtruth dataset
    [detection,ndx] = LMquery(Dd, 'filename', lower(Dgt(i).annotation.filename));
    [detection,ndx2] = LMquery(detection, 'folder', lower(Dgt(i).annotation.folder));
    ndx = ndx(ndx2); % pointer to current image in detection struct

    % if there are multiple matches, then there is a problem:
    if length(detection)>1
        error(sprintf('Multiple matches! image %s/%s seems to appear more than once',Dgt(i).annotation.folder,Dgt(i).annotation.filename))
    end

    if length(detection) == 0
        % If no objects are detected for this image, then, mark all the
        % objects as missed targets.
        if isfield(Dgt(i).annotation, 'object')
            Dd(last+1).annotation = Dgt(i).annotation;
            for m = 1:length(Dd(last+1).annotation.object)
                Dd(last+1).annotation.object(m).detection = 'missed';
            end
            last = last+1;
        end
    else
        % If there are some detections, then mark them as correct
        % detections, false alarms. Also insert the missed targets.
        for c = 1:Nclasses
            % Get polygons from ground truth -> bounding boxes
            [xt,yt] = LMobjectpolygon(Dgt(i).annotation, objects{c});
            Ngt = length(xt);

            % Get polygons detection
            [xd,yd] = LMobjectpolygon(detection.annotation, objects{c});
            Nd = length(xd);

            % Get bounding boxes
            if Nd>0 & Ngt>0
                Bt = zeros(Ngt, 4);
                for n = 1:Ngt
                    % ground truth bounding box: [x y width height]
                    Bt(n,:) = [min(xt{n}) min(yt{n}) max(xt{n})-min(xt{n}) max(yt{n})-min(yt{n})];
                end

                % Get bounding boxes
                Bd = zeros(Nd, 4);
                for n = 1:Nd
                    Bd(n,:) = [min(xd{n}) min(yd{n}) max(xd{n})-min(xd{n}) max(yd{n})-min(yd{n})];
                end
                confidence = [detection.annotation.object.confidence];

                % Compute overlappings between bounding-boxes
                overlap = overlapping(Bd, Bt);

                % Assign detections to ground truth targets. First start with the most confident detections.
                % Once a target gets assigned to one detection, that target cannot be used again
                % and the rest of detections are labeled as false alarms.
                [foo,s] = sort(-confidence); 
                nd = [];
                for n = s
                    j = find(overlap(n,:)>.5 & overlap(n,:)>max(overlap(n,:))-.001);
                    if length(j) >0 & ~ismember(j, nd)
                        nd(n) = j(1);
                    else
                        nd(n) = -1; % this is a false alarm
                    end
                end
                missedTargets = setdiff(1:Ngt, nd);
                falseAlarms = find(nd==-1);
                correctDetections = find(nd>0);
            end

            if Nd==0 & Ngt>0
                % all targets are missed
                missedTargets = 1:Ngt;
                falseAlarms = [];
                correctDetections = [];
            end
            if Ngt==0 & Nd>0
                % all detections are false alarms
                confidence = [detection.annotation.object.confidence];
                missedTargets = [];
                falseAlarms = 1:Nd;
                correctDetections = [];
            end

            if Ngt>0 | Nd>0
                if length(falseAlarms)>0
                    for a = 1:length(falseAlarms)
                        Dd(ndx).annotation.object(falseAlarms(a)).detection='false';
                    end
                end
                if length(correctDetections)>0
                    for a = 1:length(correctDetections)
                        Dd(ndx).annotation.object(correctDetections(a)).detection='correct';
                    end
                end
                if length(missedTargets)>0
                    if isfield(Dd(ndx).annotation, 'object')
                        Nobj = length(Dd(ndx).annotation);
                    else Nobj=0;
                    end
                    for a = 1:length(missedTargets)
                        Dd(ndx).annotation.object(Nobj+a).name = Dgt(i).annotation.object(missedTargets(a)).name;
                        Dd(ndx).annotation.object(Nobj+a).polygon = Dgt(i).annotation.object(missedTargets(a)).polygon;
                        Dd(ndx).annotation.object(Nobj+a).detection = 'missed';
                    end
                end
            end
	    
	    if Nd>0
	       score{c} = [score{c} confidence];
	       cr = zeros(1,Nd); cr(correctDetections)=1;
	       correct{c} = [correct{c} cr];
	    end

        end
    end
end

% Compute Precision-Recall

recall{1} = [];
precision{1} = [];
threholds = [];

for c = 1:Nclasses
    Ntargets(c) = sum(LMcountobject(Dgt, objects{c}));

    if Ntargets(c) >0
        [S,j] = sort(-score{c}); % retrieved elements are the ones above or equal to the threshold
        C = correct{c}(j);
        n = length(C);

        REL    = Ntargets(c);
        if n>0
            RETREL = cumsum(C);
            RET    = 1:n;
        else
            RETREL = 0;
            RET    = 1;
        end

        precision{c} = RETREL ./ RET;
        recall{c}    = RETREL  / REL;
    end
end




function overlap = overlapping(A, B)

n = size(A,1);
m = size(B,1);

intersection = rectint(A,B);
areaA = diag(rectint(A,A));
areaB = diag(rectint(B,B));

for i = 1:n
    for j = 1:m
        % Union of bounding boxes:
        ua = (areaA(i)+areaB(j)-intersection(i,j));
        
        % PASCAL measure:
        %pp = [min(A(i,1),B(j,1)) min(A(i,2),B(j,2)) max(A(i,1)+A(i,3),B(j,1)+B(j,3))  max(A(i,2)+A(i,4),B(j,2)+B(j,4))];
        %ua = (pp(3)-pp(1))*(pp(4)-pp(2));
        overlap(i,j) = intersection(i,j) / ua;
    end
end
