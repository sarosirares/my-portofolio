package edu.tucn.aut.isp.lab4.exercise2;

public class Exercise2 {
    public static void main(String[] args) {
        FishFeeder feeder = new FishFeeder("FISH FEEDERS SRL", "Test");
        //Because the constructor sets the initial value for meals to 0, this should not work properly
        feeder.feed();
        feeder.fillUp();
        System.out.println("The feeder specifications: \n" + feeder);
        for (int i = 0; i < 14; i++) {
            feeder.feed();
        }
        feeder.feed();
    }
}
