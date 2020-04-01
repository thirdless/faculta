package paoo.Pizza;

import paoo.IngredientFactory.IPizzaIngredientFactory;
import paoo.IngredientFactory.Veggies.IVeggies;

public class ClamPizza extends Pizza {
    public ClamPizza(IPizzaIngredientFactory ingredientFactory, String name)
    {
        this.ingredientFactory = ingredientFactory;
        this.name = name;
    }
    @Override
    public void Prepare()
    {
        dough = ingredientFactory.CreateDough();
        sauce = ingredientFactory.CreateSauce();
        clams = ingredientFactory.CreateClams();
        veggies = ingredientFactory.CreateVeggies();
        processRecord += "Preparing " + name + "\n";
        processRecord += dough.GetName() + "\n";
        processRecord += sauce.GetName() + "\n";
        processRecord += clams.GetName() + "\n";
        for(IVeggies v:veggies){
            processRecord += v.GetName() + "\n";
        }
    }
}