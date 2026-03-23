t=0:0.01:0.1;
a=[sqrt(3)/3 1 sqrt(3)];

plot(t,a(1)*t,'kv-',t,a(2)*t,'k>-',t,a(3)*t,'k<-');
legend('$a=\frac{\sqrt{3}}{3}$','a=1','$a=\sqrt{3}$', 'interpreter','Latex');
title('Semnale ramp\u{a}','interpreter','Latex');
grid;
xlabel('Timp (sec.)');
ylabel('u(t)=a*t')

poz=[0.02 0.06 0.10];

for i=1:3
 panta=atan(a(i))*180/pi;
 text(0.07,poz(i), ['panta de ', num2str(panta),'^o']);
end