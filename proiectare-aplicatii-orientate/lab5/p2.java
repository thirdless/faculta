package com.company;

import java.util.*;

class SortedVector extends Vector{

    public void addElement(Object param){
        super.add(param);
        Collections.sort(this);
    }

    public void insertElementAt(Object param, int index){
        super.insertElementAt(param, index);
        Collections.sort(this);
    }

}

public class P2 {

    public static void main(String[] args) {
        SortedVector ceva = new SortedVector();
        ceva.addElement(1);
        System.out.println(ceva.toString());
        ceva.addElement(5);
        System.out.println(ceva.toString());
        ceva.addElement(3);
        System.out.println(ceva.toString());
        ceva.insertElementAt(69, 1);
        System.out.println(ceva.toString());
    }

}
