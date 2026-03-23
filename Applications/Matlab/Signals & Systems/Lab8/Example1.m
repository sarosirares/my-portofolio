%% Step 1. Read image and template
im = imread('peppers.png'); template = imread('onion.png');
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
[max_c, imax] = max(c(:));
[ypeak, xpeak] = ind2sub(size(c), imax(1));

%% Step 3: Find the offset between the images
corr_offset = [(xpeak - size(template,2))
               (ypeak - size(template,1))];
xoffset = corr_offset(1); yoffset = corr_offset(2);

%% Step4: Find the region in the image where the template matches best
xbegin = round(xoffset + 1);
xend = round(xoffset + size(template,2));
ybegin = round(yoffset + 1);
yend = round(yoffset + size(template,1));

%% Step 5: Pad the template image to the size of the image
recovered_template = uint8(zeros(size(im)));
recovered_template(ybegin:yend, xbegin:xend) = template;
figure, imshow(recovered_template)

%% Step 6: Transparently overlay template image on source image
[m, n] = size(im); mask = ones(m, n);
i = find(recovered_template == 0);
mask(i) = .5;
figure, imshow(im), title('Template overlayed on original image')
hold on
h = imshow(recovered_template);
set(h, 'AlphaData', mask);