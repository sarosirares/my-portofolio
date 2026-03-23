%% The Unit Step Function

u0 = @(t) (1*(t>=0) + 0);
t1 = -8;
t2 = 8;
t = [t1, t2];

fplot(u0, t)
axis([-8 8 -0.1 1.1]);

%% Shift

t0 = 2;
u0 = @(t) (1*(t>=t0) + 0);
t1 = -8;
t2 = 8;
t = [t1, t2];

fplot(u0, t+t0)
axis([-8 8 -0.1 1.1]);

%% Example

u0 = @(t) (t>=0);
A = 2; T = 1; t = -2:0.001:2;
i = A*u0(t+T/2) - A*u0(t-T/2);
plot(t, i, 'LineWidth', 2)
axis([min(t) max(t) min(i) - 0.01 max(i) + 0.01])
xlabel('t')
ylabel('i(t)')
grid;

%% Triangular waveform

T = 2;
v = @(t)((2/T*t+1)*((-T/2)<=t) + (-2/T*t+1)*(t<=(T/2)) + 0);
t = [-4, 4];
fplot(v,t)
xlabel('t')
ylabel('v(t)')
grid;

%% The Unit Impulse

%% Discrete-time unit impulse signal

u = (n>=0)
n = -8:2;
stem(n, u)

