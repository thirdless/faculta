rel = 1;
while(rel == 1)
    a = input('a = ');
    b = input('b = ');
    c = input('c = ');
    if(a == 0)
        if(b == 0)
            fprintf('Ecuatia nu poate fi rezolvata\n');
        else
            z1r = -c/b;
            fprintf('\nz1 = %g\n', z1r);
        end
    else
        if(c == 0)
            z1r = 0;
            z1i = 0;
            z2r = -b/a;
            z2i = 0;
        else
            bp = b/2;
            if(abs(bp) >= abs(c))
                e = 1-(a/bp)*(c/bp);
                d = sqrt(abs(e)) * abs(bp);
            else
                e = a;
                if(c < 0)
                    e = -a;
                end
                e = bp * (bp / abs(c)) - e;
                d = sqrt(abs(e)) * sqrt(abs(c));
            end
            if(e >= 0)
                if(bp >= 0)
                    d = -d;
                end
                z1r = -(bp+d)/a;
                z1i = 0;
                z2r = 0;
                if(z1r ~= 0)
                    z2r = (c/z1r)/a;
                end
                z2i = 0;
            else
                z1r = -bp/a;
                z1i = abs(d/a);
                z2r = z1r;
                z2i = -z1i;
            end
        end
        
        fprintf('\nz1 = %g + %g * j\n', z1r, z1i);
        fprintf('z2 = %g + %g * j\n\n', z2r, z2i);  
    end
    
    x = roots([a b c])
    
    fprintf('Doriti reluarea programului? 0 = nu, 1 = da\n');
    rel = input('Reluare? ');
end
