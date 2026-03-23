T=0.1;% constata de timp a sistemului
n=4;t=0:T/100:n*T;% timpul de simulare
l=length(t);% lungimea vectorului de timp t

% generare vector linie, de lungime l, cu toate elementele 0
u=zeros(1,l);% generare vector linie, de lungime l
u(1:100)=1/T;% modificarea primelor 100 de valori din u

plot([0 0],[-1 13],'--k',[-0.1 n*T],[0 0],'--k',t,u,'b*');
set(gca,'XTick',[0, T]);
set(gca,'XTickLabel',{'0','T'})
set(gca,'YTick',[0 1/T]);
set(gca,'YTickLabel',{'0','1/T'})

xlabel('Timp (T)')
ylabel('$\delta(t)$','interpreter', 'Latex')

title('Semnal impuls unitate');% comentariu titlu
grid; % trasare linii de control