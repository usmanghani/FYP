function [h, class] = LMplot(varargin)
% Visualizes the polygons in an image.
%
% LMplot(annotation, img)
% or
% LMplot(database, ndx, HOMEIMAGES)
%
% Example:
%   [annotation, img] = LMread(filename, HOMEIMAGES)
%   LMplot(annotation, img)
%
%   thumbnail = size of the image 
%   The plot uses only 7 colors, therefore, some times, different object.
%   Classes might have the same color assigned.
% 
% If an object has the field 'confidence', the thickness of the bounding
% box will be equal to the confidence.

switch length(varargin)
    case 1
        error('Not enough input arguments.')
    case 2
        annotation = varargin{1};
        img = varargin{2};
    case 3
        D = varargin{1};
        ndx = varargin{2};
        HOMEIMAGES = varargin{3};

        annotation = D(ndx).annotation;
        img = imread(fullfile(HOMEIMAGES, annotation.folder, annotation.filename));
    otherwise
        error('Too many input arguments.')
end

% Define colors
colors = 'rgbcmyw';

% Draw image
%figure;
image(img); axis('off'); axis('equal'); hold on
% Draw each object (only non deleted ones)
h = []; class = [];
if isfield(annotation, 'object')
    Nobjects = length(annotation.object); n=0;
    for i = 1:Nobjects
        n = n+1;
        class{n} = annotation.object(i).name; % get object name
        [X,Y] = getLMpolygon(annotation.object(i).polygon);

        if isfield(annotation.object(i), 'confidence')
            LineWidth = round(annotation.object(i).confidence)
            LineWidth = min(max([2 LineWidth]), 8);
        else
            LineWidth = 4;
        end
        
        plot([X; X(1)],[Y; Y(1)], 'LineWidth', LineWidth, 'color', [0 0 0]); hold on
        h(n) = plot([X; X(1)],[Y; Y(1)], 'LineWidth', LineWidth/2, 'color', colors(mod(sum(double(class{n})),7)+1));
        hold on
    end

    if nargout == 0
        legend(h, class);
    end
    %drawnow
end


