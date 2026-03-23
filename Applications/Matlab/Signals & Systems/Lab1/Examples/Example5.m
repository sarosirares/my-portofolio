x = @(t) (t>=0);
t1 = -2;
t2 = 6;
t = [t1, t2];
fplot(x, t)
xlabel('t');
ylabel('u(t)');
axis([t -0.1 1.1])
title('Unit step signal');