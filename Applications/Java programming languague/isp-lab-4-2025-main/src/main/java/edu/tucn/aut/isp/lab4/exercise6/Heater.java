package edu.tucn.aut.isp.lab4.exercise6;

public class Heater extends Actuator {
    //methods
    public void turnOn() {
        super.turnOn();
        System.out.println("Heater turned on!");
    }

    public void turnOff() {
        super.turnOff();
        System.out.println("Heater turned off!");
    }
}
