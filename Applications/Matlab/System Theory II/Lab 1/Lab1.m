H1 = tf(2,[1 1 1])
%% a)
nyquist(H1)
%% 
H2 = tf([1,0,4],[0.3,1,1])
%% b)
nyquist(H2, linspace(0,3,1e3))
%% 4.5
w = 2.61; T = 2*pi/w; t = linspace(0, 10*T, 1000);
u = sin(w*t);
lsim(H2, u, t); shg