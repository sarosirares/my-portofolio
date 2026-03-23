%% Getting data

clc
clear
close all

load("iv_8.mat")

uid = id.InputData{1};
yid = id.OutputData{1};

uval = val.InputData{1};
yval = val.OutputData{1};

% Ts is the same for both val and id

Ts = id.Ts{1};
Nid = length(yid);
Nval = length(yval);

tid = 0:Ts:Nid*Ts-Ts;
tval = 0:Ts:Nval*Ts-Ts;

figure,
subplot(2,1,1), plot(tid, uid), title("Identification Input")
subplot(2,1,2), plot(tid, yid), title("Identification Output")
figure,
subplot(2,1,1), plot(tval, uval), title("Validation Input")
subplot(2,1,2), plot(tval, yval), title("Validation Output")

%% ARX

clc
close all

PHI = zeros(Nid, n+n);

for k = 1:Nid
    for i = 1:n
        if (k-i) <= 0
            PHI(k,i) = 0;
        else
            PHI(k,i) = -yid(k-i);
        end
    end
    for j = 1:n
        if (k-j) <= 0
            PHI(k,j+n) = 0;
        else
            PHI(k,j+n) = uid(k-j);
        end
    end
end

thetaARX = PHI\yid;

ysim = zeros(Nid, 1);
phisim = zeros(Nid, n+n);

for k = 1:Nid
    for i = 1:n
        if (k-i) <= 0
            phisim(k,i) = 0;
        else
            phisim(k,i) = -ysim(k-i);
        end
    end
    for j = 1:n
        if (k-j) <= 0
            phisim(k,j+n) = 0;
        else
            phisim(k,j+n) = uid(k-j);
        end
    end
    ysim(k) = phisim(k,:)*thetaARX;
end

PHIiv = zeros(n+n, n+n);

sum = 0;
for k = 1:Nid
    sum = sum + phisim(k, :)'.*PHI(k, :);
end

PHIiv = (1/Nid) * sum;

sum = 0;
for k = 1:Nid
    sum = sum + phisim(k, :)*yid(k);
end

Y = (1/Nid) * sum;

thetaiv = PHIiv\Y';

data_id = iddata(yid, uid, Ts);
data_val = iddata(yval, uval, Ts);
model_iv = idpoly([1 thetaiv(1:n)'], [0 thetaiv(n+1:end)'],[],[],[],0,Ts);
model = arx(data_id, [n n, 1]);

compare(data_val, model_iv, model)