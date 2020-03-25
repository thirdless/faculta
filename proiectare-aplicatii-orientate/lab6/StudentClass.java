package com.company;

class StudentClass{
    private final int N = 10;
    private int n;
    private Student[] v;
    private Consultant[] c;

    public StudentClass(){
        v = new Student[N];
        n = 0;
    }

    public StudentClass(int n){
        v = new Student[n];
        this.n = 0;
    }

    public void Add(Student s){
        for(int i = 0; i < v.length; i++){
            if(v[i] == null){
                v[i] = s.clone();
                break;
            }
        }
    }

    public void Add(Consultant[] c){
        this.c = c;
    }

    public void Print(){
        for(int i = 0; i < n; i++){
            System.out.print(v[i].toString() + "\n");
        }
    }

    public void Sort() {
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (v[j].compareTo(v[j + 1], 0) < 0) {
                    Student aux = v[j];
                    v[j] = v[j + 1];
                    v[j + 1] = aux;
                }
            }
        }
    }

    public int Getn(){
        return n;
    }

    public void ExecuteOrder(Consultant c){
        c.ExecuteOrder66(v);
    }

}