package paoo.PizzaStore.ChicagoStore;

import paoo.PizzaStore.PizzaStore;
import paoo.PizzaStore.PizzaType;
import paoo.Pizza.Pizza;
import paoo.IngredientFactory.IPizzaIngredientFactory;
import paoo.IngredientFactory.ChicagoPizzaIngredientFactory;
import paoo.Pizza.CheesePizza;
import paoo.Pizza.ClamPizza;
import paoo.Pizza.PepperoniPizza;

public class ChicagoPizzaStore extends PizzaStore {
    @Override
    protected Pizza CreatePizza(PizzaType type){
        Pizza pizza = null;
        IPizzaIngredientFactory ingredientFactory = new
                ChicagoPizzaIngredientFactory();
        switch (type) {
            case CHEESE:
                pizza = new CheesePizza(ingredientFactory,
                        "Chicago Style Cheese Pizza");
                break;
            case CLAM:
                pizza = new ClamPizza(ingredientFactory,
                        "Chicago Style Clam Pizza");
                break;
            case PEPPERONI:
                pizza = new PepperoniPizza(ingredientFactory,
                        "Chicago Style Pepperoni Pizza");
                break;
        }
        return pizza;
    }
}