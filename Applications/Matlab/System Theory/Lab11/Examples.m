%% ex1

H1 = tf([1 2],conv([1 1 0],[1 3]));
rlocus(H1)

%% ex2

H2 = tf([1 5],conv([1 1 0],[1 3]));
rlocus(H2)