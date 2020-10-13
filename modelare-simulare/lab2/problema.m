lambda = 10;
segmente = 1000;
pas = (5/lambda)/segmente;

t = 0:pas:5/lambda;
F = 1 - exp(-t * lambda);

plot(t, F, '-b');

N = 10000;
segmente = 20;
n = zeros(N, 1);
pas = (5/lambda)/segmente;
for i = 1:N
    j = ceil(genExp(lambda)/pas);
    if(j < segmente)
        n(j) = n(j) + 1;
    end
end

f = zeros(N, 1);
k = 1;
for i = 1:N
    f(i) = 0;
    for j = 1:k
        f(i) = f(i) + n(j);
    end
    k = k + 1;
    f(i) = f(i)/N;
end

hold on;

i = 1;
for x = pas:pas:5/lambda
    plot(x, f(i), 'ro');
    i = i + 1;
end
