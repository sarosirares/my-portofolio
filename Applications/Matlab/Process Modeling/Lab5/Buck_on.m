function dxdt = Buck_on(t, x)

Rds = 0.02;
RL = 0.037;
L = 0.000012;
RC = 0.025;
C = 0.000047;
Vin = 12;
Rld = 2.5;

A = [(-1/L)*(Rds+RL+(RC*Rld)/(Rld+RC)) (-1/L)*(1-RC/(Rld+RC)); 1/C*(Rld/(Rld+RC)) (-1/C)*1/(Rld+RC)];
B = [1/L;0];
C = [(RC*Rld)/(RC+Rld) Rld/(RC+Rld); 0 0];
D = zeros(1);

dxdt = [A(1,1)*x(1,1) + A(1,2)*x(2,1) + B(1,1)*Vin; A(2,1)*x(1,1) + A(2,2)*x(2,1)];

end