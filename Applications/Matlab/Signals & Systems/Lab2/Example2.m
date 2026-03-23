x = @(n)(2*cos(pi*n));
n = [-6:6];
stem(n, x(n)); grid;
xlabel('t'); ylabel('x(t)');