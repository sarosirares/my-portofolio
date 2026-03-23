clc; clear;

Ns = 1000; %Number of samples
Ts = 0.001;
T_pause = 0.0001;
N_sampl_plot = 100;
time = [];
Y = [];
time = [time 0];
start = 0;


plotTitle = 'Serial Data Log';  % plot title
xLabel = 'Elapsed Time (s)';    % x-axis label
yLabel = 'Data';                % y-axis label
plotGrid = 'on';                % 'off' to turn off grid
min = 0;                        % set y-min
max = 4096;                      % set y-max
scrollWidth = 10;               % display period in plot, plot entire data log if <= 0

%Define Function Variables
data = 0;
count = 0;

%Open Serial COM Port

figureHandle = figure('NumberTitle','off',...
        'Name','STM32 Data Logger');
ports = serialportlist;

compop = uicontrol('Parent',figureHandle,...
        'Style', 'popupmenu',...
        'String', ports,...
        'Position', [40 30 80 20]);  

startbutton = uicontrol('Parent',figureHandle,...
        'Style', 'togglebutton',...
        'String', 'Start',...
        'Position', [40 5 80 20]); 
    

              
axesHandle = axes('Parent',figureHandle,...
        'YGrid','on',...
        'XGrid','on',...
        'Position', [0.1 0.25 0.85 0.65]);
hold on;

plotHandle = plot(axesHandle,time,data,'-m',time,data,...
                'LineWidth',1,...
                'MarkerEdgeColor','k',...
                'MarkerFaceColor',[.49 1 .63],...
                'MarkerSize',2);
             
title(plotTitle,'FontSize',25);
xlabel(xLabel,'FontSize',15);
ylabel(yLabel,'FontSize',15);
axis([0 10 min max]);
% grid(plotGrid);

while(startbutton.Value == 0)
    compop.String = cellstr(serialportlist);
    pause(0.2)
end

%User Defined Properties 
srlPort = char(compop.String(compop.Value));           % define COM port #
baudRate = 115200;
s = serialport(srlPort,baudRate);
%s.InputBufferSize = 65535;


disp(strcat('Serial Comm Opened on port: ',srlPort));
% fopen(s);
disp('Starting Session');
% profiler on -history
flush(s);

pause(2)
write(s, 1,'uint8');               %flag that starts the communication

while ishandle(plotHandle) %Loop when Plot is Active
     if(s.NumBytesAvailable>2)
        dat = (read(s,1,'uint16')); %Read Data from Serial as int
        count = count + 1;  

        Y(count) = dat(1); %Extract 1st Data Element
        % cmd(count) = dat(2);
        % Wt(count) = dat(3);
        % Ut(count) = dat(4);
       if(mod(count,N_sampl_plot) ==0) 
         if(scrollWidth > 0)
            set(plotHandle,'XData',time(time > time(count)-scrollWidth),'YData',Y(time > time(count)-scrollWidth));
            % set(plotHandle,'XData',time(time > time(count)-scrollWidth),'YData',Y(time > time(count)-scrollWidth));
            axis([time(count)-scrollWidth time(count) min max]);
            else
            set(plotHandle,'XData',time,'YData');
            axis([0 time(count) min max]);
         end

       end
       time = [time time(end)+Ts];
     end
     pause(T_pause);
end

write(s, 0,'uint16');
write(s, 0,'uint16');
write(s, 0,'uint8');

% fclose(s);
% profiler off

time = time(1:length(time)-1);
if(~isempty(time))
    s.NumBytesAvailable
    
    figure; plot(time,Y);%subplot(2,1,1);plot(time,Y,time, Wt);
    %subplot(2,1,2);plot(time,Ut);
end
%Close Serial COM Port and Delete useless Variables

clear s count dat delay max min baudRate ...
        scrollWidth;
 
 
disp('Session Terminated...');
