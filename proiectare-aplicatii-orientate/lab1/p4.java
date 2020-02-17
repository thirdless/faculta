package com.company;

import java.io.*;
import java.lang.Math;

public class P4 {

    public static void main(String[] args) throws IOException {
        InputStreamReader reader = new InputStreamReader(System.in);
        BufferedReader buffer = new BufferedReader(reader);
        System.out.println("x: ");
        String s1 = buffer.readLine();
        System.out.println("y: ");
        String s2 = buffer.readLine();
        double i1, i2;
        i1 = Integer.parseInt(s1);
        i2 = Integer.parseInt(s2);

        if(i1 > 0){
            if(i2 > 0) System.out.println("\nCadranul 1");
            else if(i2 < 0) System.out.println("\nCadranul 4");
            else if(i2 == 0) System.out.println("\nCadranul 1-4");
        }
        else if(i1 < 0){
            if(i2 > 0) System.out.println("\nCadranul 2");
            else if(i2 < 0) System.out.println("\nCadranul 3");
            else if(i2 == 0) System.out.println("\nCadranul 2-3");
        }
        else if(i1 == 0){
            if(i2 > 0) System.out.println("\nCadranul 1-2");
            else if(i2 < 0) System.out.println("\nCadranul 3-4");
            else if(i2 == 0) System.out.println("\nOrigine");
        }
    }
}
