package sample;

import java.io.*;

public class Main6{
    public static void main(String[] args) throws IOException
    {
        InputStreamReader reader = new InputStreamReader(System.in);
        BufferedReader buffer = new BufferedReader(reader);
        char temp1;
        String temp;

        String s1 = buffer.readLine();
        String s2 = buffer.readLine();

        s1 = s1.toLowerCase();
        s2 = s2.toLowerCase();

        s1 = s1.replace(" ", "");
        s2 = s2.replace(" ", "");

        if(s1.length() != s2.length()) System.out.print("Cuvintele NU sunt anagrame!");
        else{
            while(s1.length() != 0){
                temp1 = s1.charAt(0);
                temp = String.valueOf(temp1);
                s1 = s1.replaceFirst(temp, "");
                s2 = s2.replaceFirst(temp, "");
            }
            if(s2.length() != 0) System.out.print("Cuvintele NU sunt anagrame!");
            else System.out.print("Cuvintele sunt anagrame!");
        }
    }
}
