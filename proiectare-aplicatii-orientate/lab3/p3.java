package sample;

import java.io.*;

public class Main2{
    public static void main(String[] args) throws IOException
    {
        InputStreamReader reader = new InputStreamReader(System.in);
        BufferedReader buffer = new BufferedReader(reader);
        char temp;

        String s1 = buffer.readLine();

        for(int i = 0; i < s1.length(); i++){
            temp = s1.charAt(i);
            if(temp == ' ') System.out.print("\n");
            else System.out.print(temp);
        }
    }
}
