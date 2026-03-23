package isp.lab5.exercise2;

public class Exercise2 {
    public static void main(String args[]) {
        Laptop laptop  = new Laptop();
        SmartPhone smartPhone = new SmartPhone();
        SmartWatch smartWatch = new SmartWatch();

        //initially
        System.out.println("Battery of the laptop = " + laptop.getBatteryLevel() + "%");
        System.out.println("Battery of the smartphone = " + smartPhone.getBatteryLevel() + "%");
        System.out.println("Battery of the smartwatch = " + smartWatch.getBatteryLevel() + "%");

        //after charging same duration

        System.out.println();

        laptop.charge(10);
        smartPhone.charge(10);
        smartWatch.charge(10);

        System.out.println("Battery of the laptop = " + laptop.getBatteryLevel() + "%");
        System.out.println("Battery of the smartphone = " + smartPhone.getBatteryLevel() + "%");
        System.out.println("Battery of the smartwatch = " + smartWatch.getBatteryLevel() + "%");
        System.out.println("We can see that the smartwatch charged up the fastest.");

        //charging different durations

        System.out.println();

        laptop.charge(7);
        smartPhone.charge(23);
        smartWatch.charge(17);

        System.out.println("Battery of the laptop = " + laptop.getBatteryLevel() + "%");
        System.out.println("Battery of the smartphone = " + smartPhone.getBatteryLevel() + "%");
        System.out.println("Battery of the smartwatch = " + smartWatch.getBatteryLevel() + "%");

        //full charge(extra minutes at charging)

        System.out.println();

        laptop.charge(100);
        smartPhone.charge(100);
        smartWatch.charge(100);

        System.out.println("Battery of the laptop = " + laptop.getBatteryLevel() + "%");
        System.out.println("Battery of the smartphone = " + smartPhone.getBatteryLevel() + "%");
        System.out.println("Battery of the smartwatch = " + smartWatch.getBatteryLevel() + "%");
        System.out.println("Devices fully charged!");
    }
}
