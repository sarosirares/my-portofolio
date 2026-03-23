%% ex1

clc
close all
clear

x = @(n)((n>=0)-(n>=2));
y = @(n)(0.2.^n.*(n>=0));
sx = 0; ex = 1; dtx = sx:ex;
sy = 0; ey = 10; dty = sy:ey;
w = conv(x(dtx),y(dty));
dtw = sx+sy:ex+ey;

w2 = @(n)(0.2.^n.*((n>=0) + 5*(n>=1)));

figure
subplot(3,1,1), stem(dtx,x(dtx))
subplot(3,1,2), stem(dty,y(dty))
subplot(3,1,3), stem(dtw,w)

figure, stem(dtw, w2(dtw))


%% ex2
clc
clear

n = -5:5;

sx = 0; ex = 3; dtx = sx:ex;
sh = -1; eh = 1; dth = sh:eh;
dty = sx+sh:ex+eh;

x = @(dtx)((dtx==0) + 2*(dtx==1) - (dtx==3));
h = @(dth)(2*(dth==-1) + 2*(dth==1));

sx = -1; ex = 2; dtx2 = sx:ex;
sh = -3; eh = -1; dth2 = sh:eh;
x_plus1 = x(dtx2+1);
h_plus2 = h(dth2+2);

y1 = conv(x(dtx),h(dth));
y2 = conv(x_plus1,h(dth));
y3 = conv(x(dtx),h_plus2);

dty2 = -2:3;
dty3 = -3:2;

figure
subplot(2,1,1), stem(n,x(n)), ylabel('x[n]')
subplot(2,1,2), stem(n,h(n)), ylabel('h[n]')
figure
subplot(2,1,1), stem(dtx2,x_plus1), ylabel('x[n+1]')
subplot(2,1,2), stem(dth2,h_plus2), ylabel('h[n+2]')
figure
subplot(3,1,1), stem(dty,y1(1:length(dty))), ylabel('y1[n]')
subplot(3,1,2), stem(dty2,y2(1:length(dty))), ylabel('y2[n]')
subplot(3,1,3), stem(dty3,y3(1:length(dty))), ylabel('y3[n]')

%% ex3

clc
a = 0.5;
N = 50;
n = 0:N-1;

x = ((n==0) - a*(n==1));
h1 = (a.^n.*(n>=0));
h2 = (sin(8*n));

h = conv(h1,h2);
y = conv(x,h);

nh = 0:length(h)-1;
ny = 0:length(y)-1;

figure;

subplot(4,1,1);
stem(n, h1, 'filled');
title('h_1[n] = \alpha^n u[n]');
xlabel('n'); ylabel('h_1[n]');

subplot(4,1,2);
stem(n, h2, 'filled');
title('h_2[n] = sin(8n)');
xlabel('n'); ylabel('h_2[n]');

subplot(4,1,3);
stem(n, x, 'filled');
title('x[n] = \delta[n] - \alpha \delta[n-1]');
xlabel('n'); ylabel('x[n]');

subplot(4,1,4);
stem(ny, y, 'filled');
title('y[n] = x[n] * (h_1[n] * h_2[n])');
xlabel('n'); ylabel('y[n]');