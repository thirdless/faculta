package com.company;

public class Prob5 {

    Multime obj1;
    Multime obj2=new Multime();

    public Prob5(int n)
    {
        obj1=new Multime(n);
    }

    public void copiere()
    {
        for(int i=0;i<obj1.n;++i)
        {
            if(obj1.v[i]>0)
            {
                obj2.append(obj1.v[i]);
            }
        }
    }

    public void afisare()
    {
        obj2.afisare();
    }
}
