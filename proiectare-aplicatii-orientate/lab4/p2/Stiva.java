package sample;


public class Stiva {
    private final int MAX = 100;
    private int[] stiva;
    private int index = -1;
    private int dim;

    Stiva(){
        stiva = new int[MAX];
        dim = MAX;
    }

    Stiva(int dim){
        stiva = new int[dim];
        this.dim = dim;
    }

    public void Push(int param){
        if(index != dim){
            index++;
            stiva[index] = param;
        }
    }

    public int Pop(){
        if(index != -1){
            int temp;
            temp = stiva[index];
            index--;
            return temp;
        }
        return -1;
    }

    public boolean isEmpty(){
        if(index == -1) return true;
        else return false;
    }
}
