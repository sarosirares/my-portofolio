%% 1

clc
close all
clear

x1 = @(t)((t>=0)&(t<2))
y1 = @(t)(t.*((t>=0)&(t<=1)) + (2-t).*((t>1)&(t<=2)))
t = -3:0.001:4;
figure, subplot(211), plot(t,x1(t)), legend('x1(t)'), subplot(212), plot(t,y1(t)), legend('y1(t)')

x2 = x1(t) + x1(t+1);
y2 = y1(t) + y1(t+1);

figure, subplot(211), plot(t,x2), legend('x2(t)'), subplot(212), plot(t,y2), legend('y2(t)')

x3 = x1(t+2) + x1(t-2);
y3 = y1(t+2) + y1(t-2);

figure, subplot(211), plot(t,x3), legend('x3(t)'), subplot(212), plot(t,y3), legend('y3(t)')

x4 = x1(t+4) + x1(t) + x1(t-2);
y4 = y1(t+4) + y1(t) + y1(t-2);

figure, subplot(211), plot(t,x4), legend('x4(t)'), subplot(212), plot(t,y4), legend('y4(t)')

x5 = x1(t+4) + x1(t+2) + x1(t-2);
y5 = y1(t+4) + y1(t+2) + y1(t-2);

figure, subplot(211), plot(t,x5), legend('x5(t)'), subplot(212), plot(t,y5), legend('y5(t)')

%% 2

clc
close all
clear

n = -8:8;
u = @(t)(t>=0);
x = @(u,n)(u(n) - u(n-3));

y1 = x(u,n);
y2 = x(u,n)*2.*n;
y3 = x(u,n)*(-2);

figure,
subplot(3,1,1), stem(n, y1), title('y1[n]');
subplot(3,1,2), stem(n, y2), title('y2[n]');
subplot(3,1,3), stem(n, y3), title('y3[n]');

%% 3

n = -2:2;

x = @(n)4*(n==0);
y = x(n) + 1/4*x(n-1);

stem(n,y);

%% 4

clc
close all
t = -4:0.001:4;

u = @(t)(t>=0);
x1 = @(u,t)u(t);
y1 = @(t)(1-exp(-2.*t)).*x1(u,t);

x2 = 4*x1(u,t) - 4*x1(u,t-1);
y2 = 4*y1(t) - 4*y1(t-1);

figure, subplot(211), plot(t,x1(u,t)), legend('x1(t)'), subplot(212), plot(t,y1(t)), legend('y1(t)')
figure, subplot(211), plot(t,x2), legend('x2(t)'), subplot(212), plot(t,y2), legend('y2(t)')