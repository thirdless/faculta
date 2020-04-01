package com.company;

abstract class AbstractFactory{
    abstract AbstractMotoare CreeazaMotor();
    abstract AbstractCaroserie CreeazaCaroserie();
}

class Fabrica1 extends AbstractFactory{
    AbstractMotoare CreeazaMotor(){
        return new Motoare1("MotorBenzina ");
    }

    AbstractCaroserie CreeazaCaroserie(){
        return new Caroserie1("MasinaTeren ");
    }
}

class Fabrica2 extends AbstractFactory{
    AbstractMotoare CreeazaMotor(){
        return new Motoare2("MotorJet ");
    }

    AbstractCaroserie CreeazaCaroserie(){
        return new Caroserie2("Avion ");
    }
}