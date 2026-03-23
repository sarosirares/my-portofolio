package edu.tucn.aut.isp.lab4.exercise3;

import java.time.LocalTime;
import java.util.Scanner;

public class AquariumController {

    //attributes
    private String manufacturer;
    private String model;
    private LocalTime currentTime;
    private LocalTime feedingTime;
    private FishFeeder aggrFeeder;

    //constructors
    //constructor for initializing the manufacturer and the model of the controller
    public AquariumController(String manufacturerC, String modelC, LocalTime feedingTimeC, FishFeeder aggrFeederC) {
        this.manufacturer = manufacturerC;
        this.model = modelC;
        this.feedingTime = feedingTimeC;
        this.currentTime = LocalTime.of(0, 0); //default value for current time = 00:00
        this.aggrFeeder = aggrFeederC;
    }

    //methods
    void setCurrentTime(LocalTime currentTime) {
        this.currentTime = currentTime;
        if (this.currentTime.equals(this.feedingTime)) {
            // this is extra checking to be sure that it will be enough food everytime
//            Scanner scanner = new Scanner(System.in);
//            if (aggrFeeder.getMeals() == 0) {
//                System.out.println("The container is empty! " +
//                        "Do you want to fill up the food container? Enter '1' to fill it and other number otherwise: ");
//                if (scanner.nextInt() == 1) {
//                    scanner.nextLine();
//                    aggrFeeder.fillUp();
//                }
//            }
            aggrFeeder.feed();
        }
    }

    @Override
    public String toString() {
        return "AquariumController{" +
                "manufacturer='" + manufacturer + '\'' +
                ", model='" + model + '\'' +
                ", currentTime=" + currentTime +
                ", feedingTime=" + feedingTime +
                ", meals=" + aggrFeeder.getMeals() +
                '}';
    }
}
