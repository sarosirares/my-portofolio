package isp.lab5.exercise3;

import org.junit.Assert;
import org.junit.Test;

import java.util.ArrayList;
import java.util.List;

public class Exercise3Test {
    @Test
    public void averageTest() {
        Sensor sensorTest1 = new TemperatureSensor(-5.1); //testing also negative value
        Sensor sensorTest2 = new TemperatureSensor(0.0); //testing also value 0
        Sensor sensorTest3 = new PressureSensor(4);
        Sensor sensorTest4 = new PressureSensor(2.1);
        Sensor sensorTest5 = new TemperatureSensor(32.4);
        List<Sensor> sensorsTest = new ArrayList<>();
        sensorsTest.add(sensorTest1);
        sensorsTest.add(sensorTest2);
        sensorsTest.add(sensorTest3);
        sensorsTest.add(sensorTest4);
        sensorsTest.add(sensorTest5);
        MonitoringService obj = new MonitoringService(sensorsTest);

        Assert.assertEquals(9.1, obj.getAverageTemperatureSensors(), 0.01);
        Assert.assertEquals(6.68, obj.getAverageAllSensors(), 0.01);

    }
}
