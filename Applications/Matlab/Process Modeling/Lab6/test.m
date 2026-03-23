clc
clear
close all

% Define the current (I) and voltage (V) data
I = [0.00000; 0.00000; 0.00000; 0.00000; 0.00020; 0.00000; 0.00020; 0.00000; 0.00020; 0.00020; 
     0.00010; 0.00060; 0.00189; 0.00389; 0.00598; 0.00807; 0.01027; 0.01445; 0.01664; 0.01874; 
     0.02083; 0.02302; 0.02512; 0.02590];
V = [0.00000; 0.36091; 0.71343; 1.07434; 1.25060; 1.43525; 1.61151; 1.79616; 1.97242; 2.33333; 
     2.50959; 2.68585; 2.87050; 2.98801; 3.08034; 3.12230; 3.16427; 3.23981; 3.27338; 3.31535; 
     3.34053; 3.35731; 3.38249; 3.43285];

% Define indices for each segment
n = length(V);
segments = round(linspace(1, n, 6));

% Initialize arrays to store piecewise fits and errors
fitResults = cell(1, 5);
fitLines = cell(1, 5);
errors = cell(1, 5);

% Plot original data and piecewise fits
figure;
subplot(2, 1, 1); % Top plot for data and piecewise fits
hold on;
plot(V, I, 'bo-', 'DisplayName', 'Measured Data'); % Plot original data in blue

% Loop over each segment to fit and calculate error
for k = 1:5
    % Get the data for the current segment
    V_seg = V(segments(k):segments(k+1));
    I_seg = I(segments(k):segments(k+1));
    
    % Perform the linear fit for the current segment (I as function of V)
    fitResults{k} = fit(V_seg, I_seg, 'poly1');
    
    % Generate fitted values for the segment
    fitLines{k} = feval(fitResults{k}, V_seg);
    
    % Plot each linear fit segment in red
    plot(V_seg, fitLines{k}, 'r-', 'LineWidth', 1.5, 'DisplayName', ['Segment ' num2str(k) ' Fit']);
    
    % Calculate the absolute error for the current segment
    errors{k} = abs(I_seg - fitLines{k});
end

% Label the plot
xlabel('Voltage (V)');
ylabel('Current (I)');
title('Piecewise Linear Approximation of LED Voltage-Current Characteristic');
legend('Location', 'southeast');
hold off;

% Plot the error evolution
subplot(2, 1, 2); % Bottom plot for error evolution
hold on;

% Plot the error for each segment separately
for k = 1:5
    V_seg = V(segments(k):segments(k+1));
    plot(V_seg, errors{k}, 'o-', 'LineWidth', 1.5, 'DisplayName', ['Segment ' num2str(k) ' Error']);
end

xlabel('Voltage (V)');
ylabel('Absolute Error |I_{measured} - I_{fit}|');
title('Error Evolution of Piecewise Linear Approximation');
legend('Location', 'northeast');
hold off;