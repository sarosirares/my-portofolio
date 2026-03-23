a0 = ak(N+1); %contains the Fourier coefficients ordered like: `[-N, ..., 0, ..., +N]`
ksi0 = 0;
Ak = abs(ak(N+2:end));
ksi = angle(ak(N+2:end));

% signal synthesis
x_est = a0*ones(size(t));
for k = 1:N
    x_est = x_est + 2*Ak(k)*cos(w0*k*t+ksi(k));
end
figure; plot(t, x, 'b', t, x_est, 'r')
xlabel('t'); legend('x(t)', 'x_{est}(t)');

%plot of amplitude, phase and power specturm
n0 = 0:N;
figure, subplot(3, 1, 1); stem(n0, [a0, Ak], '.')
legend('Amplitude spectrum')

subplot(3, 1, 2), stem(n0, [ksi0, ksi], '.g')
legend('Phase spectrum')

subplot(3, 1, 3), stem(n0, [a0^2, (Ak.^2)/2], '.r')
legend('Power spectrum')