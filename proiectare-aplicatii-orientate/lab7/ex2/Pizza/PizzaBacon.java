package com.company.Pizza;

public class PizzaBacon extends Pizza{
    public PizzaBacon(int size, int price){
        this.size = size;
        this.price = price;
    }

    @Override
    public String toString() {
        return "Pizza Bacon cu " + super.toString();
    }
}
