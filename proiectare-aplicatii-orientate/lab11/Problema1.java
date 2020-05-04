class Circle{
    double radius;
    static int number = 0;

    void setRadius(double newRadius) throws InvalidRadiusException{
        if(newRadius < 0) throw new InvalidRadiusException();
        radius = newRadius;
    }

    Circle(double newRadius) throws InvalidRadiusException{
        setRadius(newRadius);
        number++;
    }

    double getArea(){
        return Math.PI * radius * radius;
    }
}

class InvalidRadiusException extends Exception{
    InvalidRadiusException(){
        System.out.println("Invalid radius");
    }
}

public class Problema1 {
    public static void main(String[] arg){
        try{
            Circle c1 = new Circle(2);
            Circle c2 = new Circle(3);
            Circle c3 = new Circle(4);
            System.out.println("\n" + c1.getArea() + "\n" + c2.getArea() + "\n" + c3.getArea() + "\nNumar obiecte instantiate: " + Circle.number);
        }
        catch(InvalidRadiusException e){
            System.out.println("Parametrii invalizi");
        }
    }
}
