R = 5000; C = 0.2e-6; L = 0.3;
A = [0 1/C;-1/L -R/L]; B = [0;1/L]; C = [0 R]; D = 0;
timp = 0 : 0.0001 : 0.008;
U = 5 * ones(1, length(timp));
sistem = ss(A,B,C,D); [Y,T] = step(sistem, timp);
plot(T, 5*Y);
figure
LSIM(sistem, U, T);
