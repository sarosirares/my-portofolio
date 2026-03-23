clc
clear

f = 1e3;
n = 15;
nT = 2;

Ts = 1/(f*n);
w = 2*pi*f;
N = n*nT;

y = zeros(1, N);
y(1) = 0;
y(2) = sin(w*Ts);

for k = 3:N
    y(k) = 2*cos(w*Ts)*y(k-1)-y(k-2);
end

t = 0:(n*nT-1);

stem(t*f*Ts, y);

%% Using the function
close all

figure,
sin_discret(1e3, 15, 2);

figure,
sin_discret(42, 8, 5);
