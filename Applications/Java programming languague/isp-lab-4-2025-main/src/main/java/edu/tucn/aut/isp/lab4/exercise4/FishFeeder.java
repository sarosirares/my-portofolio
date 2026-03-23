package edu.tucn.aut.isp.lab4.exercise4;

public class FishFeeder {
    //attributes
    private String manufacturer;
    private String model;
    private int meals;

    //constructor for initializing manufacturer, model, and meals = 0 (as default)
    public FishFeeder(String manufacturerC, String modelC) {
        this.manufacturer = manufacturerC;
        this.model = modelC;
        meals = 0;
    }

    //methods

    //needed for setCurrentTime() from AquariumController
    public int getMeals() {
        return meals;
    }

    public void feed() {
        if (meals != 0) {
            meals--;
            System.out.println("Fish fed! Meals remained: " + meals);
        } else {
            System.out.println("Not enough food! Need to fill up!");
        }
    }

    public void fillUp() {
        meals = 14;
        System.out.println("Filled up successfully! Meals: " + meals);
    }

    @Override
    public String toString() {
        return "FishFeeder{" +
                "manufacturer='" + manufacturer + '\'' +
                ", model='" + model + '\'' +
                ", meals=" + meals +
                '}';
    }
}
