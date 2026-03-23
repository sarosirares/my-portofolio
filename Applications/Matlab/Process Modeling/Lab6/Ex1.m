clc
clear
close all

I = [0.00000; 0.00000; 0.00000; 0.00000; 0.00020; 0.00000; 0.00020; 0.00000; 0.00020; 0.00020; 0.00010; 0.00060; 0.00189; 0.00389; 0.00598; 0.00807; 0.01027; 0.01445; 0.01664; 0.01874; 0.02083; 0.02302; 0.02512; 0.02590];
V = [0.00000; 0.36091; 0.71343; 1.07434; 1.25060; 1.43525; 1.61151; 1.79616; 1.97242; 2.33333; 2.50959; 2.68585; 2.87050; 2.98801; 3.08034; 3.12230; 3.16427; 3.23981; 3.27338; 3.31535; 3.34053; 3.35731; 3.38249; 3.43285];

% Define indices for each segment
n = 5;
idx = [1 6 10 15 19 24];

% Initialize arrays to store piecewise fits
% fitResults = cell(1, 5);
% fitLines = cell(1, 5);

figure;
hold on;
plot(V, I, 'bo'); % Plot original data in blue

% Loop over each segment and fit a linear model
for i = 1:n
    % Get the data for the current segment
    I_seg = I(idx(i):idx(i+1));
    V_seg = V(idx(i):idx(i+1));
    
    % Perform the linear fit for the current segment
    fitResults{i} = fit(V_seg, I_seg, 'poly1');
    
    % Generate fitted values for plotting
    fitLines{i} = feval(fitResults{i}, V_seg);
    
    % Plot each linear fit segment in red
    plot(V_seg, fitLines{i}, 'r');
end

% Label the plot
ylabel('Current (I)');
xlabel('Voltage (V)');
title('Piecewise Linear Approximation of LED Voltage-Current Characteristic');
legend('Measured Data', 'Piecewise Linear Fit');
hold off;