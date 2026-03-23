package isp.lab5.exercise3;

import java.util.ArrayList;
import java.util.List;

public class Exercise3 {
    public static void main(String[] args) {
        Sensor sensor1 = new TemperatureSensor(36.1);
        Sensor sensor2 = new TemperatureSensor(32.0);
        Sensor sensor3 = new PressureSensor(1.2);
        Sensor sensor4 = new PressureSensor(1.1);
        Sensor sensor5 = new TemperatureSensor(29.1);
        Sensor sensor6 = new TemperatureSensor(28.0);
        Sensor sensor7 = new TemperatureSensor(27.9);
        Sensor sensor8 = new PressureSensor(1.0);
        Sensor sensor9 = new PressureSensor(1.3);
        Sensor sensor10 = new TemperatureSensor(37.0);
        List<Sensor> sensors = new ArrayList<>();

        sensors.add(sensor1);
        sensors.add(sensor2);
        sensors.add(sensor3);
        sensors.add(sensor4);
        sensors.add(sensor5);
        sensors.add(sensor6);
        sensors.add(sensor7);
        sensors.add(sensor8);
        sensors.add(sensor9);
        sensors.add(sensor10);
        //can I use List.of?

        MonitoringService obj = new MonitoringService(sensors);
        System.out.println("Average Temperature: " + obj.getAverageTemperatureSensors());
        System.out.println("Average value of all sensors: " + obj.getAverageAllSensors());
    }
}
