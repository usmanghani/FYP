function [annotation, img] = LMimscale(annotation, img, scaling, method);
%
% Scales one image (as in imresize) and the associated annotation.
% The scale factor is given by 'scaling'
% 
% When scaling<1, the image is downsampled.
%
% [annotation, img] = LMimscale(annotation, img, scaling);
%

% Store the original numerical format of the image and turn it into 'double'.
imgtype = whos('img');
img = double(img);

if nargin < 4
    method = 'nearest';
end

if scaling ~= 1
    % Image resampling:
    img = imresizefast(img, scaling, method);

    % Change the size of the polygon coordinates
    if isfield(annotation, 'object')
        Nobjects = length(annotation.object); n=0;
        for i = 1:Nobjects
            Npoints = length(annotation.object(i).polygon.pt);
            for j = 1:Npoints
                % Scale each point:
                x=str2num(annotation.object(i).polygon.pt(j).x);
                y=str2num(annotation.object(i).polygon.pt(j).y);

                x = round(x*scaling);
                y = round(y*scaling);

                annotation.object(i).polygon.pt(j).x = num2str(x);
                annotation.object(i).polygon.pt(j).y = num2str(y);
            end
        end
    end
end

% return the image in its original numeric format
img = feval(imgtype.class, img);


function img = imresizefast(img, scaling, method, init);

if nargin<4
    init = 0;
end

if scaling > .5
    img = imresize(img, scaling, method);
else
    img = convn(img, [1 2 1]'/4, 'same'); 
    img = img(init+1:2:end, :, :);
    img = convn(img, [1 2 1]/4, 'same'); 
    img = img(:,init+1:2:end,:);
    img = imresizefast(img, 2*scaling, method, 1-init);
end



