package com.company;

public class Prob7 {

    Tablou obj;

    public Prob7(int n,int m)
    {
        obj=new Tablou(n,m);
    }

    public int suma()
    {
        int s=0;

        for(int i=0;i<obj.n;++i)
        {
            s+=obj.t[i][0];
            s+=obj.t[i][obj.m-1];
        }

        for(int i=1;i<obj.m-1;++i) {
            s+=obj.t[0][i];
            s+=obj.t[obj.n-1][i];
        }

        return s;
    }

}
