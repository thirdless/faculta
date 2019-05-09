function ye = INTPL( ni,xi,yi,mg,xe )

    i = 1;
    while(i <= ni && xe > xi(i))
        i = i + 1;
    end
    indmax = fix(i+mg/2);
    if(indmax <= mg)
        indmax = mg + i;
    end
    if(indmax > ni)
       indmax = ni; 
    end
    indmin = indmax - mg;
    a = 1;
    for( i = indmin : indmax)
       if(xe == xi(i))
            ye = yi(i);
            return
       end
       a = a * (xe - xi(i));
    end
    ye = 0;
    for(i = indmin : indmax)
       PL = yi(i) * a / (xe - xi(i));
       for(j = indmin:indmax)
          if(i ~= j)
             PL = PL / (xi(i) - xi(j)); 
          end
       end
       ye = ye + PL;
    end

end

