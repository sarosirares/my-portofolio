%% Ex1 a) b)
clc
clear
close all

A = [0 16 32 48;
    16 0 16 32;
    32 16 0 16;
    48 32 16 0];

h = 1/9*ones(3);

Af = imfilter(A, h,"circular","conv")

figure,
imagesc(A), colormap("gray")
figure,
imagesc(Af), colormap("gray")

%% c)

convolution2D(A,h)

%% Ex2

clc
image = imread('peppers.png');
imagesc(image)

% Blur Gaussian filter
h1 = 1/256*[1 4 6 4 1; 4 16 24 16 4; 6 24 36 24 6; 4 16 24 16 4; 1 4 6 4 1];

figure
image1 = imfilter(image, h1,"circular","conv");
imagesc(image1)

% Motion blur
h2 = zeros(9,9);
for i = 1:length(h)
    for j = 1:length(h)
        if(i==j)
            h2(i,j) = 1;
        end
    end
end

figure
image2 = imfilter(image,h2,"circular","conv");
imagesc(image2)

% sharpening
h3 = [-1 -1 -1; -1 9 -1; -1 -1 -1];
figure
image3 = imfilter(image,h3,"circular","conv");
imagesc(image3)

% Laplacian edge and line detectors
h4 = [-1 -1 -1; -1 8 -1; -1 -1 -1];
figure
image4 = imfilter(image,h4,"circular","conv");
imagesc(image4)

h5 = [-1 -1 -1; 2 2 2; -1 -1 -1];
figure
image5 = imfilter(image,h5,"circular","conv");
imagesc(image5)

h6 = [-1 2 -1; -1 2 -1; -1 2 -1];
figure
image6 = imfilter(image,h6,"circular","conv");
imagesc(image6)

h7 = [-1 -1 2; -1 2 -1; 2 -1 -1];
figure
image7 = imfilter(image,h7,"circular","conv");
imagesc(image7)

h8 = [2 -1 -1; -1 2 -1; -1 -1 2];
figure
image8 = imfilter(image,h8,"circular","conv");
imagesc(image8)

% Sobel edge detector
h9 = [1 2 1; 0 0 0; -1 2 -1];
figure
image9 = imfilter(image,h9,"circular","conv");
imagesc(image9)

h10 = [1 0 -1; 2 0 -2; 1 0 -1];
figure
image10 = imfilter(image,h10,"circular","conv");
imagesc(image10)

% Prewitt edge detector
h11 = [1 1 1; 0 0 0; -1 -1 -1];
figure
image11 = imfilter(image,h11,"circular","conv");
imagesc(image11)

h12 = [-1 0 -1; 1 0 -1; 1 0 -1];
figure
image12 = imfilter(image,h12,"circular","conv");
imagesc(image12)

% c)

imagenoise = imnoise(image,"salt & pepper");

imwrite(imagenoise,"photo1_noise.jpg");

h13 = 1/9*[1 1 1; 1 1 1; 1 1 1];
filtered = imfilter(imagenoise,h13, "circular", "conv");
figure, imagesc(filtered)

h25 = 1/25 * ones(5,5);
filtered = imfilter(imagenoise,h25, "circular", "conv");
figure, imagesc(filtered)
