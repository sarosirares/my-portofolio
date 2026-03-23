package edu.tucn.aut.isp.lab4.exercise3;

import java.time.LocalTime;

public class Exercise3 {
    public static void main(String[] args) {
        FishFeeder feeder = new FishFeeder("FISH FEEDERS SRL", "Test"); //for aggregation
        AquariumController aquariumC = new AquariumController("Neptune", "Test", LocalTime.of(14, 0), feeder);

        System.out.println("The aquarium controller specifications are: " + aquariumC);
        //initially the meals are equal to 0

        //changing the current time
        aquariumC.setCurrentTime(LocalTime.of(14, 0));

        //checking the other way, by filling up the container using fillUp() method if the user didn't want to fill
        System.out.println("\nThe next day: container will automatically fill up if empty!\n");
        if (feeder.getMeals() == 0) { feeder.fillUp(); }

        aquariumC.setCurrentTime(LocalTime.of(12, 38)); //not the time for feeding
        aquariumC.setCurrentTime(LocalTime.of(14, 0)); //time for feeding
    }
}