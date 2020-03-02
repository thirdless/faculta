package sample;

import java.io.*;

public class Main4{
    public static void main(String[] args) throws IOException
    {
        int numar = 0;

        InputStreamReader reader = new InputStreamReader(System.in);
        BufferedReader buffer = new BufferedReader(reader);

        String s1 = buffer.readLine();

        for(int i = 0; i < s1.length(); i++){
            if(s1.charAt(i) == 'a' || s1.charAt(i) == 'e' || s1.charAt(i) == 'i' || s1.charAt(i) == 'o' || s1.charAt(i) == 'u') numar++;
        }

        System.out.print("Sunt prezente " + numar + " vocale in propozitie");
    }
}
