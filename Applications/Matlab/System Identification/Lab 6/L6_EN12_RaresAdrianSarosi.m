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

N = 200;

uid1 = inputG(N, 3, -0.7, 0.7);
uid2 = inputG(N, 10, -0.7, 0.7);
uval = 0.4*ones(70, 1);

% figure,
% plot(uid1)
% figure,
% plot(uid2)

u = [zeros(10, 1); uid1; zeros(10, 1); uid2; zeros(10, 1); uval];

figure,
plot(u)

%% Generating the output

y = DCMRun.run(u, 'port', 'COM13', 'Ts', 1e-2, 'type', 'windows');

figure,
plot(u)
figure,
plot(y)

yid1 = y(11:210);
yid2 = y(221:420);
yval = y(431:end);

%% Models

clc

id1 = iddata(yid1', uid1, 1e-2);
id2 = iddata(yid2', uid2, 1e-2);
val = iddata(yval', uval, 1e-2);

model1 = arx(id1, [5, 5, 1]);
model2 = arx(id2, [5, 5, 1]);

figure,
compare(val, model1, model2);