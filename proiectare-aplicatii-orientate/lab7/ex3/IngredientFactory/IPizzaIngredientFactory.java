package paoo.IngredientFactory;

import paoo.IngredientFactory.Dough.IDough;
import paoo.IngredientFactory.Sauce.ISauce;
import paoo.IngredientFactory.Veggies.IVeggies;
import paoo.IngredientFactory.Clams.IClams;
import paoo.IngredientFactory.Cheese.ICheese;
import paoo.IngredientFactory.Pepperoni.IPepperoni;

public interface IPizzaIngredientFactory{
    public IDough CreateDough();
    public ISauce CreateSauce();
    public ICheese CreateCheese();
    public IVeggies[] CreateVeggies();
    public IPepperoni CreatePepperoni();
    public IClams CreateClams();
}