package edu.tucn.aut.isp.lab4.exercise6;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

public class AquariumControllerTestEx6 {
    @Test
    void isOnTest() {
        FishFeeder feederTest = new FishFeeder("Test", "Test");
        LevelSensor levelTest = new LevelSensor();
        TemperatureSensor tempTest = new TemperatureSensor();
        PhMonitor pHTest = new PhMonitor();
        Alarm alarmTest = new Alarm();
        Heater heatTest = new Heater();

        AquariumController obj = new AquariumController("Test", "Test", 20, 50, 7, feederTest, tempTest, levelTest, alarmTest, heatTest, pHTest);

        //by default, the alarm should be false
        Assertions.assertFalse(alarmTest.isOn());

        //when we can't change the pH, the alarm will turn on
        pHTest.setCanpH(false);
        pHTest.setValue(7.5f);
        obj.checkPh();
        Assertions.assertTrue(alarmTest.isOn());

        //when it is possible to change pH, the pH level will change to preset pH
        pHTest.setCanpH(true);
        obj.checkPh();
        Assertions.assertEquals(7, pHTest.getValue());

        //if pH value is bigger or less than preset level by 1, alarm will turn on, cause the difference is too large, and it will kill the fish
        pHTest.setValue(5.9f);
        obj.checkPh();
        Assertions.assertTrue(alarmTest.isOn());
    }
}
