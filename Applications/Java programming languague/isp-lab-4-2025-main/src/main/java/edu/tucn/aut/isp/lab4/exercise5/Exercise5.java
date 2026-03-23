package edu.tucn.aut.isp.lab4.exercise5;

public class Exercise5 {
    public static void main(String[] args) {
        FishFeeder fFeeder = new FishFeeder("FISH FEEDERS SRL", "Test");
        LevelSensor lSensor = new LevelSensor();
        TemperatureSensor tSensor = new TemperatureSensor();
        Alarm alr = new Alarm();
        Heater heat = new Heater();

        AquariumController obj = new AquariumController("Neptune", "Test", 20, 50, fFeeder, tSensor, lSensor, alr, heat);

        tSensor.setValue(15);
        lSensor.setValue(30);

        obj.checkWaterLevel();
        obj.checkTemperature();

        System.out.println("\nThe controller at start: \n" + obj + "\n");

        tSensor.setValue(30);
        lSensor.setValue(51);

        obj.checkWaterLevel();
        obj.checkTemperature();

        System.out.println("\nThe controller after water level raised: \n" + obj + "\n");

        tSensor.setValue(20);
        lSensor.setValue(50);

        obj.checkWaterLevel();
        obj.checkTemperature();

        System.out.println("\nThe controller after temperature is set: \n" + obj + "\n");
    }
}
