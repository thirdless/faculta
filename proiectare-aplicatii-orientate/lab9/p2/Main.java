import java.util.Scanner;

public class Main {

    public static void main(String[] arg){

        Scanner scanner = new Scanner(System.in);

        System.out.print("Cuvant ingrosat: ");
        String cuvant1 = scanner.nextLine();
        System.out.print("Cuvant inclinat: ");
        String cuvant2 = scanner.nextLine();
        System.out.print("Cuvant subliniat: ");
        String cuvant3 = scanner.nextLine();
        System.out.print("Cuvant subliniat si ingrosat: ");
        String cuvant4 = scanner.nextLine();
        System.out.print("Cuvant ingrosat, subliniat si inclinat: ");
        String cuvant5 = scanner.nextLine();

        HTML html = new HTML();
        html.setTitle("Titlu generic");
        html.add(new Bold(cuvant1));
        html.add(new Italic(cuvant2));
        html.add(new Underline(cuvant3));

        Decorator under = new Underline("");
        under.add(new Bold(cuvant4));
        html.add(under);

        Decorator bold = new Bold("");
        Decorator underline = new Underline("");
        underline.add(new Italic(cuvant5));
        bold.add(underline);
        html.add(bold);

        System.out.print(html);
    }

}
