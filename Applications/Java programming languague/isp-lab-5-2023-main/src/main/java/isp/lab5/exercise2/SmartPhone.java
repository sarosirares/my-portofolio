package isp.lab5.exercise2;

public class SmartPhone implements Chargeable {
    //attributes
    private int batteryLevel;

    //constructor
    public SmartPhone() {
        this.batteryLevel = 0; //when created, the smartphone has 0% battery
    }

    //methods
    public int getBatteryLevel() {
        return batteryLevel;
    }

    public void charge(int duration) {
        if (duration >= 0) {
            this.batteryLevel += duration * 1.5; //let's say that the smartphone charges 1.5% per minute(even though batteryLevel is int)
            if (this.batteryLevel > 100) { //maximum battery level is 100
                this.batteryLevel = 100;
            }
        }
    }
}
