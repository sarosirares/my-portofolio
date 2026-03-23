function dxdt = f2(t, x)
m = 100;
Fc = 0;
if (x(1) > 30)
    Fc = (40/m)*(x(1)-30)+(8/m)*x(2);
end
dxdt = zeros(size(x));
dxdt(1) = x(2);
dxdt(2) = 9.81-sign(x(2))*(0.25/m)*(x(2)^2)-Fc;
end