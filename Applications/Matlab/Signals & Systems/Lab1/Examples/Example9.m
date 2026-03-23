A = 2;
T = 1/10;
phi = pi/3;
t1 = -0.1;
t2 = 0.2;
t = [t1, t2];
xs = @(t) (A*sin(2*pi/T*t + phi));
fplot(xs, t);
grid;
xlabel('t');
ylabel('x_s(t)');
title('x_s(t)=Asin((2 \pi /T t + \phi')