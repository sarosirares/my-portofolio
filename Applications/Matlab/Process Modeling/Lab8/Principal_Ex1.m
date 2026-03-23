clc
clear
close all

x0 = [0; 0; 0; 0];

[t, x] = ode23('Ex1', [0 10], x0);

uCu = x(:,2);
uCs = x(:,4);

plot(t, zr(t));