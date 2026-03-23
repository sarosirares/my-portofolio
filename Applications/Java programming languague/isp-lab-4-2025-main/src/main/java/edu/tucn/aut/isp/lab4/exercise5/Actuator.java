package edu.tucn.aut.isp.lab4.exercise5;

public class Actuator {
    //attributes
    private String manufacturer;
    private String model;
    private boolean on;

    //constructor
    public Actuator() {

    }

    public Actuator(String manufacturerC, String modelC) {
        this.manufacturer = manufacturerC;
        this.model = modelC;
        on = false;
    }

    public void turnOn() {
        this.on = true;
    }

    public void turnOff() {
        this.on = false;
    }

    public boolean isOn() {
        return on;
    }

    @Override
    public String toString() {
        return "Actuator{" +
                "manufacturer='" + manufacturer + '\'' +
                ", model='" + model + '\'' +
                ", on=" + on +
                '}';
    }
}
