clc
clear
close all

N = 10;            %Numărul de valori generate
Te = 1/N;           %Perioada de eșanitionare
t = 0:Te:1-Te;      %se creează vectorul timp
s1 = sin(2*pi*t);    %se creează vectorul sinus
s2 = sin(4*pi*t);

s1 = s1 + 1;            %se trece s din domeniul [-1,1] în [0,2]
s1 = s1*127.5;        %se trece s din domeniul [0,2] în [0,255]
s2 = s2 + 1;            %se trece s din domeniul [-1,1] în [0,2]
s2 = s2*127.5;        %se trece s din domeniul [0,2] în [0,255]

s=(s1 + s2)/2;

s = round(s);       %se convertește din valori reale în întregi

for i=1:N
fprintf("%d, ", s(i));
end

plot(t,s)