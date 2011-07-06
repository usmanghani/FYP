function n = countpolygons(D)
% returns the number of polygons in the database struct
%    n = countpolygons(D)

M = length(D);
n = 0;
for m = 1:M
    if isfield(D(m).annotation, 'object')
        n = n + length(D(m).annotation.object);
    end
end

