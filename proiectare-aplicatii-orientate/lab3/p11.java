package sample;

import java.io.*;

public class Main10{
    public static void main(String[] args) throws IOException
    {
        String buf = "";
        int c;
        char[] temp;

        FileReader f = null; //specificatorul pentru fisier
        try { //se utilizeaza pentru a prinde exceptiile de eroare la deschiderea fisierului
            f = new FileReader("fisier1.in");
            while ((c = f.read()) != -1) //cat timp se mai pot citi caractere din fisier
            {
                buf = buf + (char)c;//se citesc caracterele din fisier si se pun in buf
            }

            temp = buf.toCharArray();

            for(int i = 0; i < temp.length; i++){
                if(temp[i] <= 'Z' && temp[i] >= 'A') temp[i] += 32;
                else if(temp[i] <= 'z' && temp[i] >= 'a') temp[i] -= 32;
            }

            buf = String.valueOf(temp);

            FileWriter fr = null;
            try//se utilizeaza pentru a prinde exceptiile de eroare la deschiderea fisierului
            {
                fr = new FileWriter("fisier.out"); //fisier deschis pt a scrie
                fr.write(buf); //se scrie in fisier buf
                fr.close();
            }
            catch (IOException e) //eroare la scriere in fisier
            {
                System.out.println("Eroare la scriere");
            }


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
