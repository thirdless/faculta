import java.util.concurrent.*;

public class Main {
    public static void main(String[] args) throws InterruptedException{
        ArrayBlockingQueue<Integer> list = new ArrayBlockingQueue<>(5);
        ExecutorService executor = Executors.newFixedThreadPool(2);
        executor.execute(new ProducerTask(list));
        executor.execute(new ConsumerTask(list));
        executor.shutdown();
    }
}
