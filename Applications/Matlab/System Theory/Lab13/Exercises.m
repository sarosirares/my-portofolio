clc
clear

A = [-4 -0.2; 5 -10];
B = [2; 0];
C = [0 1];
D = [0];

mDC = ss(A, B, C, D);
[num, den] = ss2tf(A, B, C, D);
step(mDC); hold on;
Hss = tf(num,den);
step(Hss)

H = tf(0.1, [0.01, 0.14, 0.41]);
step(H);
stepinfo(H)

%% 6

eig(A*10)/10
p = pole(H)
zpk(H)

%% 7

t = linspace(0, 3, 500);

x0_1 = [0.1; 0.02];
x0_2 = [0.05; -0.01];

% Simulate state responses
[y1, t1, x1] = initial(mDC, x0_1, t);
[y2, t2, x2] = initial(mDC, x0_2, t);

figure;
plot(t, x1(:,1), 'b'); 
hold on;
plot(t, x2(:,1), 'r');

figure;
plot(t, x1(:,2), 'b'); 
hold on;
plot(t, x2(:,2), 'r');
title('speed w(t)');

figure;
plot(x1(:,1), x1(:,2), 'b'); 
hold on;
plot(x2(:,1), x2(:,2), 'r');
title('Current i_a');

xlabel('i_a(t)');
ylabel('w(t)');
title('Phase Portrait');
grid on;

%% 8,9

k = 0.36;

K = tf(k*60, [1, 12]);
figure
rlocus(K*H);
Hcl = K*H/(1+K*H);

figure;
step(H, Hcl);