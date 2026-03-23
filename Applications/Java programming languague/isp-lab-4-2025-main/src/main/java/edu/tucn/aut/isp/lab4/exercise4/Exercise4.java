package edu.tucn.aut.isp.lab4.exercise4;

import java.time.LocalTime;

public class Exercise4 {
    public static void main(String[] args) {
        FishFeeder feeder = new FishFeeder("FISH FEEDERS SRL", "Test");
        Lights light = new Lights();
        AquariumController obj = new AquariumController("Neptune", "Test", LocalTime.of(14, 0), feeder, light);

        System.out.println("The aquarium controller specifications are: " + obj);

        obj.setCurrentTime(LocalTime.of(10, 30));
        System.out.println("The aquarium controller specifications are: " + obj);
        obj.setCurrentTime(LocalTime.of(19, 30));
        System.out.println("The aquarium controller specifications are: " + obj);
        obj.setCurrentTime(LocalTime.of(18, 31));
        System.out.println("The aquarium controller specifications are: " + obj);
    }
}
