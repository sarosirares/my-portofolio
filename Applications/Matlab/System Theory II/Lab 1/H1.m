%% Homework 1
clc
clear
close all

%% c)
H3 = tf([1,0,0],[0.3,1,1]);
nyquist(H3)
%% d)
H4 = tf([1,0],[0.3,1,1]);
nyquist(H4)