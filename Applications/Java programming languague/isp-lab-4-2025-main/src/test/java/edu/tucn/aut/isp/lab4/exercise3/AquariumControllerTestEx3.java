package edu.tucn.aut.isp.lab4.exercise3;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

import java.text.Format;
import java.time.LocalTime;

public class AquariumControllerTestEx3 {
    @Test
    void triggerTest() {
        FishFeeder test = new FishFeeder("FeederTest", "FeederTest");
        AquariumController obj = new AquariumController("AquariumTest", "AquariumTest", LocalTime.of(12, 30), test);

        //testing when the feeder is not filled up
        obj.setCurrentTime(LocalTime.of(12, 30));
        Assertions.assertEquals(0, test.getMeals());

        //testing after filling up
        test.fillUp();
        obj.setCurrentTime(LocalTime.of(13, 1));
        Assertions.assertEquals(14, test.getMeals());
        obj.setCurrentTime(LocalTime.of(12, 30));
        Assertions.assertEquals(13, test.getMeals());
    }
}
