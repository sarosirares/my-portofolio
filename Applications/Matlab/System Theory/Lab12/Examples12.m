%% Example 1

% atribuire de valori parametrilor
wn=3;xi=0.1;k=2;
% declarare funcţie de transfer integrator
Hi=tf(1,[1 0]);
% echivalarea buclei interne
H1=feedback(Hi,2*xi*wn);
% echivalare cale directă
H2=H1*Hi;
% echivalare buclă externă
H3=feedback(H2,wn^2);
% echivalare elemente înseriate
He=k*wn^2*H3;
%he=tf(k*wn^2,[1 2*xi*wn wn^2]);

%% Example 2

clear
% declararea variabilelor simbolice
syms R1 R2 R3 R4 R5 R6 R7 C1 C2 H1 H2 H3 Ho s
H1=R2/R1/(R2*C1*s+1);
H2=1/R3*(C2*s*R4+1);
H3=R5/R6/R7;
Ho=H1*H2/(1+H1*H2*H3);
Ho=collect(simplify(expand(Ho)),'s')
pretty(Ho)