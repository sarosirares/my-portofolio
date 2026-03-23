%% 

openExample('audio/DelayBasedAudioEffectExample')

%% parameters

d = 0.5; % delay in seconds
f = 0.35; % feedback
g = 0.5; % gain
w = 0.5; % wet dry mix

%% 

[audioIn,fs] = audioread("Counting-16-44p1-mono-15secs.wav");

%% audio evaluation

sound(audioIn,fs)

%% graphic evaluation

T = 1/fs; % sampling period

t = 0:T:685055*T;
plot(t, audioIn)

%% fct a ecoului

ds = d*fs;
Hd = tf(1, [1, zeros(1, ds)], T);

Hf = feedback(Hd, f, 1);
Hgw = Hf*g*(1-w);
He = Hgw + w;

%% 

out = lsim(He, audioIn);

sound(out, fs)

%% Bad sampling

% sound(out, fs*1.5)
sound(out, fs*0.5)