%analytical expression

n = -6:6;
x = (n/2);

figure()
stem(n, x)

u = @(t)(t>=0);

%a) 
xa = ((2-n)/2).*((2-n<=4) & (2-n>=-4));
xb = ((n+2)/2).*((n+2<=4) & (n+2>=-4));

figure();
stem(xa, n)
figure();
stem(xb, n)

