import java.util.ArrayList;

public class HTML implements Tag {

    ArrayList<Tag> children = new ArrayList<Tag>();
    String title;

    @Override
    public String toString() {
        String temp = "<html>\n" + "<title>" + title + "</title>\n<body>\n";
        for(int i = 0; i < children.size(); i++){
            temp += (children.get(i)).toString() + "\n";
        }
        temp += "</body>\n</html>";
        return temp;
    }

    public void afisare(){
        System.out.println(toString());
    }

    public void setTitle(String title){
        this.title = title;
    }

    public void addTag(Tag tag){
        children.add(tag);
    }

}
