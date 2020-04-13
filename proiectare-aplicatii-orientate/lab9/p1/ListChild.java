import java.util.ArrayList;

public class ListChild implements Tag {

    ArrayList<Tag> children = new ArrayList<Tag>();
    String text;

    public ListChild(String text){
        this.text = text;
    }

    @Override
    public String toString() {
        String temp = "<li>\n";
        for(int i = 0; i < children.size(); i++){
            temp += (children.get(i)).toString() + "\n";
        }
        temp += text + "\n</li>";
        return temp;
    }

    public void addTag(Tag tag){
        children.add(tag);
    }

    public void afisare(){
        System.out.println(toString());
    }
}
