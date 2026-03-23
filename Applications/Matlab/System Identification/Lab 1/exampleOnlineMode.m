u = ones(1, 200);
y = zeros(1, length(u));
motor = DCMRun.start();
for k = 1:length(u)
 y(k) = motor.step(u(k));
 motor.wait();
end

motor.stop();