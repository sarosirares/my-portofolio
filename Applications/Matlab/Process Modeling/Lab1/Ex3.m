R=100;
V=3.3;
L=0.033;


t=0:0.0001:0.005;
i = (V/R)*(1-exp((-R*t)/L));

plot(t,i)


% syms t V R L 
% 
% i = (V/R)*(1-exp((-R*t)/L));
% 
% L*diff(i, t)+R*i-V
% simplify(ans)