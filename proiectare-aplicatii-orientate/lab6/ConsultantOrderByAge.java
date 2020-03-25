package com.company;

public class ConsultantOrderByAge implements Consultant{
    @Override
    public void ExecuteOrder66(Student[] v) {
        for(int i = 0; i < v.length - 1; i++){
            for(int j = i + 1; j < v.length; j++){
                if(v[i].compareTo(v[j], 2) > 0){
                    Student aux = v[i].clone();
                    v[i] = v[j].clone();
                    v[j] = aux.clone();
                }
            }
        }
    }
}
