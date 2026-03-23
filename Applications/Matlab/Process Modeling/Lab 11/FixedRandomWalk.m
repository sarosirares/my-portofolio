clc
clear
close all

x(1) = 0;
y(1) = 0;

for i=1:100000
    J=rand;
    if J < 0.25
        x(i+1) = x(i) + 1;
        y(i+1) = y(i);
    elseif(J > 0.25) & (J < 0.5)
        x(i+1) = x(i) - 1;
        y(i+1) = y(i);
    elseif(J > 0.5) & (J < 0.75)
        x(i+1) = x(i);
        y(i+1) = y(i) + 1;
    else
        x(i+1) = x(i);
        y(i+1) = y(i) - 1;
    end
end

plot(x,y)