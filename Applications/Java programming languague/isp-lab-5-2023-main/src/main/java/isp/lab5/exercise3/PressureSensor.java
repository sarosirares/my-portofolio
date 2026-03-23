package isp.lab5.exercise3;

public class PressureSensor extends Sensor {
    //attributes
    private double pressure;

    //constructor
    public PressureSensor(double pressure) {
        this.pressure = pressure;
    }

    //methods
    public double getValue() {
        return pressure;
    }
}
