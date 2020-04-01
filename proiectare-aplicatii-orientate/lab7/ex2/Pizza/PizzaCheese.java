package com.company.Pizza;

public class PizzaCheese extends Pizza {
    public PizzaCheese(int size, int price){
        this.size = size;
        this.price = price;
    }

    @Override
    public String toString() {
        return "Pizza Cheese cu " + super.toString();
    }
}
