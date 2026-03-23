function [Fd, R] = CalculateConfigFactor(N, sinMin, sinMax)

n = 0;
S = 0;

while n < N
    n = n + 1;
    R(n) = rand;
    sinB = 1 - 2 * R(n);
    
    if ((sinB > sinMin) && (sinB < sinMax))
        S = S + 1;
    end
end
Fd = S / N;
end