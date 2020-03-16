package com.company;

import java.util.Vector;

class SetAsVector1{
    Vector obiect;

    SetAsVector1(){
        obiect = new Vector();
    }

    public boolean add(Object param){
        return obiect.add(param);
    }

    public boolean remove(Object param){
        return obiect.remove(param);
    }

    public boolean contains(Object param){
        return obiect.contains(param);
    }

    public String toString(){
        return obiect.toString();
    }

}


public class P1v1 {

    public static void main(String[] args) {
        SetAsVector1 lol = new SetAsVector1();
        lol.add(3);
        System.out.print(lol.toString());
        lol.remove(0);
        System.out.print(lol.toString());
    }

}
