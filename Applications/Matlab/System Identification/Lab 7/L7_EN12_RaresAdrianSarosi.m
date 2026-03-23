%%
clear

%%
clc
close all

%% Function

function [u] = inputG(N, m, a, b)

u = zeros(N, 1);
A = zeros(m, m);
aparam = zeros(m, 1);
X = ones(m, 1);

    switch m
        case 3
            aparam(1) = 1;
            aparam(3) = 1;
        case 4
            aparam(1) = 1;
            aparam(4) = 1;
        case 5
            aparam(2) = 1;
            aparam(5) = 1;
        case 6
            aparam(1) = 1;
            aparam(6) = 1;
        case 7
            aparam(1) = 1;
            aparam(7) = 1;
        case 8
            aparam(1) = 1;
            aparam(2) = 1;
            aparam(7) = 1;
            aparam(8) = 1;
        case 9
            aparam(4) = 1;
            aparam(9) = 1;
        case 10
            aparam(3) = 1;
            aparam(10) = 1;
    end

    for i = 1:m
        A(1, i) = aparam(i);
    end

    for i = 2:m
        for j = 1:(m-1)
            if (i-1) == j
                A(i, j) = 1;
            end
        end
    end

    for k = 1:N
        X(:, k+1) = mod(A*X(:, k), 2);
        u(k) = [zeros(1, m-1), 1] * X(:, k);
        u(k) = a + (b-a)*u(k);
    end
end

%% Generating the input signals

% N = 200;
Ts = 1e-2;

% uid = inputG(N, 10, -0.7, 0.7);
% uval = 0.4*ones(70, 1);

% figure,
% plot(uid)
% figure,
% plot(uval)

% u = [zeros(10, 1); uid; zeros(10, 1); uval];

% figure,
% plot(u)

%% Generating the output

% y = DCMRun.run(u, 'port', 'COM14', 'Ts', 1e-2, 'type', 'windows');
N = length(yid);

% figure,
% plot(u)
% figure,
% plot(y)

yid = y(11:210);
yval = y(221:end);

% figure,
% plot(yid)
% figure,
% plot(yval)

%% loop

clc

Ts = 1e-2;
N = length(yid);

theta = zeros(2, 102);

f = 0.1;
b = 200;
alpha = 0.1;
thold = 1e-5;
theta(:, 2) = [f; b];
nk = 3;

e = zeros(1, N);
de = zeros(2, N);

l = 2;

while (norm(theta(:, l) - theta(:, l-1)) > thold) && (l < 102)
    sum1 = [0; 0];
    sum2 = [0, 0; 0, 0];
    for k = 1:nk
        e(k) = yid(k);
        de(:, k) = [0; 0];
    end
    for k = (nk+1):N
        e(k) = yid(k) + f*yid(k-1) - b*uid(k-nk) - f*e(k-1);
        de(1, k) = yid(k-1) - e(k-1) - f*de(1, k-1);
        de(2, k) = -uid(k-nk) - f*de(2, k-1);
        sum1 = sum1 + e(k)*de(:, k);
        sum2 = sum2 + de(:, k)*de(:, k)';
    end
    dV = 2/(N-nk) * sum1;
    H = 2/(N-nk) * sum2;
    
    theta(:, l+1) = theta(:, l) - alpha*(H\dV);
    f = theta(1, l+1);
    b = theta(2, l+1);

    l = l+1;
end

%% model

model = idpoly(1, [zeros(1, nk) b], 1, 1, [1 f], 0, Ts);
val = iddata(yval', uval, 1e-2);
figure,
compare(val, model); 