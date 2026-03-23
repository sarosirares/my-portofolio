clc
clear
close all

bw = imread('text.png'); %read the image
a = bw(32:45,88:98); % create the template by cropping a region form the image
figure, imshow(bw), figure, imshow(a)

% compute the correlation using FFT
C = real(ifft2(fft2(bw) .* fft2(rot90(a,2),256,256)));
figure, imshow(C,[])

% display the positions where the template matches the image
thresh = max(C(:))*90/100;
D = (C > thresh);
% extend the regions for better visualization
se = strel('disk', 5); E = imdilate(D,se);
figure, imshow(E)