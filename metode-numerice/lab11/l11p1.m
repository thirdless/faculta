rel = 1;
while(rel == 1)
    set = input('pt. set 1: 1; pt. set 2: 2\n');
    if(set == 1)

        ni = 7;

        xi=[-1,-0.96,-0.86,-0.79,0.22,0.5,0.93];
        yi=[-1,-0.151,0.894,0.986,0.895,0.5,-0.306];
        
        heval=0.05;
        
        xe = (xi(1):heval:xi(ni))';
        npev = length(xe);
        if(xe(npev)<xi(ni))
            npev=npev+1;
            xe=[xe;xi(ni)];
        end
        
        npev
        
        mg = input('mg= ');
        
         ye=zeros(npev,1);
        for ip=1:npev
            ye(ip)=INTPL(ni,xi,yi,mg,xe(ip));
            xe(ip)
            ye(ip)
        end
        
         plot(xi,yi,'or',xe,ye,'-b');
         
    else
        
        ni = 10;
        xi=[3,5.4,8.8,12.2,14,17.8,20.6,21.3,23.6,26];
        yi=[1540,1535,1530,1525,1520,1515,1510,1505,1500,1495];
        
        heval=0.5;
        
        xe = (xi(1):heval:xi(ni))';
        npev = length(xe);
        if(xe(npev)<xi(ni))
            npev=npev+1;
            xe=[xe;xi(ni)];
        end
        
        npev
        
        mg = input('mg= ');
        
         ye=zeros(npev,1);
        for ip=1:npev
            ye(ip)=INTPL(ni,xi,yi,mg,xe(ip));
            xe(ip)
            ye(ip)
        end
       
        n = 1;
        p=polyfit(xi,yi,n);
       
        yn=polyval(p,xe);
        
        plot(xi,yi,'or',xe,ye,'-b',xe,yn,'-g');
        
        
    end
    rel = input('pt reluare 1. pt iesire 0\n');
end

           
     
        
        
