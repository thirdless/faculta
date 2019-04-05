rel_a = 0;
rel_n = 0;
rel_eps = 0;
rel = 1;

while(rel == 1)

    while(rel_eps == 0)
        EPS = input('EPS = ');
        EPS
        rel_eps = input('ati introdus corect eps?');
    end

    while(rel_n == 0)
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

    u = zeros(n);
    q = eye(n);

    format short e;

    for(k = 1:n-2)
        uk = zeros(n, 1);
        sum = sqrt((a(k+1:n,k))' * a(k+1:n,k));

        if(a(k+1, k) >= 0)
           semn = 1; 
        else
            semn = -1;
        end

        sigma = semn * sum;
        uk(k+1) = a(k+1, k) + sigma;
        uk(k+2:n) = a(k+2:n, k);
        beta = sigma * uk(k+1);

        if(beta == 0)
            fprintf('\nbeta - nul : STOP');
            return
        end

        u = eye(n) - (uk * uk') / beta;
        a = u * a * u';
        q = u * q;
        fprintf('k = %g', k);
        a
    end

    h = a;
    fprintf('\nforma superior Hessenberg: \n');
    h

    iter = 0;
    flag = 1;

    while(flag == 1)
        iter = iter + 1;
        miu = h(n,n);
        pt = eye(n);
        h = h - miu * eye(n);
        for(k = 1:n-1)
            r = sqrt((h(k, k))^2 + (h(k+1, k))^2);
            if(r == 0)
               fprintf('r = 0 : STOP');
               return
            end
            ck = h(k, k)/r;
            dk = h(k+1, k)/r;
            p = eye(n);
            p(k, k) = ck;
            p(k+1, k) = -dk;
            p(k, k+1) = dk;
            p(k+1, k+1) = ck;
            h = p * h;
            pt = pt * p';
            q = p * q;
        end
        h = h * pt + miu * eye(n);
        for(i = 1:n-1)
           sum = (abs(h(i+1, i)) + abs(h(i, i))) * EPS;
           if(abs(h(i+1, i)) <= sum)
               h(i+1, i) = 0;
           end
        end
        flag = 0;
        i = 1;
        while(i <= n - 2 && flag == 0)
            if(h(i+1, i) ~= 0 && h(i+2, i+1) ~= 0)
                flag = 1;
            end
            i = i+1;
        end
        if(flag == 0)
            i = 1;
            while(i <= n - 1 && flag == 0)
                if(h(i+1, i) ~= 0)
                    ca = 1;
                    cb = -(h(i, i) + h(i+1, i+1));
                    cc = h(i,i) * h(i+1, i+1) - h(i+1, i) * h(i, i+1);
                    delta = cb * cb - 4 * ca * cc;
                    if(delta >= 0)
                        flag = 1;
                    end
                end
                i = i+1;
            end
        end
        fprintf('\niter = %g\n', iter);
        s = h;
        s
    end
    fprintf('\nforma canonica Schur: \n');
    s
    qt = q';
    fprintf('\nmatricea de transformare:\n');
    qt

    ic = sqrt(-1);
    valp = zeros(1, n);
    vectp = zeros(n);
    j = 1;
    while(j <= n - 1)
        if(s(j + 1, j) == 0)
            valp(j) = s(j, j);
            vectp(:, j) = qt(:, j);
            j = j + 1;
        else
            ca = 1;
            cb = -(s(j,j) + s(j+1, j+1));
            cc = s(j,j) * s(j+1, j+1) - s(j+1, j) * s(j, j+1);
            v = roots([ca cb cc]);
            valp(j) = v(1);
            valp(j+1) = v(2);
            vectp(:, j) = qt(:, j) + ic * qt(:, j+1);
            vectp(:, j+1) = qt(:, j) - ic * qt(:, j+1);
            j = j+2;
        end

        if(j == n)
           valp(j) = s(j,j);
           vectp(:, j) = qt(:, j);
        end
    end

    format short

    valp
    vectp

    ac = qt * s * q;

    aa
    ac
    
    
    
    fprintf('\ndoriti reluarea programului? \n');
    rel = input('rel = ');
   
end
