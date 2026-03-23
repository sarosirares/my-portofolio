package isp.lab3.exercise3;

import java.util.Objects;

public class Vehicle {
    private String model;
    private String type;
    private int speed;
    private char fuelType;

    //4)

    private static int num;

    public Vehicle(String model, String type, int speed, char fuelType) {
        this.model = model;
        this.type = type;
        this.speed = speed;
        if (fuelType == 'D' || fuelType == 'B' ||
                fuelType == 'd' || fuelType == 'b') {
            this.fuelType = fuelType;
        } else {
            throw new IllegalArgumentException("Fuel Type can only be Diesel of Benzine!");
        }
        num++;
    }

    public void setModel(String model) {
        this.model = model;
    }

    public void setType(String type) {
        this.type = type;
    }

    public void setSpeed(int speed) {
        this.speed = speed;
    }

    public void setFuelType(char fuelType) {
        if (this.fuelType == 'D' || this.fuelType == 'B' ||
                this.fuelType == 'd' || this.fuelType == 'b') {
            this.fuelType = fuelType;
        } else {
            throw new IllegalArgumentException("Fuel Type can only be Diesel of Benzine!");
        }
    }

    public String getModel() {
        return model;
    }

    public String getType() {
        return type;
    }

    public int getSpeed() {
        return speed;
    }

    public char getFuelType() {
        return fuelType;
    }

    public static int getNum() {
        return num;
    }

    @Override
    public String toString() {
        return model +
                " (" + type + ") " +
                "speed " + speed +
                ", fuel type " + fuelType;
    }

    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        Vehicle vehicle = (Vehicle) o;
        return speed == vehicle.speed && fuelType == vehicle.fuelType && Objects.equals(model, vehicle.model) && Objects.equals(type, vehicle.type);
    }

    @Override
    public int hashCode() {
        return Objects.hash(model, type, speed, fuelType);
    }


}
