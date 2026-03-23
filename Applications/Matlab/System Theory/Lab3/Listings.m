%% R, L, C circuit; L C parallel, in series with R

clc
clear all
% Declare symbolic parameters
syms R1 L1 C1
% Declare state space matrices symbolically
A_sym=[-1/R1/C1 -1/C1;1/L1 0]

B_sym=[1/R1/C1; 0]

C_sym=[1 0]

D_sym=0

% Computing the transfer function symbollicaly
syms s;
H=C_sym*inv(s*eye(2)-A_sym)*B_sym+D_sym

% Force monic shape by normalizing the denominator coefficients
%1. extract the numerator and denominator of symbolic TF
[num,den]=numden(H);  
%2. determine the denominator coefficients
den_coeffs=coeffs(den,s);
%3. Divide all coefficients by the leading coefficient
den_monic = den / den_coeffs(3);
num_monic=num / den_coeffs(3);
%4. Rebuild the ratio of the two polynomials
H_monic=collect(num_monic,s) /collect(den_monic,s);
disp(H_monic)

%% Example of a State Space declaration

clc

% Declare the parameters of the circuit
R1=1e3; % 1 kOhms
C1=1e-6; % 1 micro Farads
L1=0.2; % 0.2 Henrry
% Declare state space matrices
A=[-1/R1/C1 -1/C1;1/L1 0]
B=[1/R1/C1; 0]
C=[1 0]
D=0

% Create state space system
sys = ss(A, B, C, D);
% Display the state space system 
sys

% Display in rational form the state space matrix A
format rat
A

format
A

sys.A

sys.A(1,2)=-2e6;
disp(sys.A)

%% Simulate the response to exogenous inputs

clc

% Redeclare the ss object, in case it was previously corrupted
sys=ss([-1/R1/C1 -1/C1;1/L1 0],[1/R1/C1; 0],[1 0],0);
% Initial conditions values
x0=[0.2 0];
% time basis, around 8 milliseconds
t=linspace(0,8e-3,1e3);
% exogenouse input as unity step signal
u=ones(1,length(t));
% lsim generates the response y and the states x
[y,t,x]=lsim(sys,u,t,x0);
% arrange in the first subplot, the output / the system response together
% with the input step signal
subplot(311);plot(t,y,t,u);title('Input vs Output')
legend('y(t)-time response','u(t)-input signal');grid
xlabel('Time (sec.)');axis([0 8e-3 -0.5 1.1]);
ylabel('Voltage (V)')
% place the first state variable in the second subplot
subplot(312);plot(t,x(:,1));title('First state variable');
grid; legend('x_1(t)=u_C(t)');ylabel('Voltage (V)')
axis([0 8e-3 -0.5 0.5])
% place the second state variable in the third subplot
subplot(313);plot(t,x(:,2));title('Second state variable');
xlabel('Time (sec.)');legend('x_2(t)=i_L(t)')
axis([0 8e-3 0 2e-3]);ylabel('current (A)');grid;