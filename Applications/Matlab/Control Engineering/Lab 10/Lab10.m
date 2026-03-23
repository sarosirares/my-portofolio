clc
clear
close all

%% a)

% Magnitude criterion
clc

Hf1 = tf(2, [1 1]);

Tsigma = 1;

Hdstar = tf(1, [2*Tsigma^2, 2*Tsigma 0]);

Hc1 = minreal(Hdstar/Hf1);

Ho1 = feedback(Hc1*Hf1, 1);
figure,
step(Ho1)

t = 0:0.1:20;
y1 = lsim(Ho1, t, t);
cv1 = 1/abs((y1(end)-t(end)));

% Symmetrical criterion

HdstarS = tf([4*Tsigma 1], [8*Tsigma^3 8*Tsigma^2 0 0]);

HcS1 = minreal(HdstarS/Hf1);

HoS1 = feedback(HcS1*Hf1, 1);
figure,
step(HoS1);

figure,
lsim(HoS1, t, t);
cvS1 = 1/abs((y1(end)-t(end)));

%% b)

% Magnitude criterion
clc

Hf2 = tf(2, [1 1 0]);

Tsigma = 1;

Hdstar = tf(1, [2*Tsigma^2, 2*Tsigma 0]);

Hc2 = minreal(Hdstar/Hf2);

Ho2 = feedback(Hc2*Hf2, 1);
figure,
step(Ho2)

t = 0:0.1:20;
y2 = lsim(Ho2, t, t);
cv2 = 1/abs((y2(end)-t(end)));

% Symmetrical criterion

HdstarS = tf([4*Tsigma 1], [8*Tsigma^3 8*Tsigma^2 0 0]);

HcS2 = minreal(HdstarS/Hf2);

HoS2 = feedback(HcS2*Hf2, 1);
figure,
step(HoS2);

figure,
lsim(HoS2, t, t);
cvS2 = 1/abs((y2(end)-t(end)));

%% c)

% Magnitude criterion
clc

Hf3 = tf(2, conv([1 1], [10 1]));

Tsigma = 1;

Hdstar = tf(1, [2*Tsigma^2, 2*Tsigma 0]);

Hc3 = minreal(Hdstar/Hf3);

Ho3 = feedback(Hc3*Hf3, 1);
figure,
step(Ho3)

t = 0:0.1:20;
y3 = lsim(Ho3, t, t);
cv3 = 1/abs((y3(end)-t(end)));

% Symmetrical criterion

HdstarS = tf([4*Tsigma 1], [8*Tsigma^3 8*Tsigma^2 0 0]);

HcS3 = minreal(HdstarS/Hf3);

HoS3 = feedback(HcS3*Hf3, 1);
figure,
step(HoS3);

figure,
lsim(HoS3, t, t);
cvS3 = 1/abs((y3(end)-t(end)));

%% d)

% Magnitude criterion
clc

Hf4 = tf(2, conv([1 1 0], [10 1]));

Tsigma = 1;

Hdstar = tf(1, [2*Tsigma^2, 2*Tsigma 0]);

Hc4 = minreal(Hdstar/Hf4);

Ho4 = feedback(Hc4*Hf4, 1);
figure,
step(Ho4)

t = 0:0.1:20;
y4 = lsim(Ho4, t, t);
cv4 = 1/abs((y4(end)-t(end)));

% Symmetrical criterion

HdstarS = tf([4*Tsigma 1], [8*Tsigma^3 8*Tsigma^2 0 0]);

HcS4 = minreal(HdstarS/Hf4);

HoS4 = feedback(HcS4*Hf4, 1);
figure,
step(HoS4);

figure,
lsim(HoS4, t, t);
cvS4 = 1/abs((y4(end)-t(end)));

%% e)

% Magnitude criterion
clc

Hf5 = tf(2, conv([10 11 1], [10 1]));

Tsigma = 1;

Hdstar = tf(1, [2*Tsigma^2, 2*Tsigma 0]);

Hc5 = minreal(Hdstar/Hf5);

Ho5 = feedback(Hc5*Hf5, 1);
figure,
step(Ho5)

t = 0:0.1:20;
y5 = lsim(Ho5, t, t);
cv5 = 1/abs((y5(end)-t(end)));

% Symmetrical criterion

HdstarS = tf([4*Tsigma 1], [8*Tsigma^3 8*Tsigma^2 0 0]);

HcS5 = minreal(HdstarS/Hf5);

HoS5 = feedback(HcS5*Hf5, 1);
figure,
step(HoS5);

figure,
lsim(HoS5, t, t);
cvS5 = 1/abs((y5(end)-t(end)));

%% f)

% Magnitude criterion
clc

Hf6 = tf(2, conv([10 11 1 0], [10 1]));

Tsigma = 1;

Hdstar = tf(1, [2*Tsigma^2, 2*Tsigma 0]);

Hc6 = minreal(Hdstar/Hf6);

Ho6 = feedback(Hc6*Hf6, 1);
figure,
step(Ho6)

t = 0:0.1:20;
y6 = lsim(Ho6, t, t);
cv6 = 1/abs((y6(end)-t(end)));

% Symmetrical criterion

HdstarS = tf([4*Tsigma 1], [8*Tsigma^3 8*Tsigma^2 0 0]);

HcS6 = minreal(HdstarS/Hf6);

HoS6 = feedback(HcS6*Hf6, 1);
figure,
step(HoS6);

figure,
lsim(HoS6, t, t);
cvS6 = 1/abs((y6(end)-t(end)));