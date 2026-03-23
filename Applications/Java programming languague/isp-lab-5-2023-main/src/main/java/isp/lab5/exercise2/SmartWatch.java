package isp.lab5.exercise2;

public class SmartWatch implements Chargeable {
    //attributes
    private int batteryLevel;

    //constructor
    public SmartWatch() {
        this.batteryLevel = 0; //when created, the smartwatch has 0% battery
    }

    //methods
    public int getBatteryLevel() {
        return batteryLevel;
    }

    public void charge(int duration) {
        if (duration >= 0) {
            this.batteryLevel += duration * 2; //let's say that the smartwatch charges 2% per minute
            if (this.batteryLevel > 100) { //maximum battery level is 100
                this.batteryLevel = 100;
            }
        }
    }
}
