import java.util.concurrent.*;

public class ProducerTask implements Runnable {
    ArrayBlockingQueue<Integer> queue;
    public ProducerTask(ArrayBlockingQueue<Integer> param) {
        queue = param;
    }

    @Override
    public void run() {
        try {
            for (int i = 0; i < 10; i++) {
                queue.put(i);
                System.out.println("Numar scris: " + i);
                Thread.sleep((long)(Math.random() * 1000));
            }
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}

