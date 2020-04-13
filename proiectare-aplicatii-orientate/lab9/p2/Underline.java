import java.util.ArrayList;

public class Underline implements Decorator {
    ArrayList<Decorator> children = new ArrayList<Decorator>();
    String text;

    Underline(String text){
        this.text = text;
    }

    public void add(Decorator param){
        children.add(param);
    }

    @Override
    public String toString() {
        String temp = "<u>" + text;
        for(int i = 0; i < children.size(); i++){
            temp += (children.get(i)).toString();
        }
        return temp + "</u>";
    }
}
