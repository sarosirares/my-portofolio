clc
clear all
syms s

% Declare the parameters of the circuit
R=1e3; % 1 kOhms
C=1e-6; % 1 micro Farads
L=0.2; % 0.2 Henrry
u = 5;
% Declare state space matrices
A=[0 1/C;-1/L -R/L]
B=[0; 1/L]
C=[-1 -R]
D=1

H1=C*inv(s*eye(2)-A)*B+D

[num, den] = ss2tf(A,B,C,D)

H2 = tf(num, den)

vA = eig(A)

p = roots(den)

% Create state space system
sys = ss(A, B, C, D);

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
axis([0 8e-3 0.1 1.1])
% place the second state variable in the third subplot
subplot(313);plot(t,x(:,2));title('Second state variable');
xlabel('Time (sec.)');legend('x_2(t)=i_L(t)')
axis([0 8e-3 -0.1e-3 2e-3]);ylabel('current (A)');grid;