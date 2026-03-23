package edu.tucn.aut.isp.lab4.exercise5;

public class TemperatureSensor extends Sensor{
    //attributes
    private float value;

    //methods

    public void setValue(float value) {
        this.value = value;
    }

    public float getValue() {
        return value;
    }
}
