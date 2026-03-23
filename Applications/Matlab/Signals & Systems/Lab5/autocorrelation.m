function phi_xx = autocorrelation(x)
    M = length(x);
    phi_xx = zeros(1, M);  % Allocate for lags 0 to M-1

    for n = 0:M-1
        sum = 0;
        for k = 1:M-n
            sum = sum + x(k) * x(k+n);
        end
        phi_xx(n+1) = sum / M;
    end
end
