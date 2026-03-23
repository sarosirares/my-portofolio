x = @(t)(4*cos(pi*t-acos (1/4)));
fplot(x, [-2, 3]); grid;
xlabel('t'); ylabel('x(t)');

%% sampling of the continuous signal with period Ts = 0.01 for representation
t = -2:0.01:3;
x = 4*cos(pi*t-acos(1/4));
plot(t, x); grid; xlabel('t'); ylabel('x(t)');