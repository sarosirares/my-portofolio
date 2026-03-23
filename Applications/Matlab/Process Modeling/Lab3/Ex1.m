clc
clear
close all

syms x;

% Ex1

% a)
f(x) = asin(2*x+3);
fprintf('\nThe function differentiated is: %s', diff(f(x)))
fprintf('\nThe simplified form is: %s', simplify(diff(f(x))))

% b)
fprintf('\n')

g(x) = atan(x^2+1);
fprintf('\nThe function differentiated is: %s', diff(g(x)))
fprintf('\nThe simplified form is: %s\n', simplify(diff(g(x))))

% Ex2

% a)

fprintf('\na) %s', int(x*sin(x^2)))
fprintf('\nb) %s', int(x^2*sqrt(x+4)))
fprintf('\nc) %s\n', int(exp(-x^2), -inf, inf))

