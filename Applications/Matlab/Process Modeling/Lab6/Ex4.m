clc
clear
close all

I = [0.00000; 0.00000; 0.00000; 0.00000; 0.00020; 0.00000; 0.00020; 0.00000; 0.00020; 0.00020; 0.00010; 0.00060; 0.00189; 0.00389; 0.00589; 0.00807; 0.01027; 0.01445; 0.01664; 0.01874; 0.02083; 0.02302; 0.02512; 0.02950];
V = [0.00000; 0.36091; 0.71343; 1.07434; 1.25060; 1.43525; 1.61151; 1.79616; 1.97242; 2.33333; 2.50959; 2.68585; 2.87050; 2.98801; 3.08034; 3.12230; 3.16427; 3.23981; 3.27338; 3.31535; 3.34053; 3.35731; 3.38249; 3.43285];

figure; 
hold on;
plot(V, I, 'bo');

n = 6; %6 segmente -> 5 noduri intermediare
idx = [1 5 9 13 17 21 24];
R = zeros(n,1);
Re = 0;

for i = 1:n
    Ii = I(idx(i):idx(i+1));
    Vi = V(idx(i):idx(i+1));
    fit_i = fit(Vi, Ii, 'poly1');
    c = coeffvalues(fit_i);
    fi = c(1) * Vi + c(2);
    plot(Vi, fi, 'r'); 
end

for i = 9:24
    R(i) = V(i)/I(i);
    Re = Re + R(i);
end

% Label the plot
ylabel('Current (I)');
xlabel('Voltage (V)');
title('Piecewise Linear Approximation of LED Voltage-Current Characteristic');
legend('Measured Data', 'Piecewise Linear Fit');
hold off;

display(R)
Re