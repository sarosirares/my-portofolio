package edu.tucn.aut.isp.lab4.exercise5;

import java.time.LocalTime;

public class AquariumController {

    //attributes
    private FishFeeder feeder;
    private String manufacturer;
    private String model;
    private LocalTime currentTime;
    private LocalTime feedingTime;
    private int presetTemperature;
    private float presetLevel;
    private TemperatureSensor tSensor;
    private LevelSensor lSensor;
    private Actuator alarmAct;
    private Actuator heaterAct;


    //constructors
    //constructor for initializing the manufacturer and the model of the controller and to do the aggregation
    public AquariumController(String manufacturerC, String modelC, int pTemperature, float pLevel, FishFeeder feederC, TemperatureSensor tSensorC, LevelSensor lSensorC, Alarm alarmC, Heater sensorC) {
        this.manufacturer = manufacturerC;
        this.model = modelC;
        this.currentTime = LocalTime.of(0, 0); //default value for current time = 00:00
        this.feedingTime = LocalTime.of(12, 0); //default value for feeding time at 12:00
        this.presetTemperature = pTemperature;
        this.presetLevel = pLevel;
        this.feeder = feederC;
        this.tSensor = tSensorC;
        this.lSensor = lSensorC;
        this.alarmAct = alarmC;
        this.heaterAct = sensorC;
    }

    //methods
    void setCurrentTime(LocalTime currentTime) {
        this.currentTime = currentTime;
        if (this.currentTime.equals(this.feedingTime)) {
            feeder.feed();
        }
    }

    public void setFeedingTime(LocalTime feedingTime) {
        this.feedingTime = feedingTime;
    }

    public void checkTemperature() {
        if (this.tSensor.getValue() < (float) presetTemperature) {
            heaterAct.turnOn();
        } else {
            heaterAct.turnOff();
        }
    }

    public void checkWaterLevel() {
        if ((float) this.lSensor.getValue() < presetLevel) {
            alarmAct.turnOn();
        } else {
            alarmAct.turnOff();
        }
    }

    @Override
    public String toString() {
        return "AquariumController{" +
                ", manufacturer='" + manufacturer + '\'' +
                ", model='" + model + '\'' +
                ", currentTime=" + currentTime +
                ", feedingTime=" + feedingTime +
                ", presetTemperature=" + presetTemperature +
                ", presetLevel=" + presetLevel +
                ", Alarm.on=" + alarmAct.isOn() +
                ", Heater.on=" + heaterAct.isOn() +
                '}';
    }
}
