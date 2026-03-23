%% a)
clc
clear
close all

[y, Fs] = audioread("harp.mp3");
figure, plot([0:length(y)-1]/Fs, y), xlabel('t'), ylabel('x(t)')
sound(y, Fs)

N = 1024; % total num of samples for each frame
hopSize = N / 2; % num of samples between start of one frame 
numFrames = 20;

t = (0:N-1)/Fs;   % time vector
Ts = 1/Fs;

Ak_trapz = zeros(24, numFrames);  % initialize
Ak_fft = zeros(24, numFrames);    % initialize

for i = 1:numFrames
    startIdx = (i-1)*hopSize + 1;
    frame = y(startIdx:startIdx + N - 1);
    frame = frame(:);  % ensure column

    % Trapezoidal Fourier coefficients
    for k = 1:24
        fk = k * Fs / N;
        cosine = cos(2*pi*fk*(0:N-1)/Fs)';  % column vector
        Ak_trapz(k,i) = (2/N) * Ts * trapz(frame .* cosine);
    end

    % FFT-based coefficients
    Y = fft(frame);
    Ak_fft(:, i) = abs(Y(1:24));
end

% Compute CGS (center of gravity of spectrum)
CGS = zeros(1, numFrames);
for i = 1:numFrames
    Ak = Ak_fft(1:24, i);  % Use FFT-based Ak
    CGS(i) = sum((1:24)' .* Ak) / sum(Ak);  % Weighted average
end

% Plot amplitude spectrum of frame 1 and CGS
figure;
stem(1:24, Ak_fft(1:24,1)); hold on;
xline(CGS(1), 'r--', 'LineWidth', 2);
title('Amplitude Spectrum of Frame 1 with CGS');
xlabel('Frequency Bin');
ylabel('Amplitude');
legend('FFT Amplitudes', 'CGS');

for i = 1:numFrames
    Ak = Ak_fft(1:24, i);
    logAk = 20*log10(Ak + eps);  % add eps to avoid log(0)
    irrSum = 0;
    for k = 2:23
        diff = logAk(k) - mean([logAk(k-1), logAk(k), logAk(k+1)]);
        irrSum = irrSum + abs(diff);
    end
    IRR(i) = log10(irrSum);
end

figure,
subplot(2,1,1); plot(CGS, '-o'); title('CGS across frames'); xlabel('Frame'); ylabel('CGS');
subplot(2,1,2); plot(IRR, '-s'); title('IRR across frames'); xlabel('Frame'); ylabel('IRR');

%% 2
% --- Settings ---
filename = 'harp.mp3';  % Replace with your file name
frame_size = 1024;
overlap = 0.5;
hop_size = frame_size * (1 - overlap);
num_frames = 20;
N_harmonics = 24;

% --- Load and Prepare Audio ---
[x, Fs] = audioread(filename);
x = mean(x, 2);  % Convert to mono if stereo
x = x / max(abs(x));  % Normalize

% --- Frame Extraction and Analysis ---
CGS = zeros(num_frames, 1);
IRR = zeros(num_frames, 1);
A_all = cell(num_frames, 1);

for i = 1:num_frames
    start_idx = round((i - 1) * hop_size) + 1;
    if start_idx + frame_size - 1 > length(x)
        break;  % Avoid overflow
    end
    frame = x(start_idx : start_idx + frame_size - 1) .* hamming(frame_size);

    % FFT
    Y = fft(frame);
    A = abs(Y(1:frame_size/2));  % One-sided spectrum

    % Limit to N harmonics
    N = min(N_harmonics, length(A));
    A = A(1:N);
    A_all{i} = A;

    % --- Compute CGS ---
    k = 1:N;
    CGS(i) = sum(k .* A') / sum(A);

    % --- Compute IRR ---
    logA = 20 * log10(A);
    irr_sum = 0;
    for k = 2:N-1
        avg = (logA(k+1) + logA(k) + logA(k-1)) / 3;
        irr_sum = irr_sum + abs(logA(k) - avg);
    end
    IRR(i) = log10(irr_sum);

    % --- Optional: Plot each spectrum with CGS ---
    figure;
    stem(1:N, A, 'b');
    hold on;
    xline(CGS(i), 'r--', 'CGS');
    title(['Amplitude Spectrum (Frame ', num2str(i), ')']);
    xlabel('Harmonic Number');
    ylabel('|A_k|');
    hold off;
end

% --- b) Compare FFT with Trapezoidal Integration for First Frame ---
frame = x(1:1024) .* hamming(1024);
t = (0:frame_size-1) / Fs;

Ak_fft = abs(fft(frame));
Ak_fft = Ak_fft(1:N_harmonics);

Ak_trap = zeros(1, N_harmonics);
for k = 1:N_harmonics
    cos_basis = cos(2 * pi * k * t);
    Ak_trap(k) = trapz(t, frame' .* cos_basis);
end

% Plot comparison
figure;
plot(1:N_harmonics, Ak_fft, 'b', 1:N_harmonics, Ak_trap, 'r--');
legend('FFT', 'Trapezoidal');
xlabel('Harmonic Number');
ylabel('Amplitude');
title('FFT vs Trapezoidal Method');

% --- Plot CGS and IRR across frames ---
figure;
subplot(2,1,1);
plot(CGS, 'o-');
title('Spectral Center of Gravity (CGS)');
xlabel('Frame');
ylabel('CGS');

subplot(2,1,2);
plot(IRR, 's-');
title('Spectral Irregularity (IRR)');
xlabel('Frame');
ylabel('IRR');

% --- Display Results ---
T = table((1:length(CGS))', CGS, IRR, 'VariableNames', {'Frame', 'CGS', 'IRR'});
disp(T);

%% 3
% === Load Audio and Frame Selection ===
[y, Fs] = audioread("harp.mp3");
N = 1024;   % Frame size
n = 0:N-1;
x = y(8000 + n)';  % Extract a frame as in the train example
t = n / Fs;

% === a) Plot Time-Domain and Spectrum ===
figure;
subplot(3,1,1);
plot(t, x);
xlabel('Time (s)');
ylabel('x(t)');
title('Signal Segment');

% Compute FFT
Xf = fft(x);
A = abs(Xf(1:N/2)) / N;  % One-sided amplitude spectrum

subplot(3,1,2);
stem(1:50, A(1:50), 'filled');
xlabel('Frequency Bin');
ylabel('|A_k|');
title('Amplitude Spectrum');

% === b) Compare FFT Amplitudes with Trapezoidal Integration ===
K = 24;  % Number of harmonics
Ak_fft = A(1:K);     % FFT amplitudes
Ak_trap = zeros(1, K);

for k = 1:K
    basis = cos(2 * pi * k * t);
    Ak_trap(k) = trapz(t, x .* basis);
end

% Plot comparison
figure;
stem(1:K, Ak_fft, 'b', 'filled');
hold on;
stem(1:K, Ak_trap, 'r--');
legend('FFT', 'Trapezoidal');
xlabel('Harmonic Number');
ylabel('Amplitude A_k');
title('FFT vs Trapezoidal Method');

% === c) Spectral Center of Gravity (CGS) ===
k = 1:K;
CGS = sum(k .* Ak_fft') / sum(Ak_fft);

% Plot spectrum with CGS line
figure;
stem(k, Ak_fft, 'b', 'filled');
hold on;
xline(CGS, 'r--', 'LineWidth', 1.5);
xlabel('Harmonic Number');
ylabel('|A_k|');
title('Spectrum with Spectral Center of Gravity (CGS)');
legend('Amplitude Spectrum', 'CGS');

% === d) Spectral Irregularity (IRR) ===
logA = 20 * log10(Ak_fft);
irr_sum = 0;
for i = 2:K-1
    avg = (logA(i-1) + logA(i) + logA(i+1)) / 3;
    irr_sum = irr_sum + abs(logA(i) - avg);
end
IRR = log10(irr_sum);

% === Output Results ===
fprintf('--- Spectral Features ---\n');
fprintf('Spectral Center of Gravity (CGS): %.2f\n', CGS);
fprintf('Spectral Irregularity (IRR): %.4f\n', IRR);
