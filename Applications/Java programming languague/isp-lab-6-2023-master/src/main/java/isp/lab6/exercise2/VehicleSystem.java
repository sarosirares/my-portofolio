package isp.lab6.exercise2;

import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class VehicleSystem {
    //attributes
    private Set<Vehicle> vehicles = new HashSet<>();

    //methods
    Scanner scanner = new Scanner(System.in);

    public void addVehicle(String readVIN, String readLicenseP, String readMake, String readModel, int readYear) {
        Vehicle vehicle = new Vehicle(readVIN, readLicenseP, readMake, readModel, readYear);
        //because I overrode equals() and hashCode(), when add() method is called, it returns true if no other vehicle
        //has the same VIN as the new vehicle added, and false otherwise. It also adds only when it returns true
        if (vehicles.add(vehicle)) {
            System.out.println("Vehicle added!");
        } else {
            System.out.println("There is already a vehicle with this VIN registered!");
        }
    }

    public void removeVehicle(String readVIN) {
        Vehicle vehicle = checkVehicle(readVIN);
        if (vehicles.contains(vehicle)) {
            vehicles.remove(vehicle);
            System.out.println("Vehicle removed!");
        } else {
            System.out.println("There is no registered vehicle with this VIN!");
        }
    }

    public Vehicle checkVehicle(String readVIN) {
        for (Vehicle vehicle : vehicles) {
            if (vehicle.getVIN().equals(readVIN)) {
                return vehicle;
            }
        }
        return null;
    }

    public void displayVehicles() {
        if (vehicles.isEmpty()) {
            System.out.println("There is no vehicle registered!");
        } else {
            System.out.println("All registered vehicles:");
            for (Vehicle vehicle : vehicles) {
                System.out.println(vehicle.toString());
                System.out.println();
            }
        }
    }

    public void menu() {
        int opt;
        do {
            System.out.println("\n\t\tMENU");
            System.out.println("1. Add a vehicle");
            System.out.println("2. Remove a vehicle");
            System.out.println("3. Check vehicle");
            System.out.println("4. Display all vehicles");
            System.out.println("5. EXIT");
            System.out.println("\nEnter your option: ");
            opt = scanner.nextInt();
            scanner.nextLine();
            switch (opt) {
                case 1 -> {
                    System.out.println("Enter vehicle's VIN: ");
                    String readVIN = scanner.nextLine();
                    System.out.println("Enter the vehicle's license plate: ");
                    String readLicenseP = scanner.nextLine();
                    System.out.println("Enter the vehicle's make: ");
                    String readMake = scanner.nextLine();
                    System.out.println("Enter the vehicle's model: ");
                    String readModel = scanner.nextLine();
                    System.out.println("Enter vehicle's year: ");
                    int readYear = scanner.nextInt();
                    scanner.nextLine();
                    addVehicle(readVIN, readLicenseP, readMake, readModel, readYear);
                }
                case 2 -> {
                    System.out.println("Enter vehicle's VIN that you want to delete: ");
                    String readVIN = scanner.nextLine();
                    removeVehicle(readVIN);
                }
                case 3 -> {
                    System.out.println("Enter vehicle's VIN that you want to check: ");
                    String readVIN = scanner.nextLine();
                    Vehicle vehicle = checkVehicle(readVIN);
                    if (vehicle != null) {
                        System.out.println("Details: " + vehicle.toString());
                    } else {
                        System.out.println("There is no vehicle with that VIN registered!");
                    }
                }
                case 4 -> displayVehicles();
                case 5 -> System.out.println();
                default -> System.out.println("Not a valid option!");
            }
        } while (opt < 5);
    }

    public Set<Vehicle> getVehicles() {
        return vehicles;
    }
}
