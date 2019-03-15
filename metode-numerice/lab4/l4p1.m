n = 0;
rel_n = 0;
rel_a = 0;
rel_b = 0;
rel_eps = 0;

while(rel_eps == 0)
    EPS = input('EPS = ');
    eps
    rel_eps = input('ati introdus corect eps?');
end

while(n < 2 && rel_n == 0)
    n = input('n = ');
    n
    rel_n = input('ati introdus corect n?');
end
a = zeros(n);
while(rel_a == 0)
    for(i = 1:n)
        fprintf('linia %g', i);
        a(i,:) = input(' ');
    end
    a
    rel_a = input('ati introdus corect a?');
end
aa = a;
b = zeros(n,1);
while(rel_b == 0)
    for(i = 1:n)
        fprintf('linia %g', i);
        b(i) = input(' ');
    end
    b
    rel_b = input('ati introdus corect b?');
end
bb = b;

L = eye(n);
for(k = 1:n-1)
    [m1, ik] = max(abs(a(k:n,k)));
    ik = ik + (k - 1);
    if(ik ~= k)
        wmx = zeros(1,n);
        wmx = a(k,:);
        a(k,:) = a(ik,:);
        a(ik,:) = wmx;
        t = b(k);
        b(k) = b(ik);
        b(ik) = t;
    end
    if(abs(a(k,k)) > EPS)
       a(k+1:n, k) = a(k+1:n,k)/a(k,k);
       a(k+1:n,k+1:n) = a(k+1:n, k+1:n) - a(k+1:n,k) * a(k,k+1:n);
       temp = eye(n);
       temp(k+1:n,k) = a(k+1:n,k);
       L = L * temp;
       b(k+1:n) = b(k+1:n) - a(k+1:n,k) * b(k);
       a(k+1:n,k) = zeros(n-k,1);
    else
        frpintf('pivot nul sau foarte mic\nSTOP: algoritm');
        return;
    end
    k
    fprintf('inversa matricii Gauss de transformare: ');
    temp
    L
    a
    b
end

for(i = 1: n)
   if(abs(a(i,i))< EPS)
      fprintf('matrice prost conditionata');
   end
end
b(n) = b(n)/a(n,n);
for(i = n-1:-1:1)
    sum = a(i, i+1:n) * b(i+1:n);
    b(i) = (b(i) - sum) / a(i,i);
end
x = b;

x_bs = aa\bb;
x_inv = inv(aa) * bb;

format long e;

x
x_bs
x_inv

r = bb-aa*x;
nr = norm(r, 2);
r_bs = bb - aa * x_bs;
nr_bs = norm(r_bs, 2);
r_inv = bb - aa * x_inv;
nr_inv = norm(r_inv, 2);

nr
nr_bs
nr_inv
