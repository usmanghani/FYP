function counts = LMcountobject(D, objectname);
% Returns the number of object instances of the class 'objectname' for each
% entry in the database.
%
% Example: to know how many side views of cars there are in every image:
% counts = LMcountobject(D, 'car+side');
%

n = length(D);
counts = zeros(n,1);

[D, j] = LMquery(D, 'object.name', objectname);
for i = 1:length(D);
    counts(j(i)) = length(D(i).annotation.object);
end

