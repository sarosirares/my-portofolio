package isp.lab5.exercise3;

public class TemperatureSensor extends Sensor {
    //attributes
    private double temperature;

    //constructor
    public TemperatureSensor(double temperature) {
        this.temperature = temperature;
    }

    //methods
    public double getValue() {
        return temperature;
    }
}
