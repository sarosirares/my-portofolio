%% ex1
clc
clear
close all

im = imread('ex1.png');
imshow(im);

if(~islogical(im))
    if(ndims(im)>2)
        im = rgb2gray(im);
    end
    level = graythresh(im);
    BW = im2bw(im, level);
else
    BW = im;
end

figure, imshow(BW)

[B, L, N] = bwboundaries(BW, 'noholes');

for (k=1:N)
    X = B{k}(:,2);
    Y = B{k}(:,1);
    contur = [X'; Y'];
    ellipticFourierDescriptors(contur, 20);
    axis ij
end

%% ex2

im2 = imread('ex2.png');
imshow(im2)

if(~islogical(im2))
    if(ndims(im2)>2)
        im = rgb2gray(im2);
    end
    level = graythresh(im2);
    BW = im2bw(im2, level);
else
    BW = im2;
end

figure, imshow(BW)

[B, L, N] = bwboundaries(BW, 'noholes');

stats = regionprops(L, 'Centroid');
coordinates = stats(1).Centroid;
xc = coordinates(1);
yc = coordinates(2);

for (k=1:N)
    X = B{k}(:,2);
    Y = B{k}(:,1);
    contur = [X'; Y'];
end

r = sqrt((X - xc).^2 + (Y - yc).^2);

figure;
plot(r);
xlabel('Boundary point index j');
ylabel('Distance r(j)');
title('Distance from boundary points to center of mass');
grid on;

figure,
imshow(label2rgb(L)); hold on;

% Draw lines to a few boundary points
for k = 1:20:length(X)
    plot([xc, X(k)], [yc, Y(k)], 'b-');
end
title('Center of mass and boundary distances');

%f
% % Normalize to remove scale
% r1 = r1 / mean(r1);
% r2 = r2 / mean(r2);
% 
% % Resample to same length
% N = 200;
% r1i = interp1(1:length(r1), r1, linspace(1, length(r1), N));
% r2i = interp1(1:length(r2), r2, linspace(1, length(r2), N));

%% ex3

ax = [-44.2, 0.6, 0.7, -0.4, -4.8, -0.01, -3.7];
bx = [1.2, 0.1, -0.03, -0.3, 0.5, 0.1, 0.9];
ay = [-1.2, -0.1, 0.1, 0.2, 0.6, -0.3, -0.6];
by = [-43.8, 0.8, 0.1, 0.4, 3.7, -0.6, -3.6];
ax0 = 141.6; ay0 = 121.3

m = 327;
T = m;        % period is the number of boundary points
w = 2*pi/T;   % fundamental angular frequency
nc = length(ax);

% boundary reconstruction based on the Fourier series coefficients
for n=1:m
    X2(n) = ax0/2;
    Y2(n) = ay0/2; 
    for k=1:nc
        X2(n) = X2(n) + ax(k)*cos(k*w*n) + bx(k)*sin(k*w*n);
        Y2(n) = Y2(n) + ay(k)*cos(k*w*n) + by(k)*sin(k*w*n);
    end
end
c2 =[X2; Y2];
plot(c2(1,:),c2(2,:)); hold on; plot(ax0/2, ay0/2, '*');