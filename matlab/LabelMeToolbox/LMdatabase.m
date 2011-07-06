function [database, XML] = LMdatabase(HOMEANNOTATIONS, folderlist)
%
% This line reads the entire database into a Matlab struct
% database = LMdatabase(HOMEANNOTATIONS);
%
% Reads all the annotations.
% It creates a struct 'almost' equivalent to what you would get if you concatenate
% first all the xml files, then you add at the beggining the tag <database> and at the end </database> 
% and then use loadXML.m
%
% You do not need to download the database. The functions that read the
% images and the annotation files can be refered to the online tool. For
% instance, you can run the next command:
%
% HOMEANNOTATIONS = 'http://people.csail.mit.edu/brussell/research/LabelMe/Annotations'
% database = LMdatabase(HOMEANNOTATIONS);
%
% This will create the database struct without needing to download the
% database. It might be slower than having a local copy. You can do the
% same for the images:

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% LabelMe, the open annotation tool
% Contribute to the database by labeling objects using the annotation tool.
% http://people.csail.mit.edu/brussell/research/LabelMe/intro.html
% 
% CSAIL, MIT
% 2006
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

if nargin == 1
    if ~strcmp(HOMEANNOTATIONS(1:5), 'http:');
        folders = genpath(HOMEANNOTATIONS);
        h = [findstr(folders,  pathsep)];
        h = [0 h];
        Nfolders = length(h)-1
        for f = 1:Nfolders
            Folder{f} = folders(h(f)+1:h(f+1)-1);
        end
    else
        files = urldir(HOMEANNOTATIONS);
        Folder = {files(2:end).name}; % the first item is the main path name
        Nfolders = length(Folder);
        for i = 1:Nfolders
            Folder{i} = fullfile(HOMEANNOTATIONS, Folder{i});
        end
    end
else
    Nfolders = length(folderlist);
    for i = 1:Nfolders
        Folder{i} = fullfile(HOMEANNOTATIONS, folderlist{i});
    end
end

screenSize = get(0,'ScreenSize');
pointsPerPixel = 72/get(0,'ScreenPixelsPerInch');
width = 360 * pointsPerPixel;
height = 2*75 * pointsPerPixel;
pos = [screenSize(3)/2-width/2 screenSize(4)/2-height/2 width height];
Hfig = figure('Units', 'points', ...
    'NumberTitle','off', ...
    'IntegerHandle','off', ...
    'MenuBar', 'none', ...
    'Visible','on',...
    'position', pos,...
    'BackingStore','off',...
    'DoubleBuffer','on');

% Loop on folders
database = []; n = 0; nPolygons = 0;
if nargout == 2; XML = ['<database>']; end
for f = 1:Nfolders
    folder = Folder{f};
    disp(sprintf('%d/%d, %s', f, Nfolders, folder))
    
    if ~strcmp(folder(1:5), 'http:');
        filesAnnotations = dir(fullfile(folder, '*.xml'));
    else
        filesAnnotations = urlxmldir(folder);
    end
    
    N = length(filesAnnotations);
    fprintf(1, '%d ', N)
    for i = 1:N
        fprintf(1, '.')
        % load file
        filename = fullfile(folder, filesAnnotations(i).name);
        if filesAnnotations(i).bytes > 0
            [v, xml] = loadXML(filename);
            n = n+1;
            
            % add view point into the object name
            if isfield(v.annotation, 'object')
                for j = 1:length(v.annotation.object)
                    if isfield(v.annotation.object(j), 'viewpoint')
                        if ~isempty(v.annotation.object(j).viewpoint)
                            a = str2num(v.annotation.object(j).viewpoint.azimuth);
                            v.annotation.object(j).name = [v.annotation.object(j).name sprintf(' az%ddeg', a)];
                        end
                    end
                end
            end
            
            % store annotation into the database
            database(n).annotation = v.annotation;

            if nargout == 2
                XML = [XML xml];
            end
            
            plotbar(Hfig,f,Nfolders,i,N);
        else
            disp(sprintf('file %s is empty', filename))
        end
    end
    fprintf(1, '\n')
end

if nargout == 2; XML = [XML '</database>']; end

% % Summary database;
[names, counts] = LMobjectnames(database);
disp('-----------------')
disp(sprintf('LabelMe Database summary:\n Total of %d annotated images. \n There are %d polygons assigned to %d different object names', length(database), sum(counts), length(names)))
disp('-----------------')
% 
close(Hfig)

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
function plotbar(fig,nf,Nf,ni,Ni,message)

clf(fig)
ha = subplot(2,1,1, 'parent', fig); cla(ha)
p = patch([0 1 1 0],[0 0 1 1],'w','EraseMode','none', 'parent', ha);
p = patch([0 1 1 0]*nf/Nf,[0 0 1 1],'g','EdgeColor','k','EraseMode','none', 'parent', ha);
axis(ha,'off')
title(sprintf('folders (%d/%d)',nf,Nf), 'parent', ha)
ha = subplot(2,1,2, 'parent', fig); cla(ha)
p = patch([0 1 1 0],[0 0 1 1],'w','EraseMode','none', 'parent', ha);
p = patch([0 1 1 0]*ni/Ni,[0 0 1 1],'r','EdgeColor','k','EraseMode','none', 'parent', ha);
axis(ha,'off')
title(sprintf('files (%d/%d)',ni,Ni), 'parent', ha)
drawnow







function files = urlxmldir(page)

files = [];
page = strrep(page, '\', '/');
folders = urlread(page);
ji = findstr(lower(folders), '[txt]');
ji = 1
if length(ji)>0
    folders = folders(ji(1):length(folders));
    j1 = findstr(lower(folders), '<a href="');
    j2 = findstr(lower(folders), '</a>');
    Nfolders = length(j1);
    clear Folder
    fn = 0;
    for f = 1:Nfolders
        tmp = folders(j1(f)+9:j2(f)-1);
        fin = findstr(tmp, '"');
        if length(findstr(tmp(1:fin(end)-1), 'xml'))>0
            fn = fn+1;
            Folder{fn} = tmp(1:fin(end)-1);
        end
    end
else
    files = [];
end

if length(Folder)>0
    for f = 1:length(Folder)
        files(f).name = Folder{f};
        files(f).bytes = 1;
    end
end
