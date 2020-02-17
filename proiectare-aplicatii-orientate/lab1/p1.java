package com.company;

import java.io.*;
import java.lang.Math;

public class Main {

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
        double p = (i1 + i2 + i3) / 2,
            a = Math.sqrt(p * (p - i1) * (p - i2) * (p - i3));
        System.out.println("Rezultatul este " + a);
    }
}
