% Define n range
n_min = -5;
n_max = 10;
n = n_min:n_max;

% Define delta[n]
delta = @(n) double(n == 0);

% Define x[n] = delta[n] + 2delta[n-1] - delta[n-3]
x = arrayfun(@(k) delta(k) + 2*delta(k-1) - delta(k-3), n);

% Define h[n] = 2delta[n+1] + 2delta[n-1]
h = arrayfun(@(k) 2*delta(k+1) + 2*delta(k-1), n);

% y1[n] = x[n] * h[n]
y1 = conv(x, h);
ny1 = 2*n_min : 2*n_max;

% y2[n] = x[n+1] * h[n] => shift x[n] to the left by 1 (advance)
x2 = arrayfun(@(k) delta(k+1) + 2*delta(k) - delta(k-2), n); % x[n+1]
y2 = conv(x2, h);
ny2 = 2*n_min : 2*n_max;

% y3[n] = x[n] * h[n+2] => shift h[n] to the left by 2 (advance)
h3 = arrayfun(@(k) 2*delta(k+3) + 2*delta(k+1), n); % h[n+2]
y3 = conv(x, h3);
ny3 = 2*n_min : 2*n_max;

% Plotting
figure;

subplot(3,1,1);
stem(ny1, y1, 'filled');
title('y_1[n] = x[n] * h[n]');
xlabel('n'); ylabel('y_1[n]'); grid on;

subplot(3,1,2);
stem(ny2, y2, 'filled');
title('y_2[n] = x[n+1] * h[n]');
xlabel('n'); ylabel('y_2[n]'); grid on;

subplot(3,1,3);
stem(ny3, y3, 'filled');
title('y_3[n] = x[n] * h[n+2]');
xlabel('n'); ylabel('y_3[n]'); grid on;