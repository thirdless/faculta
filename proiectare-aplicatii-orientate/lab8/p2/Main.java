import java.util.LinkedList;
import java.util.List;

public class Main {

    public static void main(String[] args) {

        MessageSet subject = new MessageSet();
        new RussianObserver(subject);
        new EnglishObserver(subject);

        String s1 = "Nastya are struguri";
        String s2 = "Ana are mere";

        subject.setState(s1);
        subject.setState(s2);

    }
}
