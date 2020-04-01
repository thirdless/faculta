package com.company;

import com.company.Pizza.Pizza;
import com.company.PizzaFactory.PizzaFactory;
import com.company.Pizza.PizzaType;

public class Main {

    public static void main(String[] args) {
        PizzaFactory pizzas[] = {
                new PizzaFactory(PizzaType.BACON, 35, 25),
                new PizzaFactory(PizzaType.QUATRO, 20, 15),
                new PizzaFactory(PizzaType.CHEESE, 50, 40),
                new PizzaFactory(PizzaType.SALAMI, 40, 35)
        };
        for(int i = 0; i < 4; i++) System.out.println(pizzas[i].toString());
    }
}
