public class Main {
    public static void main(String[] arg){

        HTML html = new HTML();
        html.setTitle("Ceva");

        html.addTag(new Paragraph("ceva text din paragraf"));
        html.addTag(new Paragraph("ceva text din paragraf 2"));
        html.addTag(new Division(""));

        Division div = new Division("");
        div.addTag(new Paragraph("lol"));
        List list = new List();
        list.addTag(new ListChild("something something"));
        ListChild child = new ListChild("");
        child.addTag(new Paragraph("list paragraph"));
        list.addTag(child);
        html.addTag(list);
        html.addTag(div);


        System.out.print(html.toString());
    }
}
