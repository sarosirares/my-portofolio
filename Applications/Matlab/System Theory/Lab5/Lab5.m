%% simulink

clc
clear

R = 1;
L = 1;
C = 1;

%% impulse signal

H = tf([1], [1 2 2])
figure, impulse(H,10)

%% step fignal

H = tf([1], [1 2 2])
figure, step(H, 10)