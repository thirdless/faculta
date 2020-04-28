import java.util.concurrent.*;

public class Main {
    public static void main(String[] args) {
        Buffer buffer = new Buffer();
        ExecutorService executor = Executors.newFixedThreadPool(2);
        executor.execute(new ProducerTask(buffer, 10));
        executor.execute(new ConsumerTask(buffer, 6));
        executor.shutdown();

    }
}
