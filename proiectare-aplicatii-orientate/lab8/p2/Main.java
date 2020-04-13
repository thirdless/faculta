import java.util.LinkedList;
import java.util.List;

public class Main {

    public static void main(String[] args) {
        MessageSet subject = new MessageSet();
        String  s1 = "Nastya are struguri",
                s2 = "Ana are mere";

        new RussianObserver(subject);
        new EnglishObserver(subject);

        subject.setState(s1);
        subject.setState(s2);
    }
}