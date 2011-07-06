function jc = LMobjectindex(annotation, name);
% jc = LMobjectindex(annotation, name) 
% Finds an object class in the annotation struct and returns the indices
%
% D = LMquery(database, 'name', 'car');
% jc = LMobjectindex(D(1).annotation, 'car');
%
% This will return the indices of the object class 'car' in the first
% image returned by the query.

jc = [];
if isfield(annotation, 'object')
    query = parseContent(name);
    jc = findobject({annotation.object.name}, query); % find object index
end

