clc
clear
clear all

syms i V R L C t

R = 100;
V = 3.3;
L = 0.033;
C = 0.002;

%
%i = (V/R) * (1 - exp(-R*t/L));
%didt = diff(i,t);
%
%didt + (R/L) * i - V/L;
%simplify(ans)
%
%subs(i, t ,0)
%

didt = diff(i,t); % first derivative of i

I = dsolve('D2i+(R/L)*Di+i/(L*C)=V/L', 'i(0)=0')
