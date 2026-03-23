%% 1

sx = -7; ex = 0;
sy = 0; ey = 7;
dtx = sx:ex;
dty = sy:ey;
dtw = sx+sy : ex+ey;
x = (-1).^dtx;
y = ones(1, ey-sy+1);
w = conv(x,y);
subplot(3,1,1); stem(dtx, x); xlabel('n'); ylabel('x[n]');
subplot(3,1,2); stem(dty, y); xlabel('n'); ylabel('y[n]');
subplot(3,1,3); stem(dtw, w); xlabel('n'); ylabel('w[n]');

%% 2

x = @(n)(n>=1);
v = @(n)((0.5).^(n-1).*(n>=0));
sx = 1; ex = 20; dtx = sx:ex;
sv = 0; ev = 19; dtv = sv:ev;
dty = sx+sv:ex;
y = conv(double(x(dtx)), v(dtv));
subplot(3,1,1); stem(dtx, x(dtx)); xlabel('n'); ylabel('x[n]');
subplot(3,1,2); stem(dtv, v(dtv)); xlabel('n'); ylabel('v[n]');
subplot(3,1,3); stem(dty, y(1:length(dty))); hold on;
y2 = (4-((0.5).^(dty-2))).*(dty>=1);
stem(dty,y2,'*r'); xlabel('n'); ylabel('y[n]');

%% 2 eu
clc

sx = 1; ex = 20; dtx = sx:ex;
sv = 0; ev = 19; dtv = sv:ev;
dty = sx+sv:ex+ev;
x = (dtx>=1);
v = ((0.5).^(dtv-1).*(dtv>=0));
y = conv(x, v);
figure
subplot(3,1,1); stem(dtx, x); xlabel('n'); ylabel('x[n]');
subplot(3,1,2); stem(dtv, v); xlabel('n'); ylabel('v[n]');
subplot(3,1,3); stem(dty, y); hold on;
y2 = (4-((0.5).^(dty-2))).*(dty>=1);
stem(dty,y2,'*r'); xlabel('n'); ylabel('y[n]');

N=20 %for controling the amount of samples
dty_short = dty(1:N);
y_short = y(1:N);
