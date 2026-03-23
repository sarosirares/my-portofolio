package edu.tucn.aut.isp.lab4.exercise2;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

public class FishFeederTest {
    @Test
    void fillUpTest() {
        FishFeeder obj = new FishFeeder("Test", "Test");
        //using toString() to test the number of meals to not create a getter for meals and to let it private
        Assertions.assertEquals(
                "FishFeeder{manufacturer='Test', model='Test', meals=0}", obj.toString());
        obj.fillUp();
        Assertions.assertEquals(
                "FishFeeder{manufacturer='Test', model='Test', meals=14}", obj.toString());
    }

    @Test
    void feedTest() {
        FishFeeder obj = new FishFeeder("Test", "Test");
        //verify if the meals remain 0 if we use feed() and the meals are already 0
        Assertions.assertEquals(
                "FishFeeder{manufacturer='Test', model='Test', meals=0}", obj.toString());
        obj.fillUp();
        obj.feed();
        Assertions.assertEquals(
                "FishFeeder{manufacturer='Test', model='Test', meals=13}", obj.toString());
    }
}
