rel_m = 0;
rel_n = 0;
rel_eps = 0;
rel_a = 0;
rel_b = 0;
rel = 1;

while(rel == 1)

    while(rel_m == 0)
        m = input('m = ');
        m
        rel_m = input('ati introdus corect m?');
    end
    
    while(rel_n == 0)
        n = input('n = ');
        n
        rel_n = input('ati introdus corect n?');
    end

    a = zeros(m, n);
    while(rel_a == 0)
        for(i = 1:m)
            fprintf('linia %g', i);
            a(i,:) = input(' ');
        end
        a
        rel_a = input('ati introdus corect a?');
    end
    
    [u,s,v] = svd(a);
    sv = diag(s);
    clear s;

    while(rel_eps == 0)
        EPS = input('EPS = ');
        EPS
        rel_eps = input('ati introdus corect eps?');
    end

    p = 0;
    tau = max(m,n)* sv(1) * EPS;
    L = min(m,n);
    z = zeros(L,1);
    for(i = 1:L)
       if(sv(i) >= tau)
          p = p + 1;
          z(i) = 1/sv(i);
       else
           sv(i) = 0;
       end
    end
    
    p_matlab = rank(a);
    
    fprintf('\nrang matrice a : %g\nrang calculat : %g\nvalori singulare corectate:\n', p, p_matlab);
    format long e;
    sv
    if(p ~= L)
        fprintf('\nmatrice a: deficienta de rang\n');
    else
        fprintf('\nmatrice a: de rang complet\n');
    end
    
    b = zeros(m,1);
    while(rel_b == 0)
        for(i = 1:m)
            fprintf('linia %g', i);
            b(i,:) = input(' ');
        end
        b
        rel_b = input('ati introdus corect b?');
    end
    
    s = diag(z);
    x = v(:,1:L) * s * u(:,1:L)' * b;
    
    x_matlab = pinv(a) * b;
    
    r = b - a * x;
    r_matlab = b - a * x_matlab;
    
    nrez = norm(r,2);
    nrez_matlab = norm(r_matlab, 2);
    
    x
    r
    nrez
    x_matlab
    r_matlab
    nrez_matlab
    
    
    fprintf('\ndoriti reluarea programului? \n');
    rel = input('rel = ');
   
end
