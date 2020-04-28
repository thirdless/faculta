public class ProducerTask implements Runnable{
    private Buffer buffer;
    private int num;

    public ProducerTask(Buffer buffer, int num){
        this.buffer = buffer;
        this.num = num;
    }

    public void run(){
        try{
            for(int i = 0; i < num; i++){
                buffer.write(i);
                System.out.println("Scris: " + i);
                Thread.sleep((long)(Math.random() * 1000));
            }
        } catch(InterruptedException e){
            e.printStackTrace();
        }
    }
}