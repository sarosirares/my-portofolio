clc
clear
close all

a1 = 0.0001;
b1 = 0;
a2 = 0.0122;
b2 = -0.0317;
a3 = 0.0675;
b3 = -0.2038;

x1 = 2.61;
x2 = 3.11;
x3 = 3.43;

x = linspace(0, x3, 24);
y = zeros(size(x));
index = [1 10 15 19 24];

for i = 1:length(x)
    if x(i) <= x1
        y(i) = a1*x(i) + b1;
    elseif x(i) <= x2
        y(i) = a2*x(i) + b2;
    else
        y(i) = a3*x(i) + b3;
    end
end

p = polyfit(x, y, 4);
y_poly = polyval(p, x);

plot(x, y_poly);

for i=1:4
xi = x(index(i):index(i+1));
yi = y(index(i):index(i+1))
plot(xi, yi, 'r');
end


