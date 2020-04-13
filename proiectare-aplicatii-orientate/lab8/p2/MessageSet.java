import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;

public class MessageSet {
    List<String> text=new LinkedList<String>();
    List<Observer> observers=new ArrayList<Observer>();
    private String state="";
    public void attach(Observer observer)
    {
        observers.add(observer);
    }
    public void setState(String state)
    {
        this.state=state;
        text.add(state);
        notifyAllObservers();
    }
    public String getState()
    {
        return state;
    }
    public void notifyAllObservers(){
        for(Observer o:observers)
        {
            o.update();
        }
    }

}
