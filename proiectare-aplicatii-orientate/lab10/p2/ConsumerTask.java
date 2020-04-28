import java.util.concurrent.ArrayBlockingQueue;

public class ConsumerTask implements Runnable {
    ArrayBlockingQueue<Integer> queue;
    public ConsumerTask(ArrayBlockingQueue<Integer> param) {
        queue = param;
    }

    @Override
    public void run() {
        try {
            int val = 0;
            for (int i = 0; i < 10; i++) {
                val = queue.take();
                System.out.println("Numar citit: " + val);
                Thread.sleep((long)(Math.random() * 1000));
            }
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}

