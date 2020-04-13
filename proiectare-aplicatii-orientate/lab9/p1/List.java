import java.util.ArrayList;

public class List implements Tag {

    ArrayList<Tag> children = new ArrayList<Tag>();

    @Override
    public String toString() {
        String temp = "<ul>\n";
        for(int i = 0; i < children.size(); i++){
            temp += (children.get(i)).toString() + "\n";
        }
        temp += "</ul>";
        return temp;
    }

    public void afisare(){
        System.out.println(toString());
    }

    public void addTag(Tag tag){
        children.add(tag);
    }
}
