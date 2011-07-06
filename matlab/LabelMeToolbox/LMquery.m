function [database, j] = LMquery(database, fieldName, content, method)
%
% This function provides basic query functionalities. It allows you to
% locate images with certain objects.
%
% [database, j] = LMquery(database, fieldName, content, method)
%
%    database:  struct
%    fieldName: can be any of the fields in the struct at the object level.
%    content:   a string describing the desired field you are looking for.
%               you can use the characters '+' and '-' within the content string in
%               order to perform 'and' and 'not' operations.
%    method:    {'', 'exact'}: when selected 'exact', the content must be match exactly
% 
% The function LMquery searchs for images in the database.
% Queries can be done on any field of the struct array.
% The fields for an image are:
%    filename
%    folder
%    source.sourceImage
%    source.sourceAnnotation
%    object(:).name
%    object(:).deleted
%    object(:).verified
%    object(:).date
%    object(:).polygon.username
%    object(:).polygon.pt(:).x
%    object(:).polygon.pt(:).y
%    object(:).viewpoint.azimuth
%
% Look at the results of these two lines (HOMEIMAGES should be set with the path of the database):
% LMdbshowobjects(LMquery(database, 'object.name', 'plate+license'), HOMEIMAGES);
% LMdbshowobjects(LMquery(database, 'object.name', 'plate-license'), HOMEIMAGES);
%
% Performs an OR function. This will select objects that belong to one of this groups: 1) side views
% of cars, 2) buildings 3) roads or 4) trees.
% [D,j] = LMquery(database, 'object.name', 'car+side,building,road,tree');
%
% To make AND queries of different objects within an image, you can chain several queries. 
% For instance, to get images that have cars, buildings and roads:
%    [D,j1] = LMquery(database, 'object.name', 'building');
%    [D,j2] = LMquery(database, 'object.name', 'road');
%    j = intersect(j1,j2);
%    LMshow(LMquery(database(j), 'object.name', 'car,building,road'));
%
% You can query other fields. The next lines allow you to select from the
% database, all the polygons that have been verified and that are not
% marked as deleted. This is something you might want to do often:
%    database = LMquery(database, 'object.verified', '1');
%    database = LMquery(database, 'object.deleted', '0');
%
% or database = LMquery(LMquery(database, 'object.verified', '1'), 'object.deleted', '0');
%
% You can also query based on the date of annotation:
%    LMshow(LMquery(database, 'date', '13-Jan'));
% [in the case of dates, there is an exception about the meaning of the
% character '-'. Here is just a separation between day and month].
%
% More examples:
% Queries for objects
% [D,j] = LMquery(database, 'object.name', 'building');
% LMdbshowscenes(database(j), HOMEIMAGES); % this shows all the objects in the images that contain buildings
% LMdbshowscenes(D, HOMEIMAGES); % this shows only the buildings
%
% Queries for images in specific folders. 
% [D,j] = LMquery(database, 'folder', '05june05_static_indoor');
% LMdbshowscenes(database(j), HOMEIMAGES); % this shows all the objects
%
% The next example shows the annotated objects from images that come from the web:
% [D,j] = LMquery(database, 'folder', 'web');
% LMdbshowscenes(database(j), HOMEIMAGES); % this shows all the objects
%
% look for a specific image file:
% [D,j] = LMquery(database, 'filename', 'p1010843.jpg');
% LMdbshowscenes(database(j), HOMEIMAGES); % this shows all the objects
%
% look for objects annotated by one user:
% [D,j] = LMquery(database, 'object.polygon.username', 'atb');
% LMdbshowscenes(D, HOMEIMAGES); % this shows all the objects annotated by one user
%
% look for objects by viewpoint:
% [D,j] = LMquery(database, 'object.viewpoint.azimuth', '0', 'exact');
%

if (nargin < 4)
    method = '';
end

% Parse query
if length(strfind(fieldName, 'date'))>0
    query{1} = {['+' lower(content)]};
else
    query = parseContent(content);
end

% Parse queried field
fieldName = ['annotation.' fieldName];
fieldName = parseContent(fieldName, '.');

% Locate the images that verify the query
Nimages = length(database);
queriedImages = logical(zeros(Nimages,1));

for i = 1:Nimages
    v = database(i);
    
    vn = queryfields(v, fieldName, query, method);

    if length(vn)>0
        queriedImages(i)=1;
        database(i) = vn;
    end
end
database = database(queriedImages);
j = find(queriedImages);


function [vn, jc] = queryfields(v, fieldName, query, method);

vn = [];
jc = [];
depthfield = length(fieldName);

if depthfield == 1
    % End recursion
    if isfield(v, fieldName{1}{1}(2:end))
        jc = findobject({v.(fieldName{1}{1}(2:end))}, query, method);
        vn = v(jc);
    end
else
    if isfield(v, fieldName{1}{1}(2:end))
        % Recursive call
        N = length(v);
        q = logical(zeros(N,1));
        for i = 1:N
            vi = getfield(v, {i}, fieldName{1}{1}(2:end));
            vi = queryfields(vi, fieldName(2:end), query, method);
            q(i) = length(vi)>0;
            v(i).(fieldName{1}{1}(2:end)) = vi;
        end
        jc = find(q);
        vn = v(jc);
    end
end


