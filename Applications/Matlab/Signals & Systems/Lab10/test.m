clc
clear
close all

t = 0:0.00000001:0.1;

x = -8*sin(50*pi*t);
y = 0.5*sin(250*pi*t);
z = x+y;

figure,
subplot(3,1,1), plot(t, x);
subplot(3,1,2), plot(t, y);
subplot(3,1,3), plot(t, z);