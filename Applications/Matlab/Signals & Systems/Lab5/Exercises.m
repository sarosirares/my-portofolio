%% Exercise 2
%b)
N = 64;
A = 1;
n = 0:N-1;
xp = @(n)(A*sin(2*pi*n/N));

%c)
x = xp(n) + rand(1, 64);

%d)
phi = autocorrelation(x);
lags = -length(x) : length(x);

figure;
subplot(2,1,1);
stem(n, x);
title('Noisy Signal x[n]');
xlabel('n'); ylabel('Amplitude');

subplot(2,1,2);
stem(n, phi);
title('Autocorrelation \phi_{xx}[n]');
xlabel('Lag n'); ylabel('\phi_{xx}[n]');
