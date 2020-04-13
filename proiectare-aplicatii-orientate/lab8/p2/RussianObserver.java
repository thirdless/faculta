import java.util.Map;

public class RussianObserver implements Observer {
    protected MessageSet subject;

    Map<String, String> dictionary = Map.of(
            "Nastya", "У насти",
            "are", "есть",
            "struguri", "виноград",
            "mere", "яблоки",
            "Anna", "Анна"
    );

    RussianObserver(MessageSet subject)
    {
        this.subject = subject;
        this.subject.attach(this);
    }

    public void update()
    {
        System.out.print("\nMesajul tradus in Rusa\n");
        String[] words;
        String msg = subject.getState();
        words = msg.split(" ");
        for(int i = 0; i < words.length; i++)
        {
            if(dictionary.get(words[i]) != null) System.out.print(dictionary.get(words[i]) + " ");
            else System.out.print(words[i] + " ");
        }
        System.out.println("");
    }
}