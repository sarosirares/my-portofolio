clc
clear
close all

H1 = tf(2,conv([1,1],[1,3]));
rlocus(H1)

H2 = tf([1,-2],conv([1, 1],[1, 3]));
rlocus(H2)

H3 = tf(2,conv([1,1,0],[1,3]));
rlocus(H3)