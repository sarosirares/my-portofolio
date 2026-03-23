package edu.tucn.aut.isp.lab4.exercise5;

public class Alarm extends  Actuator{
    //methods
    public void turnOn() {
        super.turnOn();
        System.out.println("Alarm turned on!");
    }

    public void turnOff() {
        super.turnOff();
        System.out.println("Alarm turned off!");
    }
}
