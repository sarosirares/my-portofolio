package isp.lab3.exercise2;

public class MainOfExercise2 {
    public static void main(String[] args) {
        Rectangle obj0 = new Rectangle();
        Rectangle obj1 = new Rectangle(3, 2);
        Rectangle obj2 = new Rectangle(10, 5, "blue");

        System.out.println("The length of the first rectangle is " + obj0.getLength() +
                ", the width is " + obj0.getWidth() + ", and the color is " + obj0.getColor() +
                ". The perimeter is " + obj0.getPerimeter() + " and the area is " + obj0.getArea() + ".");

        System.out.println("The length of the second rectangle is " + obj1.getLength() +
                ", the width is " + obj1.getWidth() + ", and the color is " + obj1.getColor() +
                ". The perimeter is " + obj1.getPerimeter() + " and the area is " + obj1.getArea() + ".");

        System.out.println("The length of the third rectangle is " + obj2.getLength() +
                ", the width is " + obj2.getWidth() + ", and the color is " + obj2.getColor() +
                ". The perimeter is " + obj2.getPerimeter() + " and the area is " + obj2.getArea() + ".");

    }
}
