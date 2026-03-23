function val = y1(t)
    if (t >= -4) && (t < 0)
        val = -t;
    elseif (t >= 0) && (t<= 4)
        val = t;
    end 
end

function val = y2(t)
    if (t >= 0 && t <= 10)
        val = 0.5^t;
    end
end

function val = y3(t)
    if (t >= -10 && t < -4) || (t >= 4 && t<= 10) 
        val = sin(t);
    elseif (t >= -4 && t < 4)
        val = cos(5*t);
    end
end

t1 = -4:4;
y = zeros(size(t1));

for i = 1:length(t1)
    y(i) = y1(t1(i));
end

figure('Name', 'First function');
plot(t1,y);
hold on;

t2 = 0:0.001:10;
y = zeros(size(t2));

for i = 1:length(t2)
    y(i) = y2(t2(i));
end

figure('Name', 'Second function');
plot(t2,y);
hold on;

t3 = -10:0.001:10;
y = zeros(size(t3));

for i = 1:length(t3)
    y(i) = y3(t3(i));
end

figure('Name', 'Third function');
plot(t3,y);
hold on;