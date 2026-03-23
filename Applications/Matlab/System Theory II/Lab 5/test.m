zeta = 0.5;
H = tf(1, [1 1*zeta*2 1])

nyquist(H)

%%

H = tf(1/2*[3 1], [1 1]);

bode(feedback(H,1))
figure,
nyquist(H)

%%

k=[1, 3.16]; Hd=tf(1,conv([1 1 0],[1 2]));

bode(Hd, [0.1 1])
figure,
nichols(Hd)

%%

k = 0.1;

H = tf([1 600], [1 -400]);

nyquist(k*H)

%% 

k = 1;

H = tf(2, [0.5 1], 'iodelay', 0.13);

bode(k*H)

%%

k = 1;

H = tf(8, [1 5 0]);

nyquist(k*H);

%%

H = tf(10, [5 1 0], 'iodelay', 1);

bode(H)

%%

H = tf(18, conv([1 0],[1 3 9]));

bode(H)
figure,
nyquist(H)