package com.company;

import java.io.*;
import java.lang.Math;

public class P2 {

    public static void main(String[] args) throws IOException {
        InputStreamReader reader = new InputStreamReader(System.in);
        BufferedReader buffer = new BufferedReader(reader);
        String s1 = buffer.readLine();
        String s2 = buffer.readLine();
        String s3 = buffer.readLine();
        double i1, i2, i3;
        i1 = Double.parseDouble(s1);
        i2 = Double.parseDouble(s2);
        i3 = Double.parseDouble(s3);

        double i4 = Math.pow(i1, 2) + Math.pow(i2, 2),
               i5 = Math.pow(i2, 2) + Math.pow(i3, 2),
               i6 = Math.pow(i1, 2) + Math.pow(i3, 2);

        if(i1 <= 0 || i2 <= 0 || i3 <= 0) System.out.println("Laturile nu apartin unui triunghi");
        else{
            if(i1 == i2 && i2 == i3 && i3 == i1) System.out.println("Triunghiul este unul echilateral");
            else if(i1 == i2 || i2 == i3 || i3 == i1) System.out.println("Triunghiul este unul isoscel");
            else if(Math.pow(i3, 2) == i4 || Math.pow(i1, 2) == i5 || Math.pow(i2, 2) == i6) System.out.println("Triunghiul este unul dreptunghic");
            else System.out.println("Triunghiul este unul oarecare");
        }
    }
}
