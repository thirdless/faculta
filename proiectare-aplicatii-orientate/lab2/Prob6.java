package com.company;

import java.util.Scanner;
import java.lang.Math;

public class Prob6 {
    int []v;

    public Prob6(int n)
    {
        v=new int[n];

        Scanner scan=new Scanner(System.in);

        for(int i=0;i<n;++i)
        {
            v[i]=scan.nextInt();
        }
    }

    public int[] operatie()
    {
        int []vec=new int[v.length];

        for(int i=0; i<v.length; ++i)
        {
            vec[i] = v[i]*v[i];
        }

        return vec;
    }
}
