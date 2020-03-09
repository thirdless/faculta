package sample;

import java.io.*;

public class P2{

    public static void main(String[] args) throws IOException
    {
        Stiva lol = new Stiva();
        lol.Push(3);
        lol.Push(2);
        int temp = lol.Pop();
        System.out.print(temp);
    }
}
