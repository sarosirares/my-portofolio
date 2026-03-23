package isp.lab5.exercise2;

import org.junit.Assert;
import org.junit.Test;

public class Exercise2Test {
    @Test
    public void chargeTest() {
        Laptop laptopTest = new Laptop();
        SmartPhone smartPhoneTest = new SmartPhone();
        SmartWatch smartWatchTest = new SmartWatch();

        //initial battery level should be 0
        Assert.assertEquals(0, laptopTest.getBatteryLevel());
        Assert.assertEquals(0, smartPhoneTest.getBatteryLevel());
        Assert.assertEquals(0, smartWatchTest.getBatteryLevel());

        //testing negative values for duration
        laptopTest.charge(-10);
        smartPhoneTest.charge(-31);
        smartWatchTest.charge(-101);

        Assert.assertEquals(0, laptopTest.getBatteryLevel());
        Assert.assertEquals(0, smartPhoneTest.getBatteryLevel());
        Assert.assertEquals(0, smartWatchTest.getBatteryLevel());

        //testing real values values for duration
        laptopTest.charge(0);
        smartPhoneTest.charge(13);
        smartWatchTest.charge(35);

        Assert.assertEquals(0, laptopTest.getBatteryLevel());
        Assert.assertEquals((int) (13 * 1.5), smartPhoneTest.getBatteryLevel());
        Assert.assertEquals(35 * 2, smartWatchTest.getBatteryLevel());

        //testing full charge
        laptopTest.charge(100);
        smartPhoneTest.charge(100);
        smartWatchTest.charge(100);

        Assert.assertEquals(100, laptopTest.getBatteryLevel());
        Assert.assertEquals(100, smartPhoneTest.getBatteryLevel());
        Assert.assertEquals(100, smartWatchTest.getBatteryLevel());
    }
}
