clc
clear all

% VARIABLES IN MATLAB

A = sscanf("ceeee 23 what", "%s");
% [A, n] = sscanf("what is this", "%s", 1)
% A = sprintf("What is this %d", 4)
x1 = 5;
x2 = 5 + 10j;
x3 = [1 2 3 4]; % or x3 = [1, 2, 3, 4] (LINE VECTOR)
x4 = [1; 2; 3; 4]; % (COLUMN VECTOR)
x5 = [1 2 3; 4 5 6; 7 8 9]; % (3X3 MATRIX)

szA = size(A);
lgtA = length(A);
szx1 = size(x1);
szx2 = size(x2);
szx3 = size(x3);
szx4 = size(x4);
szx5 = size(x5);

% MATRIX GENERATION

eye(3);
zeros(x1);
ones(2);
rand(3,2);
randn(3);

v1 = 0 : 1 : 10; % generate a vector x with values ranging from 0 to 10 with a step of 0.5
v2 = linspace(0, 10, 11); % generate 11 equally spaced values in the range [0, 10]

x5 = [1 2 3; 4 5 6; 7 8 9];
x5_1 = x5(1, :); % first line of the matrix x5
x5_2 = x5(:, 2); % second column of the matrix x5
x5_3 = x5(1, 3); % the element from the first line and third column of x5
x5_4 = x5([1, 3], 1 : 3); % sub-matrix of x5 consisting of lines 1 and 3 and columns 1->3


% ARITHMETIC OPERATIONS ON MATRICES


prod = x5 .* ones(3); % element-by-element multiplication


% RELATIONAL OPERATORS - if applied to scalars -> result is a scalar
%                      - if applied to a matrix -> result is a matrix

% LOGICAL OPERATORS - && and || only to scalar, & and | to any type

% CONTROL INSTRUCTIONS

s = 10;
H = zeros(s);

for c = 1:s
    for r = 1:s
        H(r,c) = r;
    end
end
H;


% COMPLEX NUMBERS

B1 = [1 2; 3 4] + j * [5 6; 7 8];
B2 = [1 + 5i, 2 + 6i; 3 + 7i, 4 + 8i];
B3 = complex([1 2; 3 4], [5 6; 7 8]);

real(B1)
imag(B1)
abs(B1)
angle(B1)
conj(B1)


% MATLAB FILES
%       FUNCTIONS function [out1, out2] = function_name(in1, in2)

% GRAPHICAL REPRESENTATIONS

