%% test 1 
clc
clear


%a
Ts=0.01;
T0=2*pi;
t=0:Ts:T0+Ts;
w0=2*pi/T0;
h=(pi-t)/2.*(t>0 & t<2*pi);
N=10;

ak=[];
for k=-N:N
    ak=[ak, (1/T0)*trapz(t, h.*exp(-j*k*w0*t))];
end
a0=real(ak(N+1))
Bk = real(ak(N+2:2*N+1));
Ck = imag(ak(N+2:2*N+1));

n=1:N;
figure; 
subplot(2,1,1); 
stem(n, Bk); 
title('Bk coefficients');
xlabel('n'); ylabel('B_n');
subplot(2,1,2);
stem(n, Ck);
title('Ck coefficients');
xlabel('n'); ylabel('C_n');

%b
s=a0*ones(size(t));
for n=1:N
    s=s+2*(Bk(n)*cos(n*t)-Ck(n)*sin(n*t));
end

figure
plot(t,h,'b')
hold on
plot(t,s,'--r')
grid
xlim([0,2*pi+Ts])

S_avg = zeros(size(t));
for m = 0:9
    S_m = a0 * ones(size(t));
    for idx = 1:m
        S_m = S_m + 2 * (Bk(idx) * cos(idx * t) - Ck(idx) * sin(idx * t));
    end
    S_avg = S_avg + S_m;
end
S_avg = S_avg / 10;

plot(t,S_avg,'g')
legend('Original signal', 'Reconsrtucted signal','Average')