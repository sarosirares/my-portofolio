% Define the point of interest (coordinates A)
x = 45; % x-coordinate
y = 2.5;  % y-coordinate

% Choose the number of random walks (N)
N = 1000; % A higher value for better accuracy

% Call the MonteCarloFloatingRW function
TA = MonteCarloFloatingRW(x, y, N);

% Display the estimated temperature at point (x, y)
disp(['Estimated temperature at point (', num2str(x), ', ', num2str(y), '): ', num2str(TA), '°C']);
