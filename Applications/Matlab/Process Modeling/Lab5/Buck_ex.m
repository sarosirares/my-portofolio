clc
clear

Rds = 0.02;
RL = 0.037;
L = 0.000012;
RC = 0.025;
C = 0.000047;
Vin = 12;
uD = 0.4;
Rld = 2.5;

D = 0.42; % duty cycle
Fsw = 400000; % frequency
Tsw = 1 / Fsw; % period

ti = 0;
x0 = [0 0]; % ?
t = [];
x = [];

for i = 1 : 400 % t = 0->1 (1 ms)
    % ON
    [ton, xon] = ode45(@Buck_on, [ti, ti+D*Tsw], x0);
    x0 = xon(end, :);
    ti = ton(end);
    t = [t; ton];
    x = [x; xon];
    
    %OFF
    [toff, xoff] = ode45(@Buck_off, [ti, ti+(1-D)*Tsw], x0);
    x0 = xoff(end, :);
    ti = toff(end);
    t = [t; toff];
    x = [x; xoff];
end

figure
subplot(3, 1, 1);
plot(t, x(:,1)); 
grid;
xlabel('Time (seconds)');
ylabel('i_L (A)');

subplot(3, 1, 2);
plot(t, x(:,2));
grid;
xlabel('Time (seconds)');
ylabel('v_C (V)');

subplot(3, 1, 3)
Vout = RC*Rld/(RC+Rld)*x(:,1)+Rld/(RC+Rld)*x(:,2);
plot(t, Vout); 
grid; 
xlabel('Time (seconds)');
ylabel('V_O_U_T (V)');