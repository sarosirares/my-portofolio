package edu.tucn.aut.isp.lab4.exercise5;

public class Sensor {
    //attributes
    private String manufacturer;
    private String model;

    //constructor
    public Sensor() {

    }

    public Sensor(String manufacturerC, String modelC) {
        this.manufacturer = manufacturerC;
        this.model = modelC;
    }

    //methods
    @Override
    public String toString() {
        return "Sensor{" +
                "manufacturer='" + manufacturer + '\'' +
                ", model='" + model + '\'' +
                '}';
    }
}
