package isp.lab5.exercise2;

public class Laptop implements Chargeable {
    //attributes
    private int batteryLevel;

    //constructor
    public Laptop() {
        this.batteryLevel = 0; //when created, the laptop has 0% battery
    }

    //methods
    public int getBatteryLevel() {
        return batteryLevel;
    }

    public void charge(int duration) {
        if (duration >= 0) {
            this.batteryLevel += duration; //let's say that the laptop charges 1% per minute
            if (this.batteryLevel > 100) { //maximum battery level is 100
                this.batteryLevel = 100;
            }
        }
    }
}
