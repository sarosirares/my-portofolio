function [y] = sin_discret(f, n, nT)
    Ts = 1/(f*n);
    w = 2*pi*f;
    N = n*nT;

    y = zeros(1, N);
    y(1) = 0;
    y(2) = sin(w*Ts);

    % y(1) = -sin(w*Ts);
    % y(2) = 0

    for k = 3:N
        y(k) = 2*cos(w*Ts)*y(k-1)-y(k-2);
    end

    t = 0:(N-1);

    stem(t/n, y);
end