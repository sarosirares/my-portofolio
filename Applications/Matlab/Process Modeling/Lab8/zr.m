function [u] = zr(t)

u = 0.1*sin(20*t) + 0.03*sign(sin(5*t)) + 0.02*sign(sin(2*t));

end