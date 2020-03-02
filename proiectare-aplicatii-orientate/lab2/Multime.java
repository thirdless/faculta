package com.company;

import java.io.*;
import java.util.Scanner;

public class Multime {

    public int n;
    public int []v;

    public Multime()
    {
        n=0;
        v=new int[100];
    }

    public Multime(int m)
    {
        Scanner scan=new Scanner(System.in);

        n=m;

        v=new int[n];

        for(int i=0;i<n;++i)
        {
            v[i]=scan.nextInt();
        }
    }


    public void append(int val)
    {
        int ok=0;
        for(int i=0;i<n;++i) {
            if (val == v[i]) {
                ok = 1;
            }
        }
        if(ok==0) {
            v[n] = val;
            ++this.n;
        }
    }

    public void afisare()
    {
        for(int i=0;i<n;++i)
        {
            System.out.print(v[i] + " ");
        }
        System.out.println();
    }
}
