package com.company;

import java.util.*;

class SetAsVector extends Vector{

    public boolean add(Object param){
        return super.add(param);
    }

    public boolean remove(Object param){
        return super.remove(param);
    }

    public boolean contains(Object param){
        return super.contains(param);
    }

    public String toString(){
        return super.toString();
    }

}

public class P1 {

    public static void main(String[] args) {
	    SetAsVector lol = new SetAsVector();
	    lol.add(1);
	    System.out.print(lol.toString());
        lol.remove(0);
        System.out.print(lol.toString());
    }
}
