package com.company;

public abstract class AbstractMotoare{
    public abstract void operatiaM1();
    public abstract void operatiaM2();
}

class Motoare1 extends AbstractMotoare{
    Motoare1(String arg){
        System.out.println("Model motor1: " + arg);
    }

    public void operatiaM1(){
        System.out.println("m1");
    }

    public void operatiaM2(){
        System.out.println("m2");
    }
}

class Motoare2 extends AbstractMotoare{
    Motoare2(String arg){
        System.out.println("Model motor2: " + arg);
    }

    public void operatiaM1(){

    }

    public void operatiaM2(){


    }
}