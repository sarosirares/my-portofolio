%% S1: - Stability analysis depending on k

clear; % erase all the existing workspace variables
num = [240]; den = [1 40]; % the nominator and denominator of the process
Hp = tf(num,den, 'iodelay', 0.025); % the process transfer function
T = 0.02; % the sampling period
Hdes = c2d(Hp, T, 'zoh'); % the open loop discrete time transfer function
% subplot(121); rlocus(Hp); title('Continuous-time approach'); % we cannot
% plot rlocus for H with delay
rlocus(Hdes)
title('Discrete-time approach')
zpk(Hdes) % tf - products of zeros and poles

%% 
clc
k = 0:1e-3:0.318;
p = rlocus(Hdes, k)
[k', p']

%% Overdamped case, k = (0, 0.00986);
k = 0.005;
Ho = feedback(k*Hdes, 1);
figure,
subplot(121); step(Ho, 0.3); title('Overdamped, k=0.005, damping factor > 1')
subplot(122); Ho = feedback(k*Hdes, 1); pzmap(Ho)

% where the poles are located? - in the unity circle (3 real poles) (-0.0642, 0.117, 0.396)

%% Critically damped case, k = 0.00986;
k = 0.00986;
Ho = feedback(k*Hdes, 1);
figure,
subplot(121); step(Ho, 0.5); title('Critically damped, k=0.00986, damping factor = 1')
subplot(122); Ho = feedback(k*Hdes, 1); pzmap(Ho)

% where the poles are located? - in the unity circle (2 equal real poles and one going to zero)
%                              - (+0.266)

%% Underdamped case, k = (0.00986, 0.318);
k = 0.2;
Ho = feedback(k*Hdes, 1);
figure,
subplot(121); step(Ho, 0.5); title('Underdamped, k=0.2, damping factor = 0.177')
subplot(122); Ho = feedback(k*Hdes, 1); pzmap(Ho)

% where the poles are located? - in the unity circle
%                              - 2 complex conjugated poles (0.316 +- 0.746j)
%                              - one real pole going to zero

%% Undamped case, k = 0.318;
k = 0.318;
Ho = feedback(k*Hdes, 1);
figure,
subplot(121); step(Ho, 0.5); title('Stability limit, k=0.318, damping factor = 0')
subplot(122); Ho = feedback(k*Hdes, 1); pzmap(Ho)

% where the poles are located? - exactly on the unity circle (0.321 +- 0.939j)

%% Unstable case, k = (0.318, +inf);
k = 5;
Ho = feedback(k*Hdes, 1);
figure,
subplot(121); step(Ho, 0.2); title('Unstable CL, k=5')
subplot(122); Ho = feedback(k*Hdes, 1); pzmap(Ho)

% where the poles are located? - outside unity circle, unstable cl 
%                              - (0.334 +- 3.68j)
