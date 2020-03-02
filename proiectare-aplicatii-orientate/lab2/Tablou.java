package com.company;

import java.io.*;
import java.util.Scanner;

public class Tablou {
    int n,m;
    int [][] t;

    public Tablou()
    {
        Scanner scan=new Scanner(System.in);

        n=scan.nextInt();
        m=scan.nextInt();

        t=new int [n][m];

        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)
            {
                t[i][j]=scan.nextInt();
            }
        }
    }

    public Tablou(int n,int m)
    {
        this.n=n;
        this.m=m;

        t=new int [n][m];

        Scanner scan=new Scanner(System.in);

        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)
            {
                t[i][j]=scan.nextInt();
            }
        }
    }


}
