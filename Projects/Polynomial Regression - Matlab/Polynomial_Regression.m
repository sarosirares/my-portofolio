clc
clear
close all

load ("proj_fit_09.mat")

% Functions

function [PHI] = phicalc(m,x1,x2)
    N1 = length(x1);
    N2 = length(x2);
    N = (m+1)*(m+2)/2; % number of parameters
    k = 0;
    PHI = zeros(N1*N2, N);
    for i = 1:N1
        for j = 1:N2
            elem = 0;
            k = k + 1;
            for pow1 = 0:m
                for pow2 = 0:(m-pow1)
                    elem = elem + 1;
                    PHI(k,elem) = x1(i)^(pow1) * x2(j)^(pow2);
                end
            end   
        end
    end
end

function [Y] = reshapeY(y)
    N1 = length(y);
    N2 = length(y);
    Y = zeros(N1*N2,1);
    k = 0;
    for i = 1:N1
        for j = 1:N2
            k = k + 1;
            Y(k,1) = y(i,j);
        end
    end
end

function [Yhat] = computeReg(PHI, y, theta)
    N1 = length(y);
    N2 = length(y);
    yhat = PHI * theta;
    Yhat = zeros(N1, N2);
    k = 0;
    for i = 1:N1
        for j = 1:N2
            k = k+1;
            Yhat(i, j) = yhat(k);
        end
    end
end

% Preparing data

x1i_id = id.X{1};
x2j_id = id.X{2};
y_id = id.Y;

x1i_val = val.X{1};
x2j_val = val.X{2};
y_val = val.Y;

MSEvalvect = zeros(1, 25);
MSEidvect = zeros(1, 25);

% Finding the best polynomial degree for approximation

for m = 1:25
    PHI_id = phicalc(m, x1i_id,x2j_id);
    Y_id = reshapeY(y_id);
    theta = PHI_id \ Y_id;
    Yhat_id = computeReg(PHI_id, y_id, theta);

    PHI_val = phicalc(m, x1i_val, x2j_val);
    Yhat_val = computeReg(PHI_val, y_val, theta);

    sum1 = 0;
    sum2 = 0;

    for i = 1:length(Yhat_val)
        sum1 = sum1 + norm(Yhat_val(i)-y_val(i))^2;
    end
 
    for i = 1:length(Yhat_id)
        sum2 = sum2 + norm(Yhat_id(i)-y_id(i))^2;
    end
    
    MSEvalvect(m) = sum1 / length(Yhat_val);
    MSEidvect(m) = sum2 / length(Yhat_id);
end

[minMSE, mOpt] = min(MSEvalvect);
disp(['Minimum MSE: ', num2str(minMSE), ' at polynomial degree: ', num2str(mOpt)]);

PHI_id = phicalc(mOpt, x1i_id, x2j_id);
Y_id = reshapeY(y_id);
theta = PHI_id \ Y_id;
Yhat_id = computeReg(PHI_id, y_id, theta);
    
PHI_val = phicalc(mOpt, x1i_val, x2j_val);
Yhat_val = computeReg(PHI_val, y_val, theta);

% Displaying the results
figure, mesh(x1i_id, x2j_id, y_id, 'FaceColor', 'b');
hold on, mesh(x1i_id, x2j_id, Yhat_id, 'FaceColor', 'r');
xlabel("x1i")
ylabel("x2j")
zlabel("y")
legend('y', 'yapprox')
title("Approximation with optimal degree, m = 11 (Identification)")

figure, mesh(x1i_val, x2j_val, y_val, 'FaceColor', 'b');
hold on, mesh(x1i_val, x2j_val, Yhat_val, 'FaceColor', 'r');
xlabel("x1i")
ylabel("x2j")
zlabel("y")
legend('y', 'yapprox')
title("Approximation with optimal degree, m = 11 (Validation)")

% Displaying MSE
figure, 
plot(MSEvalvect, 'Color', 'r')
hold on
plot(MSEidvect, 'Color', 'b')
legend('Validation MSE', 'Identification MSE')