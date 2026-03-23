% Define s as Laplace variable
s = tf('s');

% Process (Plant only)
G_process = 0.1 / (0.01*s^2 + 0.14*s + 0.41);

% Controller
G_controller = 21.6 / (s + 12);

% Closed-loop system: feedback(G_controller * G_process, 1)
T_closed = feedback(G_controller * G_process, 1);

% Plot step responses
figure;
step(G_process, 'b', T_closed, 'r--');
legend('Process Only', 'Closed-Loop System');
title('Step Response Comparison');
xlabel('Time (s)');
ylabel('Output');
grid on;
