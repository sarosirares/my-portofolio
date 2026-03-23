%% Repmat function

N = 5;
x = [1 1 -1 -1];
xr = repmat(x,1,N);
n = 0:length(xr)-1;
stem(n,xr);

%% Mod function

N = 5;
n = 0:4*N-1;
xm = mod(n, N);
stem(n, xm);