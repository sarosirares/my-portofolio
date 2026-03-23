clc
clear
close all

img = imread('peppers.png');
if (ndims(img) == 3)
    img = rgb2gray(img);
end
F = fftshift(fft2(double(img)));
figure; imshow(img);
figure; imshow(log(abs(F)),[]); title('Magnitude')
figure; imshow(angle(F)); title('Phase')
filtertype = 'LPF'; %BLPF, GLPF, HPF, BHPF, GHPF
D0 = 27;
n = 1; % order for Butterworth filter
[M, N] = size(img);
H = imfreqfilter(filtertype, M, N, D0, n);
figure; surf(H), title(filtertype);
G = H.*F;
figure; imshow(log(abs(G)),[]); title('Filtered Magnitude')
figure; imshow(angle(G),[]); title('Filtered Phase')
imgf = real(ifft2(ifftshift(double(G))));
figure, imshow(imgf, []); title('Filtered Image');