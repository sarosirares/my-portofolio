package isp.lab3.exercise;

import isp.lab3.exercise3.Vehicle;
import org.junit.Assert;
import org.junit.Test;

public class VehicleTest {

    @Test
    public void testToString(){
        Vehicle obj = new Vehicle("Dacia", "Logan", 110, 'D');
        Assert.assertEquals("Dacia (Logan) speed 110, fuel type D", obj.toString());
    }
}
