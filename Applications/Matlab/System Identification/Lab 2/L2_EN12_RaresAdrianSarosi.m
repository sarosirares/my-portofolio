clc
clear
close all

load("lab2_07.mat")

n = 5; %degree of the approximation

function [theta, PHI] = thetaCompute(x,y,n)
    N = length(x);
    PHI = zeros(N,n);
    Y = y';
    for i = 1:N
        for j = 1:n+1
            PHI(i,j) = x(i)^(j-1);
        end
    end
    theta = PHI\Y;
end

function MSE = mse_func(Yapprox, y)
    sum = 0;
    N = length(y);
    for i = 1:N
        sum = sum + (Yapprox(i)-y(i))^2;
    end
    MSE = 1/N*sum;
end

function [Y_idapprox, Y_valapprox] = approxCompute(xid, yid, xval, yval, n)
    [theta, PHI] = thetaCompute(xid, yid, n);
    Y_idapprox = PHI * theta;
    [~, PHI] = thetaCompute(xval, yval, n);
    Y_valapprox = PHI * theta;
end

function [] = plotApprox(xid, yid, xval, yval, n)
    [Y_idapprox, Y_valapprox] = approxCompute(xid, yid, xval, yval, n);
    figure, plot(xid, yid)
    hold on;
    plot(xid, Y_idapprox), title('Yid(x)')
    figure, plot(xval, yval)
    hold on;
    plot(xval, Y_valapprox), title('Yval(x)')
end

plotApprox(id.X, id.Y, val.X, val.Y, n) %plot for variable n

min_val = inf;
MSE_id = zeros(1,25);
MSE_val = zeros(1,25);

for n = 1:25
    [Y_idapprox, Y_valapprox] = approxCompute(id.X, id.Y, val.X, val.Y, n);
    MSE_id(n) = mse_func(Y_idapprox, id.Y);
    MSE_val(n) = mse_func(Y_valapprox, val.Y);
    if(MSE_val(n) < min_val)
        min_val = MSE_val(n);
        nopt = n;
    end
end

plotApprox(id.X, id.Y, val.X, val.Y, nopt) %plot for optimal n

% Plot MSEs for both id and val
n = 1:25;

figure,
plot(n, MSE_id), title('MSEid');

figure,
plot(n, MSE_val), title('MSEval');

% Display the minimum MSE for validation and the optimal degree for
% approximation
min_val
nopt