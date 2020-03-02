package com.company;

public class Prob4 {
    Prob1 obj;

    public Prob4(int n)
    {
        obj=new Prob1(n);
    }

    public boolean ifSort()
    {
        for(int i=0;i<obj.n-1;++i)
        {
            if(obj.v[i]>obj.v[i+1])
            {
                return false;
            }
        }

        return true;
    }
}
