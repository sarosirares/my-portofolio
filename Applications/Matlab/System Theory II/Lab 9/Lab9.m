clc
clear
close all

H = tf(200, [1 0])

bode(H)
figure
nichols(H)

%% 

nichols(tf(3, [0.5 1]))

%%

nichols(tf(16, [1 1 16]))

%%

nichols(4, [1 2 0])

%%

nichols(tf(4, [1 2 0], 'Iodelay', 0.2))
xlim([-270 -90]);
ylim([-30 30]);

%%
kc = 2.65;
H_ol = tf(4, [1 2 0], 'iodelay', 0.2)

figure,
nichols(H_ol, kc*H_ol, 3*H_ol)
xlim([-270 -90]);
ylim([-30 30]);

%% function for stable

wc = 1.58;
pwc = -146;
m_wpi = -8.47
figure,
nichols(tf(4, [1 2 0], 'Iodelay', 0.2))
xlim([-270 -90]);
ylim([-30 30]);
marginNichols(wc, pwc, m_wpi)

%% function for unstable
clc
clear
close all

wc = 3.19;
pwc = -184;
m_wpi = 1;
H_ol = tf(4, [1 2 0], 'iodelay', 0.2);
nichols(3*H_ol)
xlim([-270 -90]);
ylim([-30 30]);
marginNichols(wc, pwc, m_wpi)