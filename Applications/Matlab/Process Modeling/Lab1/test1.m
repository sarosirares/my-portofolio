function val = r(t)
    if t >= 0
        val = t;
    else
        val = 0;
    end
end

t = -1:10;
x = zeros(size(t));

for i = 1:length(t)
    x(i) = r(t(i)) - 2*r(t(i) - 1) + 2*r(t(i) - 3) - r(t(i) - 4);
end

figure;
plot(t, x);