clc
clear
close all

kf = 3.5;
Tf = 0.5;
Hf = tf(kf, [Tf, 1, 0]);

%% a)
clc
close all

bodemag(Hf), hold on

wf = 1/Tf;
sigma = 0.1;
zeta = (abs(log(sigma)))/sqrt((log(sigma))^2+pi^2);

A = 1/4/sqrt(2)/zeta^2;
AdB = 20*log10(A);
A = tf(A, 1);
bodemag(A)

FdB = 1.85;
FN = abs(AdB) + abs(FdB);
Vr = 10^(-FN/20);
Hd = Vr*Hf;

bodemag(Hd)

wc = 1.23;
wn = 2*zeta*wc;
ts = 4/wn/zeta;

% dwB = wc;
% cvdB = 3.1; %read from 10^-1 and substract 20
% cv = 10^(cvdB/20);

tsstar = 3;
wc2 = wc * ts/tsstar;
VrPD = wc2/wc;
taud = Tf;
TN = taud * tsstar/ts;

HPD = VrPD * tf([taud 1], [TN 1]);
HdPD = Vr * HPD * Hf;

bodemag(HdPD)

Ho = minreal(HdPD/(1+HdPD));

figure,
step(Ho)

t = 0:0.1:50;

figure,
lsim(Ho, t, t)
y = lsim(Ho, t, t);
cv_ramp = 1/(t(end)-y(end));

% to check the closed loop bandwidth
figure,
bode(Ho)

%% b)

clc
close all

bodemag(Hf), hold on

wf = 1/Tf;
sigma = 0.1;
zeta = (abs(log(sigma)))/sqrt((log(sigma))^2+pi^2);

A = 1/4/sqrt(2)/zeta^2;
AdB = 20*log10(A);
A = tf(A, 1);
bodemag(A)

FdB = 1.85;
FN = abs(AdB) + abs(FdB);
Vr = 10^(-FN/20);
Hd = Vr*Hf;

bodemag(Hd)

wc = 1.23;
wn = 2*zeta*wc;
ts = 4/wn/zeta;

tsstar = 1;
wc2 = wc * ts/tsstar;
VrPD = ts/tsstar;
taud = Tf;
TN = taud * tsstar/ts;

HPD = VrPD * tf([taud 1], [TN 1]);
HdPD = Vr * HPD * Hf;

bodemag(HdPD)

dwB = wc;
cvdB = 16.5; %read from 10^-1 and substract 20
cv = 10^(cvdB/20);

cvstar = 6.1;

wz = 0.1*wc2;
wp = cv/cvstar * wz;

Tz = 1/wz;
Tp = 1/wp;

VrPI = cvstar/cv;

VR = Vr * VrPD * VrPI;
HPID = VR * tf(conv([Tz 1], [taud 1]), conv([Tp 1], [TN 1]));

HdPID = HPID * Hf;

bodemag(HdPID);

Ho = minreal(HdPID/(1+HdPID));

figure,
step(Ho)

t = 0:0.1:50;

figure,
lsim(Ho, t, t)
y = lsim(Ho, t, t);
cv_ramp = 1/(t(end)-y(end));

% to check the closed loop bandwidth
figure,
bode(Ho)