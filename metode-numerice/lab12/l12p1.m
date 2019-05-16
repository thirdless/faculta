hi=input('hi= ');
xi=0:hi:4*pi;
yi=sin(xi);

pp=splinen(xi,yi);
[x,c,l,g]=unmkpp(pp);

AI=c(:,1);
BI=c(:,2);
CI=c(:,3);
DI=c(:,4);

he=input('he= ');
while(he<=0 && hi>he)
    fprintf('Variabila he nu se incadreaza \n');
    he=input('he= ');
end

xe=0:he:4*pi;
ye=ppval(pp,xe);

cd1=[3*AI 2*BI CI];
ppd1=mkpp(xi,cd1);
d1e=ppval(ppd1,xe);

cd2=[6*AI 2*BI];
ppd2=mkpp(xi,cd2);
d2e=ppval(ppd2,xe);

aq=input('aq= ');
bq=input('bq= ');

while(aq<=0 && bq>aq && bq>=4*pi)
    fprintf('Variabilele nu se incadreaza \n');
    aq=input('aq= ');
    bq=input('bq= ');
end

k=0;
P=1;
while(P>0)
    k=k+1;
    P=(aq-xi(k))*(aq-xi(k+1));
end

ia=k;
k=0;
P=1;
while(P>0)
    k=k+1;
    P=(bq-xi(k))*(bq-xi(k+1));
end
ib=k;
dx=aq-xi(ia);
if(dx~=0)
    cq=[(1/4)*AI(ia) (1/3)*BI(ia) (1/2)*CI(ia) DI(ia) 0];
    qma=polyval(cq,dx);
else
    qma=0;
end

nq=ib-ia;
ind=ia-1;
qs=0;

for(iq=1:nq)
    ind=ind+1;
    dx=xi(ind+1)-xi(ind)
    cq=[(1/4)*AI(ind) (1/3)*BI(ind) (1/2)*CI(ind) DI(ind) 0];
    qs=qs+polyval(cq,dx);
end

dx=bq-xi(ib);
if(dx~=0)
    cq=[(1/4)*AI(ib) (1/3)*BI(ib) (1/2)*CI(ib) DI(ib) 0];
    qpb=polyval(cq,dx);
else
    qpb=0;
end

q=qs+qpb-qma;
qc=cos(aq)-cos(bq);
qc

plot(xi,yi,'o',xe,ye,'-',xe,d1e,'--',xe,d2e,':',[aq aq],[-1.25 1.25],'-.',[bq bq],[-1.25 1.25],'-.');
xlabel('xi, xe');
title(['yi:o ye:- d1:--d2:...',num2str(q)]);

yye=sin(xe);
err=norm(ye-yye)^2/(length(ye)-1);

plot(xi,yye,'o');

err
