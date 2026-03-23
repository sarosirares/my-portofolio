H = tf(20*[1 2], conv([1 10],[1 5]));
zpk(H)
w = [1e-1, 2, 5, 10, 1e3]; % vector that contains the frequencies in the ascending order + range margins
k = 4/5; kdB = 20*log10(k);
hold
semilogx([w(1), w(2)], [kdB, kdB], '-o', 'LineWidth', 2, 'Color', 'r');
semilogx([w(2), w(3)], [kdB, kdB+20*log10(w(3)/w(2))], '-o', 'LineWidth', 2, 'Color', 'r');
semilogx([w(3), w(4)], [kdB+20*log10(w(3)/w(2)), kdB+20*log10(w(3)/w(2))], '-o', 'LineWidth', 2, 'Color', 'r');
semilogx([w(4), w(5)], [kdB+20*log10(w(3)/w(2)), kdB+20*log10(w(3)/w(2))-20*log10(w(5)/w(4))], '-o', 'LineWidth', 2, 'Color', 'r');
bodemag(H); grid; shg; hold;