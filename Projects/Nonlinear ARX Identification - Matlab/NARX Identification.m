%% Loading data
clear
load("iddata-12.mat")

%% Functions

% Generates a matrix with all the combinations of powers we need
function pow = generate_pow(n, m)
    if n == 1
        pow = (0:m)';
        return;
    end
    pow = [];
    for i = 0:m
        rest = generate_pow(n-1, m-i);
        pow = [pow; i*ones(size(rest, 1), 1), rest];
    end
end

% Generates the vector with the delayed imputs and outputs 
function poly = polyofk(u, y, k, na, nb)
    poly = zeros(1, na+nb);
    for i = 1:na
        if (k-i) > 0
            poly(i) = y(k-i);
        end
    end
    for j = 1:nb
        if (k-j) > 0
            poly(j+na) = u(k-j);
        end
    end
end

% Computation of the predicted and simulated signals
function [Yid_pred, Yval_pred, Ysim_id, Ysim_val] = Ycalc(uid, yid, uval, yval, na, nb, m)
    N = length(uid);
    M = nchoosek(na+nb+m, m); % number of parameters
    
    PHIid = zeros(N, M);
    PHIval = zeros(N, M);

    pow = generate_pow(na+nb, m);

    for k = 1:N
        for elem = 1:M
            PHIid(k,elem) = prod(polyofk(uid, yid, k, na, nb).^pow(elem, :));
            PHIval(k,elem) = prod(polyofk(uval, yval, k, na, nb).^pow(elem, :));
        end
    end

    theta = PHIid\yid;

    Yid_pred = PHIid*theta;
    Yval_pred = PHIval*theta;
    
    % We used the first 'na' real values from the output to initialize the
    % vectors
    Ysim_id = [yid(1:na); zeros(N-na, 1)];
    PHIsimid = zeros(N, M);
    Ysim_val = [yval(1:na); zeros(N-na, 1)];
    PHIsimval = zeros(N, M);

    for k = na+1:N
        for elem = 1:M
            PHIsimid(k,elem) = prod(polyofk(uid, Ysim_id, k, na, nb).^pow(elem, :));
            PHIsimval(k,elem) = prod(polyofk(uval, Ysim_val, k, na, nb).^pow(elem, :));
        end
        Ysim_id(k) = PHIsimid(k, :)*theta;
        Ysim_val(k) = PHIsimval(k, :)*theta;
    end
end

% Computing the MSE values
function [mseId, mseVal, mseIdsim, mseValsim] = MSEcompute(yid, yval, Yid_pred, Yval_pred, Ysim_id, Ysim_val, na)
    mseId = mean((yid(na+1:end) - Yid_pred(na+1:end)).^2);
    mseVal = mean((yval(na+1:end) - Yval_pred(na+1:end)).^2);
    mseIdsim = mean((yid(na+1:end) - Ysim_id(na+1:end)).^2);
    mseValsim = mean((yval(na+1:end) - Ysim_val(na+1:end)).^2);
end

%% Computation

close all

uid = id.InputData{1};
yid = id.OutputData{1};

uval = val.InputData{1};
yval = val.OutputData{1};

N = length(uid);
Ts = id.Ts{1};

na = 2;
nb = 2;
m = 2;

%% Plots

close all

t = 0:Ts:N*Ts-Ts;

[Yid_pred, Yval_pred, Ysim_id, Ysim_val] = Ycalc(uid, yid, uval, yval, na, nb, m);

figure,
plot(t, yid, t(na+1:end), Yid_pred(na+1:end))
title("Identification")
legend("Real", "Predicted")

figure,
plot(t, yval, t(na+1:end), Yval_pred(na+1:end))
title("Validation")
legend("Real", "Predicted")

figure,
plot(t, yid, t(na+1:end), Ysim_id(na+1:end))
title("Identification")
legend("Real", "Simulation")

figure,
plot(t, yval, t(na+1:end), Ysim_val(na+1:end))
title("Validation")
legend("Real", "Simulation")

%% MSE

close all

MSEId = zeros(6, 6);
MSEVal = zeros(6, 6);
MSEIdSIM = zeros(6, 6);
MSEValSIM = zeros(6, 6);

