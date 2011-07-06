function LMdbshowscenes(database, HOMEIMAGES, subimages)
%
% Shows all the images in the database with annotation.
% This function can be used in combination with LMquery
%
% LMshow(database, HOMEIMAGES)

if nargin == 1
    HOMEIMAGES = 'C:\atb\Databases\CSAILobjectsAndScenes\Images'; % you can set here your default folder
end

Nimages = length(database);
if nargin == 3
    Nx = subimages(2);
    Ny = subimages(1);
else
    Nx = 6; Ny = 5; % will show 6x5 images per figure
end
Dx = 1/Nx; Dy = 1/Ny; 
i = 0;
while i<Nimages
    figure
    for y = Ny-1:-1:0
        for x = 0:Nx-1
            i = i+1;
            if i>Nimages
                return
            end

            axes('position', [x*Dx y*Dy Dx Dy]); % create axis
            
            img = LMimread(database, i, HOMEIMAGES); % Load image
            scaling = 320/size(img,1); % scale factor to create thumbnail
            [annotation, img] = LMimscale(database(i).annotation, img, scaling); % scale imahe
            [h,class] = LMplot(annotation, img); % show image and polygons
            drawnow
        end
    end
end


