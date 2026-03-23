function [] = CCM(Mp_dB)
%Circle of Constant Magnitude

Mp = 10^(Mp_dB/20)
r = Mp/(Mp^2-1); x = -Mp^2/(Mp^2-1);
v = linspace(0,2*pi,200); plot(sin(v)*r+x,cos(v)*r, 'r');
text(x,r*1.2,[num2str(Mp_dB),'dB'], 'Color','r')
end
