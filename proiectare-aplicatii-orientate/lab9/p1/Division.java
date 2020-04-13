import java.util.ArrayList;

public class Division implements Tag {

    ArrayList<Tag> children = new ArrayList<Tag>();
    String text;

    public Division(String text){
        this.text = text;
    }

    @Override
    public String toString() {
        String temp = "<div>\n";
        for(int i = 0; i < children.size(); i++){
            temp += (children.get(i)).toString() + "\n";
        }
        temp += text + "</div>";
        return temp;
    }

    public void afisare(){
        System.out.println(toString());
    }

    public void addTag(Tag tag){
        children.add(tag);
    }
}
