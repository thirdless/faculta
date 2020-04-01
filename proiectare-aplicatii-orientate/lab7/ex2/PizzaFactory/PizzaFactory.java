package com.company.PizzaFactory;

import com.company.Pizza.Pizza;
import com.company.Pizza.PizzaBacon;
import com.company.Pizza.PizzaQuatro;
import com.company.Pizza.PizzaSalami;
import com.company.Pizza.PizzaCheese;
import com.company.Pizza.PizzaType;

public class PizzaFactory {
    Pizza pizza;

    public PizzaFactory(PizzaType type, int size, int price){
        if(type == PizzaType.QUATRO){
            pizza = new PizzaQuatro(size, price);
        }
        else if(type == PizzaType.CHEESE){
            pizza = new PizzaCheese(size, price);
        }
        else if(type == PizzaType.SALAMI){
            pizza = new PizzaSalami(size, price);
        }
        else if(type == PizzaType.BACON){
            pizza = new PizzaBacon(size, price);
        }
    }

    @Override
    public String toString() {
        return pizza.toString();
    }
}
