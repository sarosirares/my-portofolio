clc

A = [-4 -0.2; 5 -10];
B = [2; 0];
C = [0 1];
D = [0];

mDC = ss(A, B, C, D);
[num, den] = ss2tf(A, B, C, D);
step(mDC); hold on;
H = tf(num,den);
step(H);

%% 2

H = tf(0.1, [0.01, 0.14, 0.41]);
step(H);
stepinfo(H)