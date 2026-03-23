clc
clear
close all

filterlen = 40;
%create a FIR filter using dsp.FIRFilter
%the filter coefficients, [b0,b1,...,bN], are specified as second
%parameter, after 'Numerator'
FIRFilter = dsp.FIRFilter('Numerator', ones(1,filterlen)/filterlen);
%create a moving average filter using dsp.MovingAverage
mvgAvgFilter = dsp.MovingAverage(filterlen);
%filtering of a signal using the previously created filters
input = randn(1024,1);
filterOutput = FIRFilter(input);
mvgAvgOutput = mvgAvgFilter(input);
figure, plot(input), hold on, plot(filterOutput, 'r'), plot(mvgAvgOutput, '--g')

%% Filtering an audio signal
clc

%loading an audio signal in Matlab, graphical representation of the
%signal, playing the audio signal
load mtlb
y = mtlb;
L = length(y);
k = 0:L-1;
k = k';
t = k/Fs;
sound(y,Fs)
figure, plot(t,y)

%noise addition
noise=0.5*sin(2*pi*1000/L*k);
y_z = y + noise;
sound(y_z,Fs)

%generation of a FIR bandpass filter coefficients
N = 100; Fpl = 100; Fph = 1000; Wbp = [Fpl Fph]./(Fs/2);
bpf = fir1(N,Wbp,'bandpass');

%filtering of the noisy signal
outbpf = filter(bpf,1,y_z);
sound(outbpf,Fs)

yo = conv(bpf,y_z);
sound(yo,Fs)