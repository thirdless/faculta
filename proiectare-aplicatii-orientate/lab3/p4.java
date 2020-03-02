package sample;

import java.io.*;

public class Main3{
    public static void main(String[] args) throws IOException
    {
        InputStreamReader reader = new InputStreamReader(System.in);
        BufferedReader buffer = new BufferedReader(reader);
        int carry = 0;

        String s1 = buffer.readLine();
        char[] temp = s1.toCharArray();

        temp[0] = Character.toUpperCase(temp[0]);

        for(int i = 1; i < s1.length(); i++){
            if(carry == 1) temp[i] = Character.toUpperCase(temp[i]);

            if(temp[i] == ' ') carry = 1;
            else carry = 0;
        }

        s1 = String.valueOf(temp);
        System.out.print(s1);
    }
}
