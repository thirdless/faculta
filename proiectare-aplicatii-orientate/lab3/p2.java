package sample;

import java.io.*;

public class Main1{
    public static void main(String[] args) throws IOException
    {
        InputStreamReader reader = new InputStreamReader(System.in);
        BufferedReader buffer = new BufferedReader(reader);

        String s1 = buffer.readLine();
        String s2 = buffer.readLine();

        s1 = s1.replace(s2, " * ");
        System.out.print(s1);
    }
}
