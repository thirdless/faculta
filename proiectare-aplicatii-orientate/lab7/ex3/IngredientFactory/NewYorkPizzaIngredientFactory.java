package paoo.IngredientFactory;

import paoo.IngredientFactory.Dough.IDough;
import paoo.IngredientFactory.Dough.ThinCrustDough;
import paoo.IngredientFactory.Sauce.ISauce;
import paoo.IngredientFactory.Sauce.MarinaraSauce;
import paoo.IngredientFactory.Cheese.ICheese;
import paoo.IngredientFactory.Cheese.ReggianoCheese;
import paoo.IngredientFactory.Veggies.IVeggies;
import paoo.IngredientFactory.Veggies.Garlic;
import paoo.IngredientFactory.Veggies.Onion;
import paoo.IngredientFactory.Veggies.Mushroom;
import paoo.IngredientFactory.Veggies.RedPepper;
import paoo.IngredientFactory.Pepperoni.IPepperoni;
import paoo.IngredientFactory.Pepperoni.SlicedPepperoni;
import paoo.IngredientFactory.Clams.IClams;
import paoo.IngredientFactory.Clams.FreshClams;

public class NewYorkPizzaIngredientFactory implements IPizzaIngredientFactory {
    public IDough CreateDough() {
        return new ThinCrustDough();
    }

    public ISauce CreateSauce() {
        return new MarinaraSauce();
    }

    public ICheese CreateCheese() {
        return new ReggianoCheese();
    }

    public IVeggies[] CreateVeggies() {
        IVeggies[] veggies = {new Garlic(), new
                Onion(), new Mushroom(), new RedPepper()};
        return veggies;
    }

    public IPepperoni CreatePepperoni() {
        return new SlicedPepperoni();
    }

    public IClams CreateClams() {
        return new FreshClams();
    }
}