function [names, counts] = LMobjectnames(database, options);
% Returns the name of all the object classes in the database, 
% and the number of instances of each object class:
%
% [names, counts] = LMobjectnames(database);
%
% You can visualize the counts and object names by calling the function
% with an additional parameter:
%
% LMobjectnames(database, 'plot');
%
% You can see the list of words associated with an object class using the
% command LMobjectnames. Some examples:
%   LMobjectnames(LMquery(database, 'name', 'face'))
%   LMobjectnames(LMquery(database, 'name', 'plate'))
%   LMobjectnames(LMquery(database, 'name', 'person'))


Nannotations = length(database); 
names = {};
for i = 1:Nannotations
    if isfield(database(i).annotation, 'object')
        names = [names {database(i).annotation.object(:).name}];
    end
end

[names, i, j] = unique(strtrim(lower(names)));

if nargout == 2 | nargin == 2
    Nobject = length(names);
    [counts, x] = hist(j, 1:Nobject);
end


if nargin == 2
    % plot counts
    figure
    barh(counts)
    set(gca, 'YTick', 1:Nobject)
    set(gca, 'YtickLabel', names)
    axis([0 max(counts)+5 0 Nobject+1])
    grid on
end
