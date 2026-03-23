clc
clear
close all

Hf = tf([2],[5 1 0]);

pc_zc = 1.035;
DsigmaC = pc_zc - 1;

sigmaTot = 0.1;
sigma2 = 0.1 - DsigmaC;

zeta = (abs(log(sigma2)))/sqrt((log(sigma2))^2+3.14^2);
ts = 5.5;
wn = 4/ts/zeta;

dwB = wn*sqrt(1-2*zeta^2+sqrt(2-4*zeta^2+4*zeta^4))

cv2 = wn/2/zeta

pc = DsigmaC/(2*zeta/wn - 1/1.52)
zc = pc/(1 + DsigmaC)

Ho2 = tf(wn^2, [1 2*zeta*wn wn^2])
Hoct = pc/zc * tf([1 zc], [1 pc])
Hoc = Ho2 * Hoct;

HR = minreal(Hoc/(Hf*(1-Hoc)))

figure,
step(feedback(HR*Hf,1))

t = 0:0.1:100;

y = lsim(feedback(HR*Hf,1), t, t);

cv = abs(1/(y(end) - t(end)))