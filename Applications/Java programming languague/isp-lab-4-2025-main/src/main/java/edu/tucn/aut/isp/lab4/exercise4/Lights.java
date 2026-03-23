package edu.tucn.aut.isp.lab4.exercise4;

public class Lights {
    //attributes
    private boolean isOn;

    //constructor for initializing isOn with false as default
    public Lights() {
        this.isOn = false;
    }

    //methods
    public boolean isOn() {
        return isOn;
    }

    public void turnOn() {
        this.isOn = true;
    }

    public void turnOff() {
        this.isOn = false;
    }
}
