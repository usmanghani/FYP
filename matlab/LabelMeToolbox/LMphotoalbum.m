function LMphotoalbum(folderlist, filelist, pagename, HOMEIMAGES);
%
% LMphotoalbum(folderlist, filelist, pagename, HOMEIMAGES);
%
% HOMEIMAGES should be the path for the images in your local copy of the
% database.
%
% This function allows building an interface that communicates with the
% LabelMe web annotation tool. 
%
% It can be used to label specific images.
% 
% You can use this to label images that have some characteristic that you
% want. You can use this function in combination with the LMquery function.
%
% For instance, if you want to create a web page with images only of
% kitchens so that the thumbnails are connected to the LabelMe web
% annotation tool online, you can do the next thing:
%
% [D,j] = LMquery(database, 'folder', 'kitchen');
% for i = 1:length(D);
%    folderlist{i} = D(i).annotation.folder;
%    filelist{i} = D(i).annotation.filename;
% end
% LMphotoalbum(folderlist, filelist, 'myphotoalbum.html', HOMEIMAGES);
%
% This will create a web page with thumbnails of the selected images. But
% more importantly, the images will be link with the LabelMe online tool.
% So, whenever you will click on one image it will call the annotation tool
% and will open that specific image showing the annotations available
% online (not the local ones that you have). Now you can label more objects
% in that image and download later the annotations.


Nimages = length(folderlist);
webpage = 'http://people.csail.mit.edu/brussell/research/LabelMe/beta.html?collection=LabelMe'

% Hearder
page = {};
page = addline(page, '<html><head><title>LabelMe photoalbum</title><body>');
page = addline(page, '<img src="http://people.csail.mit.edu/brussell/research/LabelMe/LabelMeNEWtight198x55.gif" height=55 alt="please" />');
page = addline(page, '<b><font size=5>Photoalbum</font></b><br>');
page = addline(page, '<hr align="Left" size="1"><br>');
page = addline(page, '<b><font size=4>Click on an image to visualize it with the online annotation tool</font></b><br>');

% Create links for each image
for i = 1:Nimages
    imageline = sprintf('<IMG src="file://%s" width=160 height=120 border=2>', ...
        strrep(fullfile(HOMEIMAGES, folderlist{i}, filelist{i}), '\', '\\'));
    page = addline(page, ...
        [sprintf('<a href="%s&folder=%s&image=%s">%s</a>', ...
        webpage, folderlist{i}, filelist{i}, imageline)]);
end
page = addline(page, '<hr align="Left" size="1"><br>');

% Close web page
page = addline(page, '</body></html>');

% write web page
fid = fopen(pagename,'w');
for i = 1:length(page); 
    fprintf(fid, [page{i} '\n']); 
end
fclose(fid);


function page = addline(page, line)

page = [page {line}];
