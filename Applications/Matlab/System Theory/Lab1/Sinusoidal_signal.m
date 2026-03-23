w=2;% pulsatia semnalului de intrare
T=2*pi/w;% perioada semnalului
n=30;% numar de esantioane pe o perioada
nT=6; % numar de perioade de reprezentat
t=0:T/n:nT*T; % timp de reprezentare

y=sin(w*t); % semnal sinusoidal

plot(t, y, 'LineWidth',2); % reprezentarea grafica
title(['Semnal sinusoidal \it{sin(}',num2str(w),'t)'])

axis([-0.1 nT*T -1.2 1.2]);
grid;

set(gca,'XTick',[0:T:nT*T]);
set(gca,'YTick',[-1 0 1]);
set(gca,'YTickLabel',{'-1','0','1'})

xlabel('Timp (sec.)');
ylabel('Amplitudine');