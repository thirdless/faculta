import java.util.ArrayList;

public class HTML {
    ArrayList<Decorator> children = new ArrayList<Decorator>();
    String title = "";

    public void setTitle(String title){
        this.title = title;
    }

    public void add(Decorator param){
        children.add(param);
    }

    @Override
    public String toString() {
        String temp = "<html>\n<title>" + title + "</title>\n<body>\n";
        for(int i = 0; i < children.size(); i++){
            temp += "\t" + (children.get(i)).toString() + " <br> \n";
        }
        return temp + "</body>\n</html>";
    }
}
