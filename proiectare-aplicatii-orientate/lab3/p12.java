package sample;

import java.io.*;
import java.lang.*;

public class Main10{
    public static void main(String[] args) throws IOException
    {
        String buf = "";
        int c;
        int nra = 0;
        int nre = 0;
        int nri = 0;
        int nro = 0;
        int nru = 0;
        int max;
        char temp = '0';

        FileReader f = null; //specificatorul pentru fisier
        try { //se utilizeaza pentru a prinde exceptiile de eroare la deschiderea fisierului
            f = new FileReader("fisier1.in");
            while ((c = f.read()) != -1) //cat timp se mai pot citi caractere din fisier
            {
                buf = buf + (char)c;//se citesc caracterele din fisier si se pun in buf
            }

            buf = buf.toLowerCase();

            for(int i = 0; i < buf.length(); i++){
                if(buf.charAt(i) == 'a') nra++;
                else if(buf.charAt(i) == 'e') nre++;
                else if(buf.charAt(i) == 'i') nri++;
                else if(buf.charAt(i) == 'o') nro++;
                else if(buf.charAt(i) == 'u') nru++;
            }

            max = Math.max(nra, Math.max(nre, Math.max(nri, Math.max(nro, nru))));

            if(nra >= nre && nra >= nri && nra >= nro && nra >= nru) temp = 'A';
            else if(nre >= nra && nre >= nri && nre >= nro && nre >= nru) temp = 'E';
            else if(nri >= nre && nri >= nra && nri >= nro && nri >= nru) temp = 'I';
            else if(nro >= nre && nro >= nri && nro >= nra && nro >= nru) temp = 'O';
            else if(nru >= nre && nru >= nri && nru >= nro && nru >= nra) temp = 'U';

            System.out.print("Cea mai folosita vocala este " + temp + " de " + max + " ori");

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
