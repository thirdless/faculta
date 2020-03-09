package sample;

import java.io.*;

public class P1{

    public static void main(String[] args) throws IOException
    {
        Complex temp1 = new Complex(2, 3);
        Complex temp2 = new Complex(3, 4);
        Complex temp3 = temp1.adunare(temp2);
        temp3 = temp1.putere(2);
        Complex temp4 = temp1.inmultire(temp1);
        temp3.afisare();
        temp4.afisare();
    }
}
