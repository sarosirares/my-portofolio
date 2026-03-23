T=0.1;
n=4;
e=[T/100 T/10 T];

for i=1:length(e)
 t=0:e(i):n*T;
 l=length(t);

 % generare vector linie, de lungime l, cu toate elementele 1
 u=ones(1,l);

 subplot(1,3,i)

 plot(t,u,'b*-');
 set(gca,'XTick',[0:T:n*T]);
 set(gca,'YTick',[0 0.5 1]);
 set(gca,'YTickLabel',{'0','0.5','1'})

 xlabel('Timp (s)');ylabel('u(t)');

 title(['Semnal esantionat la ',num2str(e(i)),'s']);

 axis([-0.03 n*T -0.1 1.2]);grid
end
