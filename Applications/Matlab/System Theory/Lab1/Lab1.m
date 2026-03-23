%% First section
%a sinewave of 50kHz over the first 3 periods
f=50e3; % the frequency of the sinewave
T=1/f; %the period (in seconds) of the sinewave
t=linspace(0, 3*T);
t=0:T/50:3*T; %time basis generated in order to obtain 50 points/period
plot(t,sin(2*pi*f*t),'r');
title('Sinewave of 50kHz over 3 periods')
xlabel('Time(sec)');
ylabel('Amplitude');
%% Second section
%usee 'axis' function in order to make visible only the second period
axis([T 2*T -1.1 1.1]);
grid;
shg;
title('Second period zoomed')
%% introduce a phaseshift of -45 degrees
s1=sin(2*pi*f*t); %zero phaseshift
s2=sin(2*pi*f*t-45);
s3=sin(2*pi*f*t-pi/4);
plot(t,s1,t,s2,t,s3);
grid;
shg;
legend('zero PS','-45','-pi/4');
shg;