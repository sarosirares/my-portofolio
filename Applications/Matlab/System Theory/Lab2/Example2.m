tf=10; % valoare finala a timpul de simulare
x0=[0 0]; %conditii initiale
ode23('RLC1',[0,tf],x0);
legend('solutia x1','solutia x2')

%% pentru reprezentarea grafica a lui x2 %%

[t,x]=ode23('RLC1',[0,tf],x0);
plot(t,x(:,2));grid;
xlabel('Timp (sec)');ylabel('Tensiune (V)')
title('Căderea de tensiune pe condensator')