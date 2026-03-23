clear all
R=1;C=1;L=1;u=1;
%s=dsolve('Dx1=-1/L/C*x2','Dx2=x1-1/R/C*x2+1/R/C*u','x1(0)=0','x2(0)=0');
% s=dsolve('Dx1=-x2','Dx2=x1-x2+1','x1(0)=0','x2(0)=0');
s=dsolve('Dx1=1/C*x2','Dx2=1/L*u-1/L*x1-R/Lx2*','x1(0)=0','x2(0)=0');
pretty(s.x2)

t=0:0.2:10; % timp de simulare
%%% varianta copiata din s.x2 %%%
ys=(2*3^(1/2)*sin((3^(1/2)*t)/2))./(3*exp(t).^(1/2));
%%% varianta explicata in lucrare %%%
yl=2*sqrt(3)/3*sin(sqrt(3)/2*t).*exp(-t/2);
plot(t,ys,'^-',t,yl,'v');
legend(['ys=',s.x2],'yl=2*sqrt(3)/3*sin(sqrt(3)/2*t).*exp(-t/2);')
text(4,0.4,'$y(t)=\frac{2\sqrt3}{3}sin(\frac{\sqrt{3}}{2}t)e^{-\frac{t}… …{2}}$','Interpreter','latex','FontSize',20)
title('Semnalul de ie\c{s}ire','Interpreter','latex');
ylabel('Timp (sec.)');xlabel('Tensiune (V)');
xlabel('Timp (sec.)');ylabel('Amplitudine')