clc
clear
close all

q = [120; 150; 180; 200; 250; 300; 320; 340; 380; 400; 450; 500; 550; 600; 650; 700; 750; 800];
h = [13; 17; 20; 25; 30; 34; 35; 39; 41; 44; 50; 53; 58; 62; 66; 69; 72; 78];

% c = zeros(2,1);
% c = [18 * mean(q.^2), 18 * mean(q); 18 * mean(q), 18]^(-1) * [18 * mean(q.*h); 18 * mean(h)]

fit_q = fit(h, q, 'poly1');
p = coeffvalues(fit_q);
a = p(1)
b = p(2)

r_l = b+a*h;

hold on;
plot(h, r_l, 'r')

m_q = mean(q)
m_h = mean(h)
sd_q = std(q)
sd_h = std(h)