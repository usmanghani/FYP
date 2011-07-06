% MATLAB Toolbox for LabelMe Image Database
% Release October 1, 2005
%
% If you use this toolbox, we only ask you to contribute to the database, 
% from time to time, by using the labeling tool.
%
% LabelMe is a WEB-based image annotation tool: 
% http://people.csail.mit.edu/brussell/research/LabelMe/intro.html
% This tool allows researchers to label images and share the annotations with
% the rest of the community.
%
% Bryan Russell, Antonio Torralba, William T. Freeman, 2005.
% -----------------------------------------------------------------
%
% Introduction
%   demo                - contains examples of how to use several functions
%
% LabelMe tools for reading and ploting the annotations of individual files
%   LMread              - reads one image and the corresponding annotation XML file
%   LMplot              - image and polygons visualization
%
% LabelMe Database tools
%   LMdatabase          - loads all the annotations into a big database struct
%   LMquery             - performs a query on the database
%   LMdbshowscenes      - shows thumbnails for the all the images in the database. Combined with query can show images with only certain objects.
%   LMdbshowobjects     - shows crops of the objects in the database.
%   LMobjectnames       - returns a list with the name of all the objects in the database
%   LMobjectindex       - retuns the indices of an object class within the annotation struct
%   LMcountobject       - counts the number of instances of an object class in every image
%
% Image manipulation
%   LMimscale           - scales the image and the corresponding annotation
%   LMimcrop            - crops the image and the corresponding annotation
%   LMimpad             - pads an image with PADVAL and modifies the annotation
%
% Objects, polygons and segmentation
%   LMobjectpolygon     - returns all the polygons for an object class within an image
%   LMobjectmask        - returns the segmentation mask for all object instances of one class within an image
%   LMobjectsinsideimage- removes polygons outside the image boundary
%
% Creation of training and test images and databases
%   LMcookimage         - reformat an image and annotation to fit certain requirements.
%   LMcookdatabase      - create tuned databases (you can control the difficulty, the object size, ...)
%
% Communication with online annotation tool
%   LMphotoalbum        - creates a web page with thumbnails and connected to LabelMe online
%   LMthumbnailsbar     - creates a bar of thumbnails connected to LabelMe online
%
% Install and update images and annotations
%   LMinstall           - installs the database
%   LMupdate            - authomatic update of the annotations for specific files
%   LMprogressiveinstall- will update the local images with only the new images,
%                         and also download all of the annotations
% 
% Translation from/to other formats
%   PAS2LM              - Translates PASCAL format to LabelMe 
%   LM2OpenCV           - will output a query in format usable for OpenCV Haar 
%
% Object detection
%   LMrecallPrecision   - Precision-recall curve 
%
% XML tools (translates the XML files into MATLAB struct arrays):
%   writeXML            - translates a struct array into a XML file. 
%   loadXML             - read XML file
%   drawXML             - shows the image and plots the polygons 
%   xml2struct          - translates a XML string into a matlab struct
%   struct2xml          - translates a matlab struct into a XML string 
%
% Web tools
%   urldir              - like 'dir' but takes as argument a web address
%   LMgetfolderlist     - will return the list of folders from the online database
%
% Utility functions
%   parseparameters
%   colorSegments
%   subplottight        - like 'subplot' but removes spacing between axes
%   parseContent
%   findobject
%   countpolygons
%   getLMpolygon





