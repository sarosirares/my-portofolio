clc
clear
close all

image = imread("text2.png");
template = imcrop(image);

%% Step 1. Read image and template
im = imread('text2.png');
%convert the images to gray scale if needed
if(ndims(im) == 3)
    im = rgb2gray(im);
end
if(ndims(template) == 3)
    template = rgb2gray(template);
end
figure; imshow(im), title('Image'), figure, imshow(template), title('Template')

%% Step 2: Do normalized cross-corelation and find coordinates of peak
c = normxcorr2(template, im);
figure, surf(c), shading flat
threshold = 0.9;
c_thresh = c > threshold;
local_max = imregionalmax(c) & c_thresh;
[ypeak, xpeak] = find(local_max);
peak_values = c(local_max);

%% Step 3: Find the offset between the images
corr_offsets = zeros(length(xpeak), 2);
for i = 1:length(xpeak)
    xoffset = xpeak(i) - size(template, 2);
    yoffset = ypeak(i) - size(template, 1);
    corr_offsets(i, :) = [xoffset, yoffset];
end

%% Step4: Find the region in the image where the template matches best
regions = zeros(size(corr_offsets, 1), 4);  % Each row: [xbegin, xend, ybegin, yend]
for i = 1:size(corr_offsets, 1)
    xoffset = corr_offsets(i, 1);
    yoffset = corr_offsets(i, 2);
    
    xbegin = round(xoffset + 1);
    xend = round(xoffset + size(template, 2));
    ybegin = round(yoffset + 1);
    yend = round(yoffset + size(template, 1));
    
    regions(i, :) = [xbegin, xend, ybegin, yend];
end

%% Step 5: Pad the template image to the size of the image
recovered_template = uint8(zeros(size(im)));  % Create a blank image the same size as the original


for i = 1:size(regions, 1)
    % Get the region bounds for this match
    xbegin = regions(i, 1);
    xend = regions(i, 2);
    ybegin = regions(i, 3);
    yend = regions(i, 4);
    
    % Ensure the region is within the bounds of the image
    xbegin = max(xbegin, 1);
    xend = min(xend, size(im, 2));
    ybegin = max(ybegin, 1);
    yend = min(yend, size(im, 1));
    
    % Place the template in the recovered template at the matching position
    recovered_template(ybegin:yend, xbegin:xend) = template(1:(yend-ybegin+1), 1:(xend-xbegin+1));
end

% Display the recovered template with all matches
figure, imshow(recovered_template);

%% Step 6: Transparently overlay template image on source image
[m, n] = size(im); mask = ones(m, n);
i = find(recovered_template == 0);
mask(i) = .5;
figure, imshow(im), title('Template overlayed on original image')
hold on
h = imshow(recovered_template);
set(h, 'AlphaData', mask);


%% b)
clc
im_logical = im > 0;
template_logical = template > 0;
figure, imshow(im_logical), figure, imshow(template_logical)

% compute the correlation using FFT
C = real(ifft2(fft2(im_logical) .* fft2(rot90(template_logical,2),674,1226)));
figure, imshow(C,[]);

% display the positions where the template matches the image
thresh = max(C(:))*90/100;
D = (C > thresh);
% extend the regions for better visualization
se = strel('disk', 5); E = imdilate(D,se);
figure, imshow(E)