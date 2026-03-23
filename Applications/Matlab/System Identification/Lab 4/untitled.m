clc; clear; close all;
ts =0.01;
a=-0.7;
b=0.7;
n=500;
ur=a+(b-a)*rand(n,1);
uedi = [zeros(10,1); ur; zeros(10,1); 0.2*ones(70,1)];

yedi = DCMRun.run(uedi);