function ak = fsAnalysis(x, t, T0, Ts, N)
%function for estimating the first N coefficients of the Fourier series for
%signal x

%T0 - fundamental period of x; Ts- sampling period

%extraction of one period from x

t = t(1:floor(T0/Ts));
x = x(1:length(t));

%estimation of the coefficients using the trapezoidal method

w0 = 2*pi/T0;
ak = [];
for k = -N:N
    ak = [ak, (1/T0)*trapz(t, x.*exp(-1i*k*w0*t))];
end