clc
close all

k = 1:150;
u = 1*(k==20);
% y = DCMRun.run(u, 'port', 'COM5', 'Ts', 1e-3, 'type', 'windows');
figure, plot(y);
h = y(24:end);
a = 300;
b = 0.2;
x = a*exp(-b*k);
figure, plot(h), hold on
plot(x, 'r--')
