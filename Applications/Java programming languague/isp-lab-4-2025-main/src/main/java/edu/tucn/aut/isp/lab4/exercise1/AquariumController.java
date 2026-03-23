package edu.tucn.aut.isp.lab4.exercise1;

import java.time.LocalTime;

public class AquariumController {

    //attributes
    private String manufacturer;
    private String model;
    private LocalTime currentTime;

    //constructors
    //constructor for initializing the manufacturer and the model of the controller
    public AquariumController(String manufacturerC, String modelC) {
        this.manufacturer = manufacturerC;
        this.model = modelC;
        this.currentTime = LocalTime.of(0, 0); //default value for current time = 00:00
    }

    //methods
    void setCurrentTime(LocalTime currentTime) {
        this.currentTime = currentTime;
    }

    @Override
    public String toString() {
        return "AquariumController{" +
                "manufacturer='" + manufacturer + '\'' +
                ", model='" + model + '\'' +
                ", currentTime=" + currentTime +
                '}';
    }
}
