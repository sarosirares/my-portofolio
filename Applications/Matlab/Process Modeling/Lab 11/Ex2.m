clc
clear

N = 10000;

S1 = rand(1, N);
S2 = rand(1, N);

X = 2*S1 - 1;
Y = 2*S2 - 1;

inside_circle = X.^2 + Y.^2 <= 1;

n = sum(inside_circle);

pi_approx = 4 * n / N

hold on
% Plot points inside the circle in blue
plot(X(inside_circle), Y(inside_circle), 'b.', 'MarkerSize', 10);

% Plot points outside the circle in red
plot(X(~inside_circle), Y(~inside_circle), 'r.', 'MarkerSize', 10);
