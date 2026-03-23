%% ex1

clc
clear
close all

% a)
img = imread('peppers.png');

% b)
sfilter = fspecial("sobel");

% c)
sfilter_t = sfilter';

% d)
[H1_raw, fx1, fy1] = freqz2(sfilter);
[H2_raw, fx2, fy2] = freqz2(sfilter_t);

% e)
if (ndims(img) == 3)
    img = rgb2gray(img);
end
F = fftshift(fft2(double(img)));

% f)
imgSize = size(img);
H1 = imresize(H1_raw, imgSize, 'bilinear');
H2 = imresize(H2_raw, imgSize, 'bilinear');
G1 = H1.*F;
G2 = H2.*F;

% g)
imgf1 = real(ifft2(ifftshift(double(G1))));
imgf2 = real(ifft2(ifftshift(double(G2))));

% h)
S = sqrt(imgf1.^2 + imgf2.^2);
% S = imgf1+imgf2;

% i)
figure, imshow(S, []); title('Filtered Image');

%% ex2

% a)
saturn = imread('saturn.png');
cameraman = imread('cameraman.tif');

% b)
if (ndims(saturn) == 3)
    saturn = rgb2gray(saturn);
end
if (ndims(cameraman) == 3)
    cameraman = rgb2gray(cameraman);
end

% c)
saturn = imresize(saturn, size(cameraman), 'bilinear');

% d)
F_sat = fftshift(fft2(double(saturn)));
F_cam = fftshift(fft2(double(cameraman)));

% e)
figure; imshow(log(abs(F_sat)),[]); title('Magnitude Saturn')
figure; imshow(angle(F_sat),[]); title('Phase Saturn')

figure; imshow(log(abs(F_cam)),[]); title('Magnitude Cameraman')
figure; imshow(angle(F_cam),[]); title('Phase Cameraman')

% f)
mag_sat = abs(F_sat);
phase_sat = angle(F_sat);

mag_cam = abs(F_cam);
phase_cam = angle(F_cam);

F1 = mag_sat .* exp(1i * phase_cam);
F2 = mag_cam .* exp(1i * phase_sat);

% g)
img_f1 = real(ifft2(ifftshift(double(F1))));
img_f2 = real(ifft2(ifftshift(double(F2))));

% h)
figure, imshow(img_f1, []); title('Filtered Image Saturn');
figure, imshow(img_f2, []); title('Filtered Image Cameraman');

