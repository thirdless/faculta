public class ConsumerTask implements Runnable{
    private Buffer buffer;
    private int num;

    public ConsumerTask(Buffer buffer, int num){
        this.buffer = buffer;
        this.num = num;
    }

    public void run(){
        try{
            int temp = 0;
            for(int i = 0; i < num; i++){
                temp = buffer.read();
                System.out.println("Citit: " + temp);
                Thread.sleep((long)(Math.random() * 1000));
            }

        } catch(InterruptedException e){
            e.printStackTrace();
        }
    }
}