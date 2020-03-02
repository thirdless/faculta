package sample;

import java.io.*;

public class Main{
    public static void main(String[] args) throws IOException
    {
        String ceva1 = "LOL Ceva HAAH Ceva Ceva LOL Ceva";
        String ceva2 = "Ceva";
        int numar = 0;

        while(true){
            if(ceva1.indexOf(ceva2) == -1) break;

            numar++;
            ceva1 = ceva1.replaceFirst(ceva2, "");
        }

        System.out.print("A aparut de " + numar + " ori");
    }
}
