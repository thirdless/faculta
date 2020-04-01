package com.company.Pizza;

public class PizzaSalami extends Pizza {
    public PizzaSalami(int size, int price){
        this.size = size;
        this.price = price;
    }

    @Override
    public String toString() {
        return "Pizza Salami cu " + super.toString();
    }
}
