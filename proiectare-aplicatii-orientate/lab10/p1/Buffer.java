import java.util.LinkedList;
import java.util.concurrent.locks.Condition;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

public class Buffer {
    final Lock lock = new ReentrantLock();
    final Condition notFull  = lock.newCondition();
    final Condition notEmpty = lock.newCondition();

    final static int CAPACITY = 4;
    LinkedList<Integer> list = new LinkedList<>();
    int count = 0;

    public void write(int value) {
        lock.lock();
        try {
            while (CAPACITY == count) {
                System.out.println("Waiting to write");
                notFull.await();
            }
            list.offer(value);
            count++;
            notEmpty.signal();
        } catch(InterruptedException e){
            e.printStackTrace();
        } finally {
            lock.unlock();
        }
    }

    public int read() {
        lock.lock();
        try {
            while (count == 0){
                System.out.println("Waiting to read");
                notEmpty.await();
            }
            int temp = list.getFirst();
            list.remove();
            --count;
            notFull.signal();
            return temp;
        } catch(InterruptedException e){
            e.printStackTrace();
            return -1;
        } finally {
            lock.unlock();
        }
    }
}