import java.util.Scanner;

public class MainMenu {
    public static void main(String[] args){
        DataBase db = new DataBase();
        int param;
        Scanner scanner = new Scanner(System.in);
        System.out.println("1 - add;");
        System.out.println("2 - delete;");
        System.out.println("3 - update;");
        System.out.println("4 - sort by rating desc;");
        System.out.println("5 - show table;");
        System.out.println("0 - terminate execution");
        while(true){
            System.out.print("\nIntroduceti comanda dorita: ");

            param = Integer.parseInt(scanner.nextLine());
            switch(param){
                case 1:
                    db.add();
                    break;
                case 2:
                    db.delete();
                    break;
                case 3:
                    db.change();
                    break;
                case 4:
                    db.sort();
                    break;
                case 5:
                    db.show();
                    break;
                case 0:
                    db.disc();
                    System.exit(0);
                    break;
            }
        }
    }
}
