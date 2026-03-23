clc
clear
close all

Hf = tf([2],[2 1 0]);

%% a)
clc
close all

sigma = 0.1;
ts = 20;

zeta = (abs(log(sigma)))/sqrt((log(sigma))^2+3.14^2);
wn = 4/ts/zeta;
cv = wn/2/zeta
dwB = wn*sqrt(1-2*zeta^2+sqrt(2-4*zeta^2+4*zeta^4))

Ho = tf([wn^2], [1 2*zeta*wn wn^2])
HR = minreal(Ho/(Hf*(1-Ho)))

step(feedback(HR*Hf,1))

%% b)
clc
close all

sigma = 0.04;
ts = 3;

zeta = (abs(log(sigma)))/sqrt((log(sigma))^2+3.14^2);
wn = 4/ts/zeta;
cv = wn/2/zeta
dwB = wn*sqrt(1-2*zeta^2+sqrt(2-4*zeta^2+4*zeta^4))

Ho = tf([wn^2], [1 2*zeta*wn wn^2])
HR = minreal(Ho/(Hf*(1-Ho)))

step(feedback(HR*Hf,1))

%% c)
clc
close all

sigma = 0.07;
ts = 3;

zeta = (abs(log(sigma)))/sqrt((log(sigma))^2+3.14^2);
wn = 4/ts/zeta;
cv = wn/2/zeta
dwB = wn*sqrt(1-2*zeta^2+sqrt(2-4*zeta^2+4*zeta^4))

% Ho = tf([wn^2], [1 2*zeta*wn wn^2])
% HR = minreal(Ho/(Hf*(1-Ho)))
% 
% step(feedback(HR*Hf,1))