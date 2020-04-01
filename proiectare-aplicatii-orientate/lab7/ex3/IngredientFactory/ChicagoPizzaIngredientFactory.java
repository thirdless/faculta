package paoo.IngredientFactory;

import paoo.IngredientFactory.Dough.IDough;
import paoo.IngredientFactory.Dough.ThickCrustDough;
import paoo.IngredientFactory.Sauce.ISauce;
import paoo.IngredientFactory.Sauce.PlumTomatoSauce;
import paoo.IngredientFactory.Cheese.ICheese;
import paoo.IngredientFactory.Cheese.Mozzarella;
import paoo.IngredientFactory.Veggies.IVeggies;
import paoo.IngredientFactory.Veggies.BlackOlives;
import paoo.IngredientFactory.Veggies.Spinach;
import paoo.IngredientFactory.Veggies.EggPlant;
import paoo.IngredientFactory.Pepperoni.IPepperoni;
import paoo.IngredientFactory.Pepperoni.SlicedPepperoni;
import paoo.IngredientFactory.Clams.IClams;
import paoo.IngredientFactory.Clams.FrozenClams;

public class ChicagoPizzaIngredientFactory implements IPizzaIngredientFactory {
    public IDough CreateDough() {
        return new ThickCrustDough();
    }

    public ISauce CreateSauce() {
        return new PlumTomatoSauce();
    }

    public ICheese CreateCheese() {
        return new Mozzarella();
    }

    public IVeggies[] CreateVeggies() {
        IVeggies[] veggies = {new BlackOlives(), new
                Spinach(), new EggPlant()};
        return veggies;
    }

    public IPepperoni CreatePepperoni() {
        return new SlicedPepperoni();
    }

    public IClams CreateClams() {
        return new FrozenClams();
    }
}