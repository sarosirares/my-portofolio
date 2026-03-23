t1 = -8;
t2 = 8;
tstep = 0.001;
t = t1:tstep:t2;

n1 = -6;
n2 = 6;
n = n1:n2;

x1 = (-t+2).*((t>=0)&(t<=4)) + (-t-2).*((t>=-4)&(t<0));
plot(t-1, x1)

figure %continuous signals
subplot(5,1,1)
plot(t, x1)
xlabel('t')
ylabel('x1(t)')
subplot(5,1,2)
plot(t-1, x1)
xlabel('t')
ylabel('x1(t-1)')
subplot(5,1,3)
plot(t+1, x1)
xlabel('t')
ylabel('x1(t+1)')
subplot(5,1,4)
plot(2*t, x1)
xlabel('t')
ylabel('x1(2*t)')
subplot(5,1,5)
plot(t/2, x1)
xlabel('t')
ylabel('x1(t/2)')

x2 = ((-n/2)+1).*((n>0)&(n<=4)) + ((n/2)+1).*((n>=-4)&(n<=0));

figure %discrete signals
subplot(5,1,1)
stem(n, x2)
xlabel('n')
ylabel('x2(n)')
subplot(5,1,2)
stem(n-1, x2)
xlabel('n')
ylabel('x1(n-1)')
subplot(5,1,3)
stem(n+1, x2)
xlabel('n')
ylabel('x1(n+1)')
subplot(5,1,4)
stem(n*2, x2)
xlabel('n')
ylabel('x1(2*n)')
subplot(5,1,5)
stem(n/2, x2)
xlabel('n')
ylabel('x1(n/2)')