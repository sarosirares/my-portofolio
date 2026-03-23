package edu.tucn.aut.isp.lab4.exercise4;

import java.time.LocalTime;

public class AquariumController {

    //attributes
    private String manufacturer;
    private String model;
    private LocalTime currentTime;
    private LocalTime feedingTime;
    private FishFeeder aggrFeeder;
    private LocalTime lightOnTime;
    private LocalTime lightOffTime;
    private Lights aggrLight;

    //constructors
    //constructor for initializing the manufacturer and the model of the controller
    public AquariumController(String manufacturerC, String modelC, LocalTime feedingTimeC, FishFeeder aggrFeederC, Lights lightC) {
        this.manufacturer = manufacturerC;
        this.model = modelC;
        this.feedingTime = feedingTimeC;
        this.currentTime = LocalTime.of(0, 0); //default value for current time = 00:00
        this.aggrFeeder = aggrFeederC;
        this.aggrLight = lightC;
    }

    //methods
    void setCurrentTime(LocalTime currentTime) {
        this.currentTime = currentTime;
        if (this.currentTime.equals(this.feedingTime)) {
            aggrFeeder.feed();
        }
        if (aggrLight.isOn()) {
            this.lightOffTime = currentTime;
            //easier implementation using until method from class LocalTime, but I wanted to use methods used in demo example
            if ((lightOffTime.minusHours(lightOnTime.getHour()).getHour() == 7) ||
                    (lightOffTime.minusHours(lightOnTime.getHour()).getHour() == 6 && lightOffTime.getMinute() >= lightOnTime.getMinute() ||
                            lightOffTime.minusHours(lightOnTime.getHour()).getHour() == 8 && lightOffTime.getMinute() <= lightOnTime.getMinute())) {
                aggrLight.turnOff();
                System.out.println("Lights off!");
            } else {
                if ((lightOffTime.minusHours(lightOnTime.getHour()).getHour() - 8) >= 0) {
                    System.out.println("Lights should've been closed " + (lightOffTime.minusHours(lightOnTime.getHour()).getHour() - 8) + " hours before");
                } else {
                    System.out.println("Lights should be closed " + -(lightOffTime.minusHours(lightOnTime.getHour()).getHour() - 6) + " hours after");
                }
            }
        } else {
            aggrLight.turnOn();
            System.out.println("Lights on!");
            this.lightOnTime = currentTime;
        }
    }

    @Override
    public String toString() {
        return "AquariumController{" +
                "manufacturer='" + manufacturer + '\'' +
                ", model='" + model + '\'' +
                ", currentTime=" + currentTime +
                ", feedingTime=" + feedingTime +
                ", lightOnTime=" + lightOnTime +
                ", lightOffTime=" + lightOffTime +
                ", meals=" + aggrFeeder.getMeals() +
                ", isOn=" + aggrLight.isOn() +
                '}';
    }
}
