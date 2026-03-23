package isp.lab5.exercise3;

import java.util.List;

public class MonitoringService {
    //attributes
    private List<Sensor> sensors;

    //constructors
    public MonitoringService(List<Sensor> sensors) {
        this.sensors = sensors;
    }

    //methods
    public double getAverageTemperatureSensors() {
        double total = 0;
        int i = 0;
        for (Sensor sensor : sensors) {
            if (sensor instanceof TemperatureSensor) {
                total += sensor.getValue();
                i++;
            }
        }
        return total / i;
    }

    public double getAverageAllSensors() {
        double total = 0;
        int i = 0;
        for (Sensor sensor : sensors) {
            total += sensor.getValue();
            i++;
        }
        return total / i;
    }
}
