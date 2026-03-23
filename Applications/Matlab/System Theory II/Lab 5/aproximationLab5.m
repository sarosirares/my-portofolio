%% Approximate by asymptotes the mmagnitude characteristic (similar to last week)

% H(s)=7(s+8)/(s+5)(s+20)
clc
close all
clear

k = 7*8/5/20;

kdB = 20*log10(k);

w = [0.1, 5, 8, 20, 1000];
s = [0, -20, 0, -20];

hold on
semilogx([0.1, 5], [kdB, kdB], '-o', 'LineWidth', 2, 'Color', 'r');
semilogx([5, 8], [kdB, kdB + (-20)*log10(8/5)], '-o', 'LineWidth', 2, 'Color', 'r');
semilogx([8, 20], [kdB + (-20)*log10(8/5), kdB + (-20)*log10(8/5)], '-o', 'LineWidth', 2, 'Color', 'r');
semilogx([20, 1000], [kdB + (-20)*log10(8/5), kdB + (-20)*log10(8/5) + (-20)*log10(1000/20)], '-o', 'LineWidth', 2, 'Color', 'r');

H = zpk([-8], [-5, -20], 7)
bodemag(H); grid; shg; hold;

%% function
close all

k = 7*8/5/20;
w = [0.1, 5, 8, 20, 1000];
s = [0, -20, 0, -20];
kdb = 20*log10(k);

hold
for i = 1:length(w)-1
    kdbdiff = s(i)*log10(w(i+1)/w(i));
    semilogx([w(i), w(i+1)], [kdb, kdb + kdbdiff], '-o', 'LineWidth', 2, 'Color', 'r');
    kdb = kdb + kdbdiff;
end

H = zpk([-8], [-5, -20], 7)
bodemag(H); grid; shg; hold;

%% function
% H(s)=15s/(s+3)

k = 15/3; % Calculate the gain for the new transfer function
kdb = -20 + 20*log10(k);
w = [0.1, 3, 15/3 100];
s = [20, 0, 0];

hold

for i = 1:length(w)-1
    kdbdiff = s(i)*log10(w(i+1)/w(i));
    semilogx([w(i), w(i+1)], [kdb, kdb + kdbdiff], '-o', 'LineWidth', 2, 'Color', 'r');
    kdb = kdb + kdbdiff;
end

H = zpk([0], [-3], 15);
bodemag(H); grid; shg; hold;