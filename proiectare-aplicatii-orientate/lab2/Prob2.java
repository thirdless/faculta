package com.company;

import java.io.*;
import java.util.Scanner;

public class Prob2 {

    int n, m;

    Multime A, B;

    public Prob2(int n, int m)
    {
        this.n=n;
        this.m=m;

        A=new Multime(n);
        B=new Multime(m);
    }

    public Multime intersectie()
    {
        Multime C=new Multime();
        for(int i=0; i<n; ++i) {
            for (int j = 0; j <m ; ++j) {
                if(A.v[i]==B.v[j])
                {
                    C.append(A.v[i]);
                }
            }
        }
        return C;
    }
}
