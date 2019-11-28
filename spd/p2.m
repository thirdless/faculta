n = input('nr de valori = ');
b = input('p = ');
q = 1 - b;
x = zeros(1, n);
p = zeros(1, n);

for i = 1:n
    x(i) = i;
    p(i) = factorial(n) / (factorial(i) * factorial(n - i)) * b^i * q^(n - i);
end

x
p

subplot(2,1,1);
hold on
grid on
plot(x(1:n), p(1:n), '*r')

subplot(2,1,2)
hold on
grid on
frep = 0;
plot([x(1)-2 x(1)], [frep frep])

for i=1:n
    frep = frep + p(i);
    plot([i, i+1], [frep frep]);
end
plot([x(n) x(n)+2], [frep frep]);
