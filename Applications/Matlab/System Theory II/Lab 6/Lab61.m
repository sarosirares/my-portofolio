%% Stability analysis using Simplified Nyquist Criterion

%% Given the next open loop transfer function:

H_ol = tf(12, [1 5 0], "IOdelay", 0.2)
bode(H_ol)

%% Use 'axis' function to zoom the Phase characteristic around -180 degrees 

bode(H_ol) %properties limits
axis([0.1, 100, -270, 0])
wc = 2.2;

%% Point out the cutoff frequency on Magnitude characteristic; use the following two lines to set the first subplot the active one: 

handles=findobj(gcf,'Type','axes');
axes(handles(2));
hold on
semilogx(wc, 0, 'ok', 'MarkerFaceColor', 'k')
text(wc, 2, '\omega_c')
hold off

%% Read the phase of the open loop at the cutoff frequency\

pw_c = -139;
handles=findobj(gcf,'Type','axes');
axes(handles(2));
hold on
semilogx([0.1, 100], [1, 1]*(-180), '--k')
semilogx([1, 1]*wc, [-180, pw_c], '-m', 'LineWidth',2)
semilogx(wc, pw_c, '^m', 'LineWidth',2)
text(1.2, -150, '\gamma_k=41^0')

%% plot the gain margin 

gainM = 7.47;
handles=findobj(gcf,'Type','axes');
axes(handles(2));
hold on
semilogx([0.1, 100], [0, 0], '--k')
semilogx([1, 1]*4.3, [-gainM, 0], '-m', 'LineWidth',2)
semilogx(4.3, -gainM, 'vm', 'LineWidth',2)
text(5.2, -3.75, 'm_k=7.47')

%% plot w-pi
w_pi = 4.3;

handles=findobj(gcf,'Type','axes');
axes(handles(2));
hold on
semilogx(w_pi, -180, 'ok', 'MarkerFaceColor', 'k')
text(w_pi, -170, '\omega_-_p_i')
hold off


%% 

H_ol2 = tf(20, [1 5 0], "IOdelay", 0.2)
bode(H_ol2)