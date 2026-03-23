%% Function from lab2
function MSE = mse_func(Yapprox, y)
    sum = 0;
    N = length(y);
    for i = 1:N
        sum = sum + (Yapprox(i)-y(i))^2;
    end
    MSE = 1/N*sum;
end

%% Generating data for step
clc
close all

Ts = 1e-2;
u = [zeros(30,1); 0.7*ones(70,1); zeros(30,1); 0.4*ones(70,1); zeros(30,1); -0.5*ones(70,1)];
t = 0:0.01:3-Ts;

%y = DCMRun.run(u, 'port', 'COM9', 'Ts', 1e-2, 'type', 'windows');
%plot(t,u)

%% Isolating data

uid = u(33:100);
yid = y(33:100);

t = 0:0.01:1-0.33;

%plot(t,yid) % identification set

%% Generating transfer function

t = 0:0.01:1-0.33;
yidss = mean(yid(57:67));
uidss = 0.7;

k = yidss/uidss
yidt1 = 0.632*(yidss-0); % y0 = 0
t1 = 0.0501701; % value read from graph
T = t1-0 % t0 = 0

H = tf(k,[T, 1])

yidapprox = lsim(H,uid,t);

% Identification model
% plot(t,yidapprox,t,yid)
% legend('Model', 'yid')

%% Validation

uval = u(133:300);
yval = y(133:300);

t = 0:0.01:3-1.33;

yvalapprox = lsim(H, uval, t);

figure,
plot(t, yvalapprox, t, yval);
legend('Model', 'yval')
title("Step (Validation)")

MSE = mse_func(yvalapprox, yval)

%% Generating data for impulse

Ts = 0.01;
uimp = [0.1*ones(30,1); ones(2,1); 0.1*ones(30,1); ones(2,1); 0.1*ones(30,1); ones(2,1); 0.1*ones(30,1); ones(2,1); 0.1*ones(30,1)];
t = 0:Ts:1.58-Ts;

% plot(t,uimp)

% The impulses should be 1/alpha, alpha being the length of the impulse

% yimp = DCMRun.run(uimp, 'port', 'COM5', 'Ts', 1e-2, 'type', 'windows');

% plot(t,yimp)

%% Isolating data

uimpid = uimp(31:60);
yimpid = yimp(31:60);

t = 0:0.01:0.6-0.31;

% plot(t,yimpid) % identification set

%% Generating transfer function

t = 0:0.01:0.6-0.31;
yimpidss = mean(yimpid(25:30));
uimpidss = 0.1;

kimp = yimpidss/uimpidss
yimpidt2 = yimpidss + (max(yimpid) - yimpidss) * 0.368; % y0 = yimpidss
t2imp = 0.072294; % value read from graph
t1imp = 0.03; % value read from the graph
Timp = t2imp - t1imp

A = -(1/Timp);
B = kimp/Timp;
C = 1;
D = 0;

Himp = ss(A, B, C, D)

yimpidapprox = lsim(Himp,uimpid,t, [yimpidss]); % took yss as initial condition

% Identification model
% plot(t,yimpidapprox, t,yimpid)
% legend('Model', 'yimpid')

%% Validation

uimpval = uimp(62:157);
yimpval = yimp(62:157);

t = 0:0.01:1.57-0.62;

yimpvalapprox = lsim(Himp, uimpval, t, [yimpidss]);

figure,
plot(t, yimpvalapprox, t, yimpval);
legend('Model', 'yval')
title("Impulse (Validation)")

MSEimp = mse_func(yimpvalapprox, yimpval)