package com.company.Pizza;

public abstract class Pizza {
    int size, price;

    @Override
    public String toString() {
        return "marimea " + size + " cm si pretul " + price + " lei";
    }
}