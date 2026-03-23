%% a)

x0 = @(t)(2*cos(pi*t-acos(-1/2)));
fplot(x0, [-3, 3]); grid;
xlabel('t'); ylabel('x(t)');


%% b)

x1 = @(t)(sin(2*pi/3*t));
fplot(x1, [-6, 0]); grid;
xlabel('t'); ylabel('x(t)');
hold
x2 = @(t)(sin(2*pi/3*t)+1);
fplot(x2, [0, 6]); grid;
xlabel('t'); ylabel('x(t)');
grid;
plot([0 0], [0 1]);

%% c)

x = @(n)(cos(pi*n));
n = [-5:5];
stem(n, x(n)); grid;
xlabel('t'); ylabel('x(t)');

%% d)

x4 = @(t)(-5*sawtooth(pi/5*t));
fplot(x4, [5, 35])
grid;

%% d) without sawtooth

x5 = @(t)(-5*2*abs(mod(t/10,1))+5)

fplot(x5, [5, 35])