package sample;

import java.io.*;

public class Matrix {

    int[][] matrice;
    int dim;

    Matrix() throws IOException {
        InputStreamReader reader = new InputStreamReader(System.in);
        BufferedReader buffer = new BufferedReader(reader);
        System.out.print("Dimensiunea matricii: ");
        String s1 = buffer.readLine();
        dim = Integer.parseInt(s1);

        matrice = new int[dim][dim];

        for(int i = 0; i < dim; i++){
            for(int j = 0; j < dim; j++){
                System.out.print("Matrice[" + i + "][" + j + "] = ");
                String temp = buffer.readLine();
                matrice[i][j] = Integer.parseInt(temp);
            }
            System.out.print("\n");
        }
    }

    public void adunare(Matrix param){
        Matrix temp1;
        Matrix temp2;
        int temp;

        if(param.dim > dim){
            temp1 = param;
            temp2 = this;
            temp = param.dim;
        }
        else{
            temp1 = this;
            temp2 = param;
            temp = dim;
        }

        for(int i = 0; i < temp; i++){
            for(int j = 0; j < temp; j++) {
                temp1.matrice[i][j] += temp2.matrice[i][j];
            }
        }

        this.matrice = temp1.matrice;
    }

    public void inmultire(Matrix param){
        if(dim == param.dim){
            int[][] temp;
            temp = new int[dim][dim];

            for(int i = 0; i < dim; i++){
                for(int j = 0; j < dim; j++) {
                    for(int k = 0; k < dim; k++){
                        temp[i][j] += this.matrice[i][k] * param.matrice[k][j];
                    }
                }
            }

            this.matrice = temp;
        }
    }

    @Override
    public String toString() {
        String temp = "";
        for(int i = 0; i < dim; i++){
            for(int j = 0; j < dim; j++){
                temp += matrice[i][j] + " ";
            }
            temp += "\n";
        }
        return temp;
    }
}
