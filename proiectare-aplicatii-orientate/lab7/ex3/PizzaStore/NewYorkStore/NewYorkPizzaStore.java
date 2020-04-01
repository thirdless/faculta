package paoo.PizzaStore.NewYorkStore;

import paoo.PizzaStore.PizzaStore;
import paoo.PizzaStore.PizzaType;
import paoo.Pizza.Pizza;
import paoo.IngredientFactory.IPizzaIngredientFactory;
import paoo.IngredientFactory.NewYorkPizzaIngredientFactory;
import paoo.Pizza.CheesePizza;
import paoo.Pizza.ClamPizza;
import paoo.Pizza.PepperoniPizza;

public class NewYorkPizzaStore extends PizzaStore{
    @Override
    protected Pizza CreatePizza(PizzaType type) {
        Pizza pizza = null;
        IPizzaIngredientFactory ingredientFactory = new
                NewYorkPizzaIngredientFactory();
        switch (type) {
            case CHEESE:
                pizza = new CheesePizza(ingredientFactory,
                        "New York Style Cheese Pizza");
                break;
            case CLAM:
                pizza = new ClamPizza(ingredientFactory, "NewYork Style Clam Pizza");
                break;
            case PEPPERONI:
                pizza = new PepperoniPizza(ingredientFactory,
                        "New York Style Pepperoni Pizza");
                break;
        }
        return pizza;
    }
}