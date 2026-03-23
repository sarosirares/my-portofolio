package isp.lab3.exercise3;

public class MainOfExercise3 {
    public static void main(String[] args) {
        Vehicle obj1 = new Vehicle("Dacia", "Logan", 110, 'D');
        Vehicle obj2 = new Vehicle("Ford", "Kuga", 150, 'B');
        //Vehicle objtest = new Vehicle("Toyota", "Auris", 140, 'D'); object created for testing static method get.Num()

        System.out.println("Initial vehicles before calling setters:");
        System.out.println(obj1 + "; " + obj2);

        //calling the setters and getters

        obj1.setModel("Opel");
        obj1.setType("Astra H");
        obj1.setSpeed(140);
        obj1.setFuelType('D');

        obj2.setModel("Opel");
        obj2.setType("Astra H");
        obj2.setSpeed(140);
        obj2.setFuelType('D');

        System.out.println("\nThe model of the first car and it's fuel type is " + obj1.getModel() + ", " + obj1.getFuelType());
        System.out.println("\nThe type and speed of the second car is " + obj2.getType() + ", " + obj2.getSpeed());

        //3) comparison

        if (obj1.equals(obj2)) {
            System.out.println("The vehicles are identical!");
        } else {
            System.out.println("The vehicles are not identical!");
        }

        //4)

        System.out.println("The number of objects of type vehicle created is: " + Vehicle.getNum() + ".");

    }
}
