package isp.lab3.exercise4;

public class MainOfExercise4 {
    public static void main(String[] args) {
        MyPoint point1 = new MyPoint();
        MyPoint point2 = new MyPoint(5, -1, 12);

        point1.setXYZ(1, 0, -1);



        System.out.println("The distance between " + point1 + " and " + point2 +
                " is: " + String.format("%.3f", point1.distance(point2))); // rounded the floating number to 3 decimals

        System.out.println("The distance between " + point1 + " and (4, 2, -4) is: " +
                String.format("%.3f", point1.distance(4, 2, -4))); // rounded the floating number to 3 decimals

    }
}
