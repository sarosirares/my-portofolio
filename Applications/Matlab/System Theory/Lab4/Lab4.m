%% G1

G1 = tf(1, [1 1])
p1 = roots([1 1])
figure, step(G1, 10);
figure, impulse(G1, 10)

%% G2

G2 = tf(1, [1 -1])
p2 = roots([1 -1])
figure, step(G2, 10);
figure, impulse(G2, 10)

%% G3

G3 = tf(1, [1 0 -1])
p3 = roots([1 0 -1])
figure, step(G3, 10);
figure, impulse(G3, 10)

%% G4

G4 = tf(1, [1 0 1])
p4 = roots([1 0 1])
figure, step(G4, 10);
figure, impulse(G4, 10)

%% G5

G5 = tf(1, [1 2 17])
p5 = roots([1 2 17])
figure, step(G5, 10);
figure, impulse(G5, 10)

%% G6

G6 = tf(1, [1 -2 17])
p6 = roots([1 -2 17])
figure, step(G6, 10);
figure, impulse(G6, 10)

%% Testing functions

%% tf
G0 = tf([1 -3 -4], [1 5 6]) %tf
%% zpk
p1 = roots([1 5 6])
z1 = roots([1 -3 -4])
sys = zpk(z1, p1, 1)        %zpk

%% ss2tf
R=1e3; % 1 kOhms
C=1e-6; % 1 micro Farads
L=0.2; % 0.2 Henrry

A=[0 1/C;-1/L -R/L];
B=[0; 1/L];
C=[-1 -R];
D=1;

[b, a] = ss2tf(A,B,C,D)

%% tf2ss

[A, B, C, D] = tf2ss([1, 0, 0], [1, 5000, 5000000])

%% tfdata

%% tf
sys1 = tf(1, [1 1])
sys2 = tf(1, [1 -2 17])
[num, den] = tfdata(sys1)
[num, den] = tfdata(sys2)
%% zpk
p1 = roots([1 5 6])
z1 = roots([1 -3 -4])
sysz = zpk(z1, p1, 1)
[num, den] = tfdata(sysz)
%% State Space
R=1e3; % 1 kOhms
C=1e-6; % 1 micro Farads
L=0.2; % 0.2 Henrry

A=[0 1/C;-1/L -R/L];
B=[0; 1/L];
C=[-1 -R];
D=1;

syss = ss(A,B,C,D)
[num, den] = tfdata(syss)