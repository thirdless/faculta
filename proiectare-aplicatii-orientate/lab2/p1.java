package com.company;

import java.io.*;
import java.util.Scanner;

public class Prob1 {
    int n;
    int[] v;

    public Prob1(int n)
    {
        Scanner scan=new Scanner(System.in);

        this.n=n;

        v=new int[this.n];

        for(int i=0;i<this.n;++i)
        {
            System.out.print("Inserati elementul " + i + " din vector: ");
            v[i]=scan.nextInt();
        }
    }

    public int Min()
    {
        int m;

        m=v[0];

        for(int i=1;i<this.n;++i)
        {
            if(m > v[i])
            {
                m=v[i];
            }
        }

        return m;
    }
}
