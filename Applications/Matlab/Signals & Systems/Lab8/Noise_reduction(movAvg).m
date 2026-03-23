% audio signal generation
Fs = 44100;
f_do = 261.6;
f_re = 293.6;
f_mi = 329.6;
t = 0:1/Fs:0.5-1/Fs;
do = sin(2*pi*f_do*t);
re = sin(2*pi*f_re*t);
mi = sin(2*pi*f_mi*t);
silence = zeros(size(t));

t = 0:1/Fs:2.5-1/Fs;
s = [do, re, mi, silence, do];
figure, plot(t,s)
sound(s,Fs)
pause(3)

% noise addition
z = 0.1*(2*rand(size(t))-1);
sz = s + z;
sound(sz,Fs)
pause(3)

M = 50;
h = 1/M*ones(1,M);
sf = conv(h,sz);
sound(sf,Fs)