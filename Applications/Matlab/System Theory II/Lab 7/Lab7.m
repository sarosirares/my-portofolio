clear;clc
h=tf(1,[1 0],'IOdelay',0.2);
w=logspace(-1,2);
[m,f]=bode(h,w);
mm(1,:)=m(1,1,:);ff(1,:)=f(1,1,:);
subplot(211)
semilogx([0.1 1 10 100],[20 0 -20 -40],'k','LineWidth',2);grid
hold;semilogx(w,20*log10(mm),'b');
legend('caracteristica reala','aproximata prin puncte');
title('Caracteristica de modul','FontSize',18);
hold
subplot(212);semilogx(w,ff);hold;
semilogx([0.25 0.5 1 2 4 8]*5,-90-180/pi*[0.25 0.5 1 2 4 8],'ok')
semilogx([0.1/5 0.25 0.5 1 2 4 8]*5,-180/pi*[0, 0.25 0.5 1 2 4 8],'or-')
hold
legend('caracteristica reala','aproximata prin puncte','-\tau_m\omega');
axis([0.1,100,-360,0]);grid
set(gca,'YTick',[-270,-180,-90,0]);
text([1.25,2.5,5,20],-320*[1 1 1 1],{'1.25','2.5','5','20'},'Color','r');
shg

figure,
nyquist(h)

%% a)

h1=tf(12,[1 5 0],'IOdelay',0.2);

figure,
bodemag(h1)

figure,
w=logspace(-1,2);
[m,f]=bode(h1,w);
mm(1,:)=m(1,1,:);ff(1,:)=f(1,1,:);
subplot(211)
semilogx([0.1 1 5 100],[27.6 7.6 -9.39 -58.5],'k','LineWidth',2);grid
hold;semilogx(w,20*log10(mm),'b');
legend('caracteristica reala','aproximata prin puncte');
title('Caracteristica de modul','FontSize',18);
hold
subplot(212);semilogx(w,ff);hold;
semilogx([0.25 0.5 1 2 4 8]*5,-90-180/pi*[0.25 0.5 1 2 4 8],'ok')
semilogx([0.1/5 0.25 0.5 1 2 4 8]*5,-180/pi*[0, 0.25 0.5 1 2 4 8],'or-')
hold
legend('caracteristica reala','aproximata prin puncte','-\tau_m\omega');
axis([0.1,100,-360,0]);grid
set(gca,'YTick',[-270,-180,-90,0]);
text([1.25,2.5,5,20],-320*[1 1 1 1],{'1.25','2.5','5','20'},'Color','r');
shg