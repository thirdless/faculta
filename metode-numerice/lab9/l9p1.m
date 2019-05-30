rel4 = 0;
rel = 1;

while(rel == 1)
    n = input('Grad polinom: ');
    EPS = input('parametru metoda Bairstow: ');
    a = zeros(n, 1);
    aa = zeros(n, 1);
    ac = zeros(n, 1);

    while(rel4 == 0)
        for(i = 0:n)
            ie = i + 1;
            ip = n - 1;
            fprintf('coeficient putere %g, a(%g)=', ip, ie);
            a(ie) = input(' ');
            aa(ie) = a(ie);
        end
        if(a(1) == 0)
            rel4 = 0;
            fprintf('a(1) trebuie sa fie diferit de 0');
        else
            rel4 = 1;
        end
    end

    aa1 = aa(1);
    for(i = 1:n+1)
       aa(i) = aa(i)/aa1;
    end

    ac = a;
    nn = n;
    x = zeros(n, 1);
    iter = 0;
    i = 0; 
    b = zeros(n+3, 1);
    c = zeros(n+2, 1);

    while(nn > 2)
        iter = iter + 1;
        fprintf('Divizor nr. %g', iter);
        b(1) = 0;
        b(2) = 0;
        c(1) = 0;
        c(2) = 0;
        p = 0;
        q = 0;
        flag = 1;
        while(flag == 1)
           for(k = 0:nn)
               ibc = k + 3;
               ia = k + 1;
               b(ibc) = aa(ia) - p * b(ibc - 1) - q * b(ibc - 2);
               c(ibc) = b(ibc) - p * c(ibc - 1) - q * c(ibc - 2);
           end
           in = nn + 3;
           di = c(in - 2)^2 - c(in - 3) * (c(in - 1) - b(in - 1));
           pi = -b(in - 1) * c(in - 2) + b(in) * c(in - 3);
           qi = -b(in) * c(in - 2) + b(in - 1) * (c(in - 1) - b(in - 1));
           if(di == 0)
               fprintf('di - nul : STOP');
               return
           end
           p = p - pi / di;
           q = q - qi / di;
           rr = abs((pi + qi)/ di);
           fprintf('\np = %g\nq = %g\nr = %g\n', p, q, rr);
           if(rr < EPS)
               flag = 0;
           end
        end
        fprintf('Coeficienti divizori: %g, %g, %g\n', 1, p, q);
        xd = roots([1 p q]);
        fprintf('\nRadacini divizor:');
        xd
        i = i + 1;
        x(i) = xd(1);
        i = i + 1;
        x(i) = xd(2);
        nn = nn - 2;
        for(k = 0 : nn)
            ia = k + 1;
            ib = k + 3;
            aa(ia) = b(ib);
        end
    end

    iter = iter + 1;
    fprintf('Divizori nr. %g\n', iter);
    if(nn == 2)
        fprintf('Coeficienti divizor: %g, %g, %g\n', aa(1), aa(2), aa(3));
        xd = roots([aa(1) aa(2) aa(3)]);
        i = i + 1;
        x(i) = xd(1);
        i = i + 1;
        x(i) = xd(2);
    else
        fprintf('Coeficienti divizor: %g, %g', aa(1), aa(2));
        xd = roots([0 aa(1) aa(2)]);
        i = i + 1;
        x(i) = xd;
    end
    fprintf('Radacini divizor: ');
    xd

    L1 = zeros(n - 1, 1);
    an = zeros(1, n);
    for(i = 0 : n - 1)
        ir = n + 1 - i;
        an(i+1) = -a(ir)/a(1);
    end
    f = [L1 eye(n-1)];
    f = [f; an];

    xx = eig(f);
    x_matlab = roots(ac');

    fprintf('Radacini polinom - metoda BAIRSTOW: ');
    x
    fprintf('Radacini polinom - metoda FROBENIUS: ');
    xx
    fprintf('Radacini polinom - functia ROOTS: ');
    x_matlab

    fprintf('Doriti reluarea programului? 1 - da, 0 - nu');
    rel = input(' ');
end

