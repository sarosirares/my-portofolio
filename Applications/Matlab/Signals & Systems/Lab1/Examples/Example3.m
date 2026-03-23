f = @(x)(2*x.^2+0.2*abs(x)+20)
x = -1:0.1:1;
result = f(x)

fplot(f)