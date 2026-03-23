clc
clear
close all

N=100000;
VA_9=MonteCarloFixedRW(2,2,N);
VA_10=MonteCarloFixedRW(2,3,N);
VA_11=MonteCarloFixedRW(3,3,N);
VA_12=MonteCarloFixedRW(3,2,N);

fprintf("Potentials:\n");
fprintf("Point 9: %.3f\n", VA_9);
fprintf("Point 10: %.3f\n", VA_10);
fprintf("Point 11: %.3f\n", VA_11);
fprintf("Point 12: %.3f\n", VA_12);