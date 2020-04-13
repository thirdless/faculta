import java.util.ArrayList;

public class Italic implements Decorator {
    ArrayList<Decorator> children = new ArrayList<Decorator>();
    String text;

    Italic(String text){
        this.text = text;
    }

    public void add(Decorator param){
        children.add(param);
    }

    @Override
    public String toString() {
        String temp = "<i>" + text;
        for(int i = 0; i < children.size(); i++){
            temp += (children.get(i)).toString();
        }
        return temp + "</i>";
    }
}
