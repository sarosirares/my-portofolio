package edu.tucn.aut.isp.lab4.exercise5;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

public class AquariumControllerTestEx5 {
    @Test
    void isOnTest() {
        FishFeeder feederTest = new FishFeeder("Test", "Test");
        LevelSensor levelTest = new LevelSensor();
        TemperatureSensor tempTest = new TemperatureSensor();
        Alarm alarmTest = new Alarm();
        Heater heatTest = new Heater();

        AquariumController obj = new AquariumController("Test", "Test", 20, 50, feederTest, tempTest, levelTest, alarmTest, heatTest);

        //by default, both the alarm and heater should be false
        Assertions.assertFalse(alarmTest.isOn());
        Assertions.assertFalse(heatTest.isOn());

        levelTest.setValue(12);
        tempTest.setValue(45.2f);
        obj.checkWaterLevel();
        obj.checkTemperature();

        Assertions.assertTrue(alarmTest.isOn()); //if water level is below, alarm is on
        Assertions.assertFalse(heatTest.isOn()); //if temperature is higher, the heater is off

        levelTest.setValue(50);
        tempTest.setValue(18.5f);
        obj.checkWaterLevel();
        obj.checkTemperature();

        Assertions.assertFalse(alarmTest.isOn()); //if water level is at level, alarm is off
        Assertions.assertTrue(heatTest.isOn()); //if temperature is lower, the heater is on

        levelTest.setValue(51);
        tempTest.setValue(20.0f);
        obj.checkWaterLevel();
        obj.checkTemperature();

        Assertions.assertFalse(alarmTest.isOn()); //if water level is above, alarm is off
        Assertions.assertFalse(heatTest.isOn()); //if temperature is equal to preset, the heater is off
    }
}
