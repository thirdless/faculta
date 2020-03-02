package sample;

import java.io.*;

public class Main7{
    public static void main(String[] args) throws IOException
    {
        String buf = "";
        int c;
        FileReader f = null; //specificatorul pentru fisier
        try { //se utilizeaza pentru a prinde exceptiile de eroare la deschiderea fisierului
            f = new FileReader("fisier.in");
            while ((c = f.read()) != -1) //cat timp se mai pot citi caractere din fisier
            {
                buf = buf + (char)c;//se citesc caracterele din fisier si se pun in buf
            }
            System.out.print(buf);
            f.close(); // se inchide fisierul
        }
        catch (FileNotFoundException e) { // exceptie : nu s-a gasit fisierul
            System.out.println("Fisierul nu a fost gasit");
        }
        catch (IOException e) //eroare la citirea din fisier
        {
            System.out.println("Eroare la citire");
        }
    }
}
