function LMinstall(varargin);
%
% Downloads a set of folders from the LabelMe dataset.
%
% 1) Install all the images
%  LMinstall(HOMEIMAGES, HOMEANNOTATIONS);
%
% 2) install only images in the specified folders
%  LMinstall(folderlist, HOMEIMAGES, HOMEANNOTATIONS);
%
% 3) install only the images specified
%  LMinstall(folders, images, HOMEIMAGES, HOMEANNOTATIONS);
%
% This function is useful if you do not want to download the entire
% dataset. You can first browse the dataset, and when you have decided for
% a set of folders that you want to use, you can use this function to
% download only those folders.
%
% Contribute to the dataset by labeling few images:
% http://people.csail.mit.edu/brussell/research/LabelMe/intro.html


% If this function stops working, you might need to download the newest
% version of the toolbox in order to update the web addresses:

webpageanno = 'http://people.csail.mit.edu/brussell/research/LabelMe/Annotations';
webpageimg = 'http://people.csail.mit.edu/brussell/research/LabelMe/Images';

Narguments = length(varargin);

switch Narguments
    case {0,1}
        error('Not enough input arguments.')
    case 2
        disp('Install full database (more than 10Gb required)')
        HOMEIMAGES = varargin{1};
        HOMEANNOTATIONS = varargin{2};
        folderlist = urldir(webpageimg, 'DIR');
        folderlist = {folderlist(:).name};
        if strcmp(folderlist{1}(1),'/'); % remove root folder
            folderlist = folderlist(2:end);
        end
    case 3
        folderlist = varargin{1};
        HOMEIMAGES = varargin{2};
        HOMEANNOTATIONS = varargin{3};
    case 4
        folders = varargin{1};
        filelist = varargin{2};
        folderlist = unique(folders);
        HOMEIMAGES = varargin{3};
        HOMEANNOTATIONS = varargin{4};
end

Nfolders = length(folderlist);

% create folders:
disp('create folders');
for i = 1:Nfolders
    mkdir(HOMEIMAGES, folderlist{i});
    mkdir(HOMEANNOTATIONS, folderlist{i});
end


disp('download images and annotations...')
for f = 1:Nfolders
    disp(sprintf('Downloading folder %s (%d/%d)...',  folderlist{f}, f, Nfolders))
    
    wpi = [webpageimg  '/' folderlist{f}];
    wpa = [webpageanno '/' folderlist{f}];

    if Narguments<4
        images = urldir(wpi, 'img');
        if length(images)>0
            images = {images(:).name};
        end
        
        annotations = urldir(wpa, 'txt');
        if length(annotations)>0
            annotations = {annotations(:).name};
        end
    else
        j = findstr(folders,folderlist{f});
        images = filelist(j);
        annotations = strrep(filelist(j), '.jpg', '.xml');
    end
    
    
    Nimages = length(images);
    for i = 1:Nimages
        disp(sprintf('    Downloading image %s (%d/%d)...',  images{i}, i, Nimages))
        [F,STATUS] = urlwrite([wpi '/' images{i}], fullfile(HOMEIMAGES,folderlist{f},images{i}));
    end
    
    Nanno= length(annotations);
    for i = 1:Nanno
        disp(sprintf('    Downloading annotation %s (%d/%d)...',  annotations{i}, i, Nanno))
        [F,STATUS] = urlwrite([wpa '/' annotations{i}], fullfile(HOMEANNOTATIONS,folderlist{f},annotations{i}));
    end
end
