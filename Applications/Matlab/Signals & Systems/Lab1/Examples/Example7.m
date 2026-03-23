e = 1 / 100;
x = @(t) (1/e)*((t>0)&(t<=e));
t1 = -1;
t2 = 5;
t = [t1, t2];
fplot(x, t, 5000);
set(gca, 'FontSize', 14)
xlabel('t');
ylabel('p_\epsilon(t)');
title('Pulse functiom \epsilon = 1/00')
axis([t1 t2 -0.1 1.1/e])

