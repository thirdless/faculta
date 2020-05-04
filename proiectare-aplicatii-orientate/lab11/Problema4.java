class Random{
    int[] array;
    Random(){
        array = new int[50];
        for(int i = 0; i < 50; i++){
            array[i] = (int)(Math.random() * 10000);
        }
    }

    int get(int pos) throws ArrayIndexOutOfBoundsException{
        return array[pos];
    }
}

public class Problema4 {
    public static void main(String[] arg){
        Random random = new Random();
        try{
            System.out.println(random.get(20));
            System.out.println(random.get(55));
        } catch(ArrayIndexOutOfBoundsException e){
            System.out.println("Pozitie invalida");
        }
    }
}