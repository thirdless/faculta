package paoo.Pizza;

import paoo.IngredientFactory.IPizzaIngredientFactory;
import paoo.IngredientFactory.Cheese.ICheese;
import paoo.IngredientFactory.Clams.IClams;
import paoo.IngredientFactory.Dough.IDough;
import paoo.IngredientFactory.Pepperoni.IPepperoni;
import paoo.IngredientFactory.Sauce.ISauce;
import paoo.IngredientFactory.Veggies.IVeggies;

public abstract class Pizza {
    protected String name;
    protected ICheese cheese;
    protected IClams clams;
    protected IDough dough;
    protected IPepperoni pepperoni;
    protected ISauce sauce;
    protected IVeggies[] veggies;
    protected String processRecord = "";
    protected IPizzaIngredientFactory ingredientFactory;

    public Pizza() {

    }

    public String GetName(){
        return name;
    }

    public String GetProcessRecord(){
        return processRecord;
    }

    public abstract void Prepare();

    public void Bake(){
        processRecord += "Bake for 25 mins at 175 C\n";
    }

    public void Cut(){
        processRecord += "Cutting the pizza into diagonal slices\n";
    }

    public void Box(){
        processRecord += "Place pizza in official PizzaStore box";
    }
}
