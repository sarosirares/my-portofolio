%step signal u(t) = (t>=0) ? 1 : 0
t1 = -2;
t2 = 6;
tstep = 0.001;
t = t1:tstep:t2;
x = (t>=0)
plot(t, x)
xlabel('t');
ylabel('u(t)');
title('Unit step signal');
axis([t1-tstep, t2+tstep, -0.1, 1.1])