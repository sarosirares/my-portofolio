clc
clear
close all

W = 2;
H = 1;
x = .5;

N = 100;
sinMin = -0.5;
sinMax = 0.5;

Exact_Value = 1/2  * ((W - x) / ((W - x) ^ 2 + H ^ 2) + x / (x ^ 2 + H ^ 2) ^ 1/2)

[Approx_Value, R] = CalculateConfigFactor(N,sinMin,sinMax);

Approx_Value
