package com.company;

abstract class AbstractCaroserie{
    public abstract void operatiaC1();
    public abstract void operatiaC2();
}

class Caroserie1 extends AbstractCaroserie{
    Caroserie1(String arg){
        System.out.println("Model caroserie1:" + arg);
    }

    public void operatiaC1(){

    }

    public void operatiaC2(){

    }
}

class Caroserie2 extends AbstractCaroserie{
    Caroserie2(String arg){
        System.out.println("Model caroserie2:" + arg);
    }

    public void operatiaC1(){
        System.out.println("c1");
    }

    public void operatiaC2(){
        System.out.println("c2");
    }
}