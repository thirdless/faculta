package com.company;

public class Prob3 {

    Prob2 obj;

    public Prob3(int n, int m)
    {
        obj=new Prob2(n,m);
    }

    public Multime diferenta()
    {
        Multime C= new Multime();
        for(int i=0;i<obj.n;++i)
        {
            for(int j=0;j<obj.m;++j)
            {
                if(obj.A.v[i] != obj.B.v[i])
                {
                    C.append(obj.A.v[i]);
                }
            }
        }

        return C;
    }
}
