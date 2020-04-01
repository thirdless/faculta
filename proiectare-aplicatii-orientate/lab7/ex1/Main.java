package com.company;

class FactoryMaker{
    private static AbstractFactory pfactory = null;

    static AbstractFactory getFactory(String opt){
        if(opt.equals("a")){
            pfactory = new Fabrica1();
        }
        else if(opt.equals("b")){
            pfactory = new Fabrica2();
        }
        return pfactory;
    }
}

public class Main {

    public static void main(String[] args) {
        AbstractFactory pf[] = {
                FactoryMaker.getFactory("a"),
                FactoryMaker.getFactory("a"),
                FactoryMaker.getFactory("b")

        };

        for(int i = 0; i < 3; i++){
            pf[i].CreeazaMotor();
            pf[i].CreeazaCaroserie();
        }
    }
}
