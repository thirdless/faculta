package paoo;

import java.util.*;

import paoo.PizzaStore.ChicagoStore.ChicagoPizzaStore;
import paoo.PizzaStore.NewYorkStore.NewYorkPizzaStore;
import paoo.PizzaStore.PizzaStore;
import paoo.Pizza.Pizza;
import paoo.PizzaStore.PizzaType;

public class Main {

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        PizzaStore store = null;
        Pizza pizza = null;

        System.out.println("Type the city (New York/Chicago):");
        String storeType = input.nextLine();

        if(storeType.compareTo("Chicago") == 0) store = new ChicagoPizzaStore();
        else if(storeType.compareTo("New York") == 0) store = new NewYorkPizzaStore();

        System.out.println("Type the pizza type (Cheese/Pepperoni/Clam):");
        String pizzaType = input.nextLine();

        if(store != null){
            if(pizzaType.compareTo("Cheese") == 0) pizza = store.OrderPizza(PizzaType.CHEESE);
            else if(pizzaType.compareTo("Pepperoni") == 0) pizza = store.OrderPizza(PizzaType.PEPPERONI);
            else if(pizzaType.compareTo("Clam") == 0) pizza = store.OrderPizza(PizzaType.CLAM);
        }

        if(pizza != null) System.out.println(pizza.GetProcessRecord());
        else System.out.println("Input error");
    }
}
