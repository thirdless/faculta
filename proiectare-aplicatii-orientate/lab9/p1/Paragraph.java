import java.util.ArrayList;

public class Paragraph implements Tag {

    String text;

    public Paragraph(String text){
        this.text = text;
    }

    @Override
    public String toString() {
        return "<p>" + text + "</p>";
    }

    @Override
    public void afisare() {
        System.out.println(toString());
    }
}
