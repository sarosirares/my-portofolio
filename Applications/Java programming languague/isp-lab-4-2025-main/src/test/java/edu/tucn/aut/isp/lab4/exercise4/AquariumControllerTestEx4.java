package edu.tucn.aut.isp.lab4.exercise4;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

import java.time.LocalTime;

public class AquariumControllerTestEx4 {
    @Test
    void lightTriggerTest() {
        FishFeeder testFeeder = new FishFeeder("Test", "Test");
        Lights testLight = new Lights();
        AquariumController obj = new AquariumController("Test", "Test", LocalTime.of(14, 0), testFeeder, testLight);

        //initially the light is off
        Assertions.assertFalse(testLight.isOn());
        //after setting the light on time, the light is on
        obj.setCurrentTime(LocalTime.of(9, 15));
        Assertions.assertTrue(testLight.isOn());
        //if we set a time smaller than 6 hours, the light should remain on
        obj.setCurrentTime(LocalTime.of(15, 10));
        Assertions.assertTrue(testLight.isOn());
        //same if we set a time bigger than 8
        obj.setCurrentTime(LocalTime.of(18, 30));
        Assertions.assertTrue(testLight.isOn());
        //the light should switch to off, cause the difference between current time and On time is between 6 and 8
        obj.setCurrentTime(LocalTime.of(17, 15));
        Assertions.assertFalse(testLight.isOn());

    }
}
