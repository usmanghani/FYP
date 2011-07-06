% VIPDH_PATTERN Model helper script for the VIP pattern matching demo.  
%   This script is run in the model workspace initialization function
%   which can be accessed using the model explorer.

% Copyright 2004 The MathWorks, Inc.

% load and initialize the data required by vippattern demo

target_img = rgb2gray(imread('things2_target.jpg'));
cat_info = aviinfo('things2.avi');

% get path to the model
model_path = [get(bdroot(gcbh),'Path'), '/Pyramiding factor'];

% create a pyramiding factor variable and initialize it;
% this variable is also modified in the model by the block
% called:  Pyramiding factor

% Set the pyramiding factor by grabbing it from the masked block 
% called 'Pyramiding factor'
pyramiding_factor = 1/str2double(get_param(model_path,'pfactor'));

% NOTE: target_img was obtained by using imcrop on one of the video frames

% resize the target template in order to speed up the processing;
% the video will be resized on the fly in order to match the size of
% the target; this process is sometimes called pyramiding
target_img_pyramid = imresize(target_img, pyramiding_factor);

target_dim_nopyramid = size(target_img);
target_dim = size(target_img_pyramid);
iut_dim = round([cat_info.Height cat_info.Width] * pyramiding_factor);

% figure out the sizes after padding; padding is necessary in order
% to avoid circular convolution
target_pad_rows = 2^nextpow2(iut_dim(1)+target_dim(1)+1);
target_pad_cols = 2^nextpow2(iut_dim(2)+target_dim(2)+1);

% precompute the FFT of the target; rotate the target to achive
% correlation instead of convolution
target_fft = fftn(single(rot90(target_img_pyramid,2)),...
    [target_pad_rows target_pad_cols]);

% precompute the sum of pixel values squared for later usage
% in normalizing the cross-correlation
target_sq_sum = single(target_img_pyramid).^2;
target_sq_sum = sqrt(sum(target_sq_sum(:)));
