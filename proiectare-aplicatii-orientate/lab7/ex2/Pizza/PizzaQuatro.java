package com.company.Pizza;

public class PizzaQuatro extends Pizza {
    public PizzaQuatro(int size, int price){
        this.size = size;
        this.price = price;
    }

    @Override
    public String toString() {
        return "Pizza Quatro Stagioni cu " + super.toString();
    }
}
