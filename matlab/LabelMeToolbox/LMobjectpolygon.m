function [x,y] = LMobjectpolygon(annotation, name);
% [x,y] = LMobjectpolygon(annotation, name) returns all the polygons that
% belong to object class 'name'. Is it an array Ninstances*Nvertices

jc = LMobjectindex(annotation, name);
Nobjects = length(jc);
if Nobjects == 0
    x = []; y =[];
else
    for n = 1:Nobjects
        [x{n},y{n}] = getLMpolygon(annotation.object(jc(n)).polygon);
    end
end

