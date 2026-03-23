a = 0.2;
b = -0.5;
t1 = 0;
t2 = 8;
t = [t1, t2];
xe = @(t) (a*exp(b*t));
fplot(xe, t);
grid;
xlabel('t');
ylabel('x_e(t)');
title('x_e(t) = a e^{bt}')