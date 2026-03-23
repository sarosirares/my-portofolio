%% Generating data
clc
close all

Ts = 0.01;

% u = [zeros(20,1); 0.7+(-0.7-0.7)*rand(550,1); zeros(20,1); 0.2*ones(70,1)];
t = 0:0.01:6.6-Ts;

figure,
plot(t,u)

% y = DCMRun.run(u, 'port', 'COM10', 'Ts', 1e-2, 'type', 'windows');

figure,
plot(t,y)

%% Isolating data
clc
close all

uid = u(20:570);
yid = y(20:570);

uval = u(593:660);
yval = y(593:660);

tid = 0:0.01:5.5;
tval = 0:0.01:0.67;

% figure,
% plot(tid, uid)
% figure,
% plot(tid, yid)

% figure,
% plot(tval, uval)
% figure,
% plot(tval, yval)

% mean(uid) % it is a zero-mean signal 
% mean(yid) % it is not a zero-mean signal

% uid = detrend(uid);
yid = detrend(yid);

% plot(tid, yid)

% mean(uid) % it is a zero-mean signal 
% mean(yid) % now it is a zero-mean signal

%% Computing correlation functions
clc
close all

N = length(uid);
M = 30;
Ru = zeros(N, M);
Ryu = zeros(N, 1);
ru = zeros(1, N);
ryu = zeros(1, N);

for tau = 1:N
    sumu = 0;
    sumyu = 0;
    for k = 1:N-tau
        sumu = sumu + uid(k+tau)*uid(k);
        sumyu = sumyu + yid(k+tau)*uid(k);
    end
    ru(tau) = 1/N*sumu;
    ryu(tau) = 1/N*sumyu;
end
    
for i = 1:N
    for j = 1:M
        Ru(i,j) = ru(abs(j-i) + 1);
    end
end

for i = 1:N
    Ryu(i, 1) = ryu(i);
end

%% Solve equation FIR

h = Ru\Ryu;

%% Simulating model response to whole set
clc
close all

yidapprox = conv(h, uid);
yvalapprox = conv(h, uval);

figure,
plot(yidapprox(1:length(yid)))
hold
plot(yid)

figure,
plot(yvalapprox(1:length(yval)))
hold
plot(yval)

%% MSE

sum = 0;
N = length(yval);
for i = 1:N
    sum = sum + (yvalapprox(i)-yval(i))^2;
end
MSE = 1/N*sum

%% Clear data

clear