for n = 1:6
    for m = 1:6
        [Yid_pred, Yval_pred, Ysim_id, Ysim_val] = Ycalc(uid, yid, uval, yval, n, n, m);
        [MSEId(n,m), MSEVal(n,m), MSEIdSIM(n,m), MSEValSIM(n,m)] = MSEcompute(yid, yval, Yid_pred, Yval_pred, Ysim_id, Ysim_val, n);
    end
end

[MSEidOpt, idxId] = min(MSEId);
[MSEisOpt, idxIS] = min(MSEIdSIM);
[MSEvalOpt, idxV] = min(MSEVal);
[MSEvsOpt, idxVS] = min(MSEValSIM);

[msevalOpt, mval] = min(MSEvalOpt);
[mseidOpt, mid] = min(MSEidOpt);
[msevsOpt, mvs] = min(MSEvsOpt);
[mseisOpt, mis] = min(MSEisOpt);

disp(['MSE for Predicted Validation data: ', num2str(msevalOpt), ' for na=nb=', num2str(idxV(mval)), ' and m=', num2str(mval)]);
disp(['MSE for Predicted Identification data: ', num2str(mseidOpt), ' for na=nb=', num2str(idxId(mid)), ' and m=', num2str(mid)]);
disp(['MSE for Simulated Validation data: ', num2str(msevsOpt), ' for na=nb=', num2str(idxVS(mvs)), ' and m=', num2str(mvs)]);
disp(['MSE for Simulated Identification data: ', num2str(mseisOpt), ' for na=nb=', num2str(idxIS(mis)), ' and m=', num2str(mis)]);

[msevalOpt, mval] = min(MSEvalOpt);
mseidOpt = MSEidOpt(mval);
[msevsOpt, mvs] = min(MSEvsOpt);
mseisOpt = MSEisOpt(mvs);

disp(['MSE for Predicted Validation data: ', num2str(msevalOpt), ' for na=nb=', num2str(idxV(mval)), ' and m=', num2str(mval)]);
disp(['MSE for Predicted Identification data: ', num2str(mseidOpt), ' for na=nb=', num2str(idxV(mval)), ' and m=', num2str(mval)]);
disp(['MSE for Simulated Validation data: ', num2str(msevsOpt), ' for na=nb=', num2str(idxVS(mvs)), ' and m=', num2str(mvs)]);
disp(['MSE for Simulated Identification data: ', num2str(mseisOpt), ' for na=nb=', num2str(idxIS(mvs)), ' and m=', num2str(mvs)]);

np = idxV(mval);
ns = idxVS(mvs);

%% Plotting the predition and simulation outputs for optimal parameters 

close all

t = 0:Ts:N*Ts-Ts;

[Yid_pred, Yval_pred, ~, ~] = Ycalc(uid, yid, uval, yval, np, np, mval);
figure,
plot(t,yid, t(np+1:end), Yid_pred(np+1:end))
title("Identification for optimal parameters")
legend("Real", "Predicted")

figure,
plot(t, yval, t(np+1:end), Yval_pred(np+1:end))
title("Validation for optimal parameters")
legend("Real", "Predicted")

[~, ~, Ysim_id, Ysim_val] = Ycalc(uid, yid, uval, yval, ns, ns, mvs);
figure,
plot(t, yid, t(ns+1:end), Ysim_id(ns+1:end))
title("Identification for optimal parameters")
legend("Real", "Simulated")

figure,
plot(t, yval, t(ns+1:end), Ysim_val(ns+1:end))
title("Validation for optimal parameters")
legend("Real", "Simulation")

%% Model compare

close all

id = iddata(yid, uid, Ts);
val = iddata(yval(ns+1:end), uval(ns+1:end), Ts);
id_pred = iddata(Yid_pred, uid, Ts);
val_pred = iddata(Yval_pred(ns+1:end), uval(ns+1:end), Ts);
id_sim = iddata(Ysim_id, uid, Ts);
val_sim = iddata(Ysim_val(ns+1:end), uval(ns+1:end), Ts);

figure,
compare(id, id_pred);
figure, 
compare(val, val_pred);

figure,
compare(id, id_sim);
figure, 
compare(val, val_sim);