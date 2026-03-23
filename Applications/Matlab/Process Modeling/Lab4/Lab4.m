[t, x] = ode45(@f2,[0 100], [0 0]);
figure, plot(t, -x(:,1)),
figure, plot(-x(:,1), x(:,2))