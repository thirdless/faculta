package com.company;

import java.io.*;
import java.lang.Math;

public class P5 {

    public static void main(String[] args) throws IOException {
        InputStreamReader reader = new InputStreamReader(System.in);
        BufferedReader buffer = new BufferedReader(reader);
        System.out.println("Ora conectarii: ");
        String oc1 = buffer.readLine();
        int oc = Integer.parseInt(oc1);
        System.out.println("Minutul conectarii: ");
        String mc1 = buffer.readLine();
        int mc = Integer.parseInt(mc1);
        System.out.println("Secunda conectarii: ");
        String sc1 = buffer.readLine();
        int sc = Integer.parseInt(sc1);
        System.out.println("Ora deconectarii: ");
        String od1 = buffer.readLine();
        int od = Integer.parseInt(od1);
        System.out.println("Minutul deconectarii: ");
        String md1 = buffer.readLine();
        int md = Integer.parseInt(md1);
        System.out.println("Secunda deconectarii: ");
        String sd1 = buffer.readLine();
        int sd = Integer.parseInt(sd1);

        int cs = 0;
        int cm = 0;

        int ora, min, sec;

        if(oc < od || (oc == od && mc < md) || (oc == od && mc == md && sc < sd)) {
            ora = od - oc;
            min = md - mc;
            sec = sd - sc;
        }
        else{
            sec = (sc - sd) - 60;
            if(sec < 0) cs = 1;

            min = (mc - md) - 60;
            if(cs == 1) min += 1;
            if(min < 0) cm = 1;

            ora = 23 - (oc - od);
            if(cm == 1) ora += 1;
        };
        sec = Math.abs(sec);
        min = Math.abs(min);
        ora = Math.abs(ora);
        System.out.println("\nDurata: " + ora + " ore, " + min + " minute si " + sec + " secunde");
    }
}
