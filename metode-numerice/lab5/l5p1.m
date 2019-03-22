rel_a = 0;
rel_b = 0;
rel_xn = 0;

EPS = input('EPS = ');
max_iter = input('max_iter = ');
n = input('n = ');

a = zeros(n);
while(rel_a == 0)
    for(i = 1:n)
        fprintf('linia %g', i);
        a(i,:) = input(' ');
    end
    a
    rel_a = input('ati introdus corect a?');
    for(i = 1:n)
        if(abs(a(i,i)) < EPS)
            fprintf('element pe diagonala nul sau foarte mic\nRearanjati si reintroduceti A');
            rel_a = 0;
        end
    end
end

b = zeros(n,1);
while(rel_b == 0)
    for(i = 1:n)
        fprintf('linia %g', i);
        b(i,1) = input(' ');
    end
    b
    rel_b = input('ati introdus corect b?');
end

xn = zeros(n,1);
while(rel_xn == 0)
    for(i = 1:n)
        fprintf('linia %g', i);
        xn(i,1) = input(' ');
    end
    xn
    rel_xn = input('ati introdus corect xn?');
end

nn = diag(diag(a));
p = nn-a;
g = inv(nn)*p;
valp = eig(g);
ro = max(abs(valp));
fprintf('\nraza spectrala matrice convergenta, ro = %g', ro);
if(ro < 1)
   fprintf('\nmetoda converge');
else
    fprintf('\nmetoda nu converge');
end

vninf = 1;
iter = 0;
format long e

while((vninf > EPS) && (iter < max_iter))
    iter = iter + 1;
    xv = zeros(n,1);
    xv = xn;
    for(i=1:n)
        sum = 0;
        for(j = 1:i-1)
           sum = sum+a(i,j)*xv(j);
        end
        for(j = i+1:n)
            sum = sum + a(i,j) * xv(j);
        end
        xn(i) = (b(i) - sum)/a(i,i);
    end
    vninf = max(abs(xn-xv));
    fprintf('\niter = %g', iter);
    xn
    fprintf('\nvninf = %g', vninf);
end

x = a\b;

fprintf('\niter = %g', iter);
xn
x

format short
