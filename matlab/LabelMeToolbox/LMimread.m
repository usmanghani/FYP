function img = LMimread(D, ndx, HOMEIMAGES)
%
% Reads one image from the database. 
%     img = LMimread(database, ndx, HOMEIMAGES);
%
% This function is similar to LMread. Just for compatibility.

filename = fullfile(HOMEIMAGES, D(ndx).annotation.folder, D(ndx).annotation.filename);
filename = strrep(filename, '\', '/');

img = imread(filename);


