package edu.tucn.aut.isp.lab4.exercise1;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

import java.time.LocalTime;

class AquariumControllerTest {
    //implement minimal tests
    @Test
    //this test method was here before
    void dummyTestNPE() {
        Assertions.assertThrows(
                NullPointerException.class, () -> {
                    Integer nullInt = null;
                    nullInt.toString();
                });

        AquariumController obj = new AquariumController("TestMa", "TestMo");
        //testing if the constructor initializes correctly
        Assertions.assertEquals(
                "AquariumController{manufacturer='TestMa', model='TestMo', currentTime=00:00}", obj.toString());
        obj.setCurrentTime(LocalTime.of(23, 15));
        Assertions.assertEquals(
                "AquariumController{manufacturer='TestMa', model='TestMo', currentTime=23:15}", obj.toString());

    }


}
