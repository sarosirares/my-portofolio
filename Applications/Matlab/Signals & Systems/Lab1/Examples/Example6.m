%pulse signal p(t) = ((t>=0)&&(t<e)) ? 1/e : 0;

clc
clear all
close

e = 1 / 100
t1 = -1;
t2 = 5;
tstep = 0.005;
t = t1:tstep:t2;
x = (1/e)*((t>0)&(t<=e));
plot(t, x);
xlabel('t');
ylabel('p_\epsilon(t)');
title('Pulse functiom \epsilon = 1/00')

