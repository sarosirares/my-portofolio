package edu.tucn.aut.isp.lab4.exercise6;

public class Exercise6 {
    public static void main(String[] args) {
        FishFeeder fFeeder = new FishFeeder("FISH FEEDERS SRL", "Test");
        LevelSensor lSensor = new LevelSensor();
        TemperatureSensor tSensor = new TemperatureSensor();
        PhMonitor pHobj = new PhMonitor();
        Alarm alr = new Alarm();
        Heater heat = new Heater();

        AquariumController obj = new AquariumController("Neptune", "Test", 20, 50, 7.0f, fFeeder, tSensor, lSensor, alr, heat, pHobj);

        System.out.println("\nAlarm will turn on when the 'canpH' variable is of, because that means it's not possible to change pH.");
        pHobj.setValue(6.4f);
        pHobj.setCanpH(false);
        obj.checkPh();

        System.out.println("\nBecause pH level is 6.4, and it is possible to change it, the pH level is changed to the preset value.");

        pHobj.setCanpH(true);
        obj.checkPh();
    }
}
