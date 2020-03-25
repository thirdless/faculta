package com.company;

public class ConsultantPrint implements Consultant {

    @Override
    public void ExecuteOrder66(Student[] v){
        for(Student i : v){
            System.out.print(i.toString());
        }
    }
}
