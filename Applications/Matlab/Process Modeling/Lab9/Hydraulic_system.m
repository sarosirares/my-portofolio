clc
clear
close all

% Known Data
H1 = 30.48;               % Elevation of the reservoir (m)
C_HW = 120;               % Hazen-Williams coefficient (dimensionless)

% Pipe data [Length (m), Diameter (m)]
pipes = [304.8, 0.254;    % Pipe 1-2
         457.2, 0.254;    % Pipe 1-3
         304.8, 0.254];   % Pipe 2-3

% Known outflows at Nodes 2 and 3
Q_out2 = 0.0425;          % Flow leaving Node 2 (m^3/s)
Q_out3 = 0.085;           % Flow leaving Node 3 (m^3/s)

% Calculate resistance coefficients K for each pipe
K = zeros(3, 1);
for i = 1:3
    L = pipes(i, 1);      % Length of the pipe (m)
    d = pipes(i, 2);      % Diameter of the pipe (m)
    K(i) = 10.67 * (L / (C_HW^1.852 * d^4.87));
end

% Initial guesses for flow rates (Q12, Q13, Q23)
Q = [0.05; 0.03; 0.02];  % Initial guesses (m^3/s)

% Tolerance and maximum iterations
tol = 1e-6;
max_iter = 100;

% Newton's Method Iteration
for iter = 1:max_iter
    % Compute head losses (h12, h13, h23)
    h = K .* abs(Q).^1.852;
    
    % Continuity equations
    f1 = Q(1) - Q(3) - Q_out2;           % Node 2: Q12 - Q23 = Q_out2
    f2 = Q(2) + Q(3) - Q_out3;           % Node 3: Q13 + Q23 = Q_out3
    
    % Energy conservation in the loop (1-2-3)
    f3 = h(1) - h(2) - h(3);             % h12 - h13 - h23 = 0
    
    % Jacobian matrix
    J = [
        1,  0, -1;                       % df1/dQ
        0,  1,  1;                       % df2/dQ
        1.852 * K(1) * abs(Q(1)).^0.852, -1.852 * K(2) * abs(Q(2)).^0.852, -1.852 * K(3) * abs(Q(3)).^0.852
    ];
    
    % Update flows using Newton's method
    F = [f1; f2; f3];
    delta_Q = -J \ F;
    Q = Q + delta_Q;
    
    % Check for convergence
    if max(abs(delta_Q)) < tol
        fprintf('Converged after %d iterations\n', iter);
        break;
    end
end

% Display results
if iter == max_iter
    disp('Newton''s method did not converge.');
else
    fprintf('Flow rates (m^3/s):\n');
    fprintf('Q12 = %.6f\n', Q(1));
    fprintf('Q13 = %.6f\n', Q(2));
    fprintf('Q23 = %.6f\n', Q(3));
end

% Given data
H1 = 30.48; % Reservoir head (m)
C_HW = 120; % Hazen-Williams coefficient

% Pipe dimensions and flow rates
L_12 = 304.8; % Length of pipe 1-2 (m)
D_12 = 0.254; % Diameter of pipe 1-2 (m)
Q_12 = 0.0425; % Flow rate in pipe 1-2 (m^3/s)

L_13 = 457.2; % Length of pipe 1-3 (m)
D_13 = 0.254; % Diameter of pipe 1-3 (m)
Q_13 = 0.085; % Flow rate in pipe 1-3 (m^3/s)

% Calculate resistance factors (K)
K_12 = (10.67 * L_12) / (C_HW^1.852 * D_12^4.87);
K_13 = (10.67 * L_13) / (C_HW^1.852 * D_13^4.87);

% Calculate head losses
h_12 = K_12 * abs(Q_12)^1.852;
h_13 = K_13 * abs(Q_13)^1.852;

% Calculate H2 and H3
H2 = H1 - h_12;
H3 = H1 - h_13;

% Display results
fprintf('H2 = %.2f m\n', H2);
fprintf('H3 = %.2f m\n', H3);
