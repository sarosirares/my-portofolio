%% f)
close all
H = tf([1 9], [-1 5]);
nyquist(H)

%%
close all

k = 0.9; nyquist(k*H)

Ho = feedback(k*H, 1);
step(Ho)

%%
close all

k = 1.5; nyquist(k*H)

Ho = feedback(k*H, 1);
step(Ho)

%% a)

k = 0.4; Hol = k*tf(10, [1 3], 'IOdelay', 1)

nyquist(Hol)