%% evidenţierea performanţelor
close all % se închid ferestrele curente
h=tf(7,[3 1 10]);% se declară un element de ordinul II
k=7/10; % factorul de proporţionalitate
wn=sqrt(10/3); % pulsaţia naturală
df=1/3/2/wn; % factorul de amortizare
step(h);% afişarea răspunsului la treaptă
hold ; % reţinerea afişării curente
%% suprareglajul
sigma=k*exp(-pi*df/sqrt(1-df^2))
%% valoarea primului maxim
ymax=k*(1+exp(-pi*df/sqrt(1-df^2)))
%% timpul de atingere al primului maxim
tmax=pi/wn/sqrt(1-df^2)
%% plasare punct în maxim
plot(tmax,ymax,'.b','MarkerSize',20);shg
%% plasare linie verticală prin maxim
plot([tmax tmax],[0 ymax],'--');shg
%% evidenţiere linie limită valoare staţionară
plot([0 tmax],[ymax ymax],'--');shg
%% formulă text pentru maxim
s='$y_{max}=k(1+e^\frac{-\pi\xi}{\sqrt{1-\xi^2}})$'
text(tmax+0.5,ymax,s,'Interpreter','Latex','FontSize',40);shg
%% formulă text pentru timp atingere maxim
s='$t_{max}=\frac{\pi}{\omega_n\sqrt{1-\xi^2}} $'
text(tmax,0.1,s,'Interpreter','Latex','FontSize',40);
%% timpul de răspuns
ts=4/df/wn;
%% text formulă timp de răspuns
s='$t_s=\frac{4}{\xi\omega_n}$';
text(4/df/wn,0.1,s,'Interpreter','Latex','FontSize',40,'FontWeight','bold')
plot(4/df/wn,k,'.b','MarkerSize',20);
plot([4/df/wn 4/df/wn],[0 k],'--');shg