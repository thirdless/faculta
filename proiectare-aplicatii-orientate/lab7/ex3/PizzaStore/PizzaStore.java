package paoo.PizzaStore;

import paoo.Pizza.Pizza;

public abstract class PizzaStore {
    protected abstract Pizza CreatePizza(PizzaType type);
    public Pizza OrderPizza(PizzaType type){
        Pizza pizza = CreatePizza(type);
        pizza.Prepare();
        pizza.Bake();
        pizza.Cut();
        pizza.Box();

        return pizza;
    }
}
