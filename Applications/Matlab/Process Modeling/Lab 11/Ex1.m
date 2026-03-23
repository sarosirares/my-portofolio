clc
clear

N1 = 10;
N2 = 40;
N3 = 80;
s1_1 = 0;
s2_1 = 0;
s3_1 = 0;
s1_2 = 0;
s2_2 = 0;
s3_2 = 0;

A = rand(N1, 1);
B = rand(N2, 1);
C = rand(N3, 1);

for j=1:N1
s1_1 = s1_1 + sin(A(j));
end

for j=1:N2
s2_1 = s2_1 + sin(B(j));
end

for j=1:N3
s3_1 = s3_1 + sin(C(j));
end

for j=1:N1
s1_2 = s1_2 + sin(A(j))/A(j);
end

for j=1:N2
s2_2 = s2_2 + sin(B(j))/B(j);
end

for j=1:N3
s3_2 = s3_2 + sin(C(j))/C(j);
end

I1_1 = (pi/(2*N1))*s1_1
I2_1 = (pi/(2*N2))*s2_1
I3_1 = (pi/(2*N3))*s3_1

I1_2 = (pi^2/(8*N1))*s1_2
I2_2 = (pi^2/(8*N2))*s2_2
I3_2 = (pi^2/(8*N3))*s3_2

e1 = I1_2 - I1_1^2
e2 = I2_2 - I2_1^2
e3 = I3_2 - I3_1^2