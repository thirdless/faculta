public class Main {

    public static void main(String[] arg) throws InterruptedException{
        Download.GetInstance().Start(new File("fisier1.txt", 13));
        Download.GetInstance().Start(new File("fisier2.txt", 6));
    }

}
