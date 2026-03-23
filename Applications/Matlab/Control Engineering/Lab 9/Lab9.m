clc
clear
close all

Hf = tf(2, conv([10 1], [5 1]), 'IODelay', 3);

%% a)

gammak_star = 50;
Hf_phase = -180 + gammak_star + 15;
wc = 0.142;
Ti = 4/wc;
Hf_mag_dB = -0.652;
Hf_mag = db2mag(Hf_mag_dB);
kp = 1/Hf_mag;
Hc_PI = kp * tf([Ti 1], [Ti 0]);

figure,
bode(Hf)

figure,
bode(Hc_PI*Hf)
figure,
step(feedback(Hc_PI*Hf, 1))

%% b)

beta = 0.1;
Hf_b_phase = -180 + gammak_star - atand((1-beta)/2/sqrt(beta));
wc_b = 0.316;
Hf_b_mag_dB = -9.82;
Hf_b_mag = db2mag(Hf_b_mag_dB);
kp_b = sqrt(beta)/Hf_b_mag;
taud = 1/wc_b/sqrt(beta);
Hc_PD = kp_b * tf([taud 1], [beta*taud 1]);

figure,
bode(Hc_PD*Hf)
figure,
step(feedback(Hc_PD*Hf, 1))