%% First graph

u = @(t)(t>=0)
A = 1;

t = -3:0.001:3;

figure
subplot(3,3,1)
x1 = -A*u(t);
plot(t,x1)
axis([min(t) max(t) -2 2])
grid;

T = 1;

subplot(3,3,2)
x2 = -A*u(t-T);
plot(t,x2)
axis([min(t) max(t) -2 2])
grid;

subplot(3,3,3)
x2 = -A*u(t+T);
plot(t,x2)
axis([min(t) max(t) -2 2])
grid;

subplot(3,3,4)
x3 = A*u(-t);
plot(t,x3)
axis([min(t) max(t) -2 2])
grid;

subplot(3,3,5)
x4 = A*u(-(t-T));
plot(t,x4)
axis([min(t) max(t) -2 2])
grid;

subplot(3,3,6)
x5 = A*u(-(t+T));
plot(t,x5)
axis([min(t) max(t) -2 2])
grid;

subplot(3,3,7)
x6 = -A*u(-t);
plot(t,x6)
axis([min(t) max(t) -2 2])
grid;

subplot(3,3,8)
x7 = -A*u(-t+T);
plot(t,x7)
axis([min(t) max(t) -2 2])
grid;

subplot(3,3,9)
x8 = -A*u(-t-T);
plot(t,x8)
axis([min(t) max(t) -2 2])
grid;