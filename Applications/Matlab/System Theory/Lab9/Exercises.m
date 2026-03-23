%% Ex1
H = tf(1, [1, 1])
rlocus(H)

%% Ex2

H = tf([1, -2], [1, 3])
rlocus(H)

%% Ex3

H = tf([1, 2],conv([1,-1],[1,4]))
rlocus(H)

%% Ex4

H = tf([1, 5],conv([1,-1],[1, 4]))
rlocus(H)

%% Ex5

roots([1,-1,1])
H = tf([1, -1, 1],conv([1,4,3],[1,4]))
rlocus(H)

%% ex1

H = tf(conv([1,2],[1,3]),[1,1,0])
rlocus(H)

%% ex2

H = tf(conv([1,1],[1,2]), [1,1,1])
rlocus(H)

%% ex3

H = tf(1,conv([1,1,0],[1,2]))
rlocus(H)

