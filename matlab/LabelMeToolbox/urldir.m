function files = urldir(page, tag)
%
% Lists the files within a URL
%
% Collecion of folders:
% files = urldir(page, 'DIR')
% Collection of files:
% files = urldir(page, 'TXT')

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% LabelMe, the open annotation tool
% Contribute to the database by labeling objects using the annotation tool.
% 
% CSAIL, MIT
% 2006
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

if nargin == 1
    tag = '[dir]';
    tag = '/'
else
    tag = lower(tag);
    if strcmp(tag, 'dir')
        tag = '/';
    end
    if strcmp(tag, 'txt')
        tag = 'xml';
    end
    if strcmp(tag, 'img')
        tag = 'jpg';
    end
end

nl = length(tag);
nfiles = 0;
files = [];

% Read page
page = strrep(page, '\', '/');
webpage = urlread(page);

% Parse page
j1 = findstr(lower(webpage), '<a href="');
j2 = findstr(lower(webpage), '</a>');
Nelements = length(j1);
if Nelements>0
    for f = 1:Nelements
        % get HREF element
        chain = webpage(j1(f):j2(f));
        jc = findstr(lower(chain), '">');
        chain = deblank(chain(10:jc(1)-1));
        
        % check if it is the right type
        if strcmp(chain(end-nl+1:end), tag)
            nfiles = nfiles+1;
            files(nfiles).name = chain;
        end
   end    
end

