import java.util.concurrent.TimeUnit;

public class Download {
    private static Download instance = null;
    private File[] queue;
    private int n;
    private final int speed = 1;

    private Download(){
        n = 0;
        queue = new File[1024];
    }

    public static Download GetInstance(){
        if(instance == null) instance = new Download();
        return instance;
    }

    public static void Reset(){
        instance = null;
    }

    public void Start(File param) throws InterruptedException{
        queue[n++] = param;
        System.out.println("Starting " + param.name + " with size " + param.size + "MB with speed of " + speed + "Mbps");
        TimeUnit.SECONDS.sleep(param.size * speed);
        queue[n--] = null;
    }
}
