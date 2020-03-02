package sample;

import java.io.*;

public class Main5{
    public static void main(String[] args) throws IOException
    {
        InputStreamReader reader = new InputStreamReader(System.in);
        BufferedReader buffer = new BufferedReader(reader);

        String s1 = buffer.readLine();
        s1 = s1.toLowerCase();
        char[] temp = s1.toCharArray();

        for(int i = 0; i < s1.length(); i++){
            if(s1.charAt(i) != 'a' && s1.charAt(i) != 'e' && s1.charAt(i) != 'i' && s1.charAt(i) != 'o' && s1.charAt(i) != 'u'){
                temp[i] = Character.toUpperCase(temp[i]);
            }
        }

        s1 = String.valueOf(temp);
        System.out.print(s1);
    }
}
