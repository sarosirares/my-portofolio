package isp.lab7.safehome;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class SafeHome {

    public static void main(String[] args) {
        List<AccessLog> accessLogs = new ArrayList<>();
        Door door = new Door(DoorStatus.CLOSE); //initially the door is closed
        DoorLockController obj = new DoorLockController(accessLogs, door);
        Scanner scanner = new Scanner(System.in);

        String opt;
        do {
            System.out.println();
            System.out.println("\t\tMENU");
            System.out.println();
            System.out.println("1. USER " + "\n2. ADMIN" + "\n0. EXIT");
            System.out.println("\nEnter your option: ");
            opt = scanner.nextLine();
            switch (opt) {
                case "1" -> {
                    String pin;
                    System.out.println("Enter pin: ");
                    pin = scanner.nextLine();
                    try {
                        obj.enterPin(pin);
                    } catch (InvalidPinException | TooManyAttemptsException e) {
                        System.out.println(e.getMessage());
                    }
                }
                case "2" -> {
                    System.out.println();
                    System.out.println("1. Add Tenant" + "\n2. Remove Tenant" + "\n3. Access logs" + "\n0. EXIT");
                    System.out.println("\nEnter your option: ");
                    String optTenant = scanner.nextLine();
                    switch (optTenant) {
                        case "1" -> {
                            System.out.println("Enter the name of the new tenant: ");
                            String tName = scanner.nextLine();
                            System.out.println("Enter the pin of the new tenant: ");
                            String pTenant = scanner.nextLine();
                            try {
                                obj.addTenant(pTenant, tName);
                            } catch (TenantAlreadyExistsException e) {
                                System.out.println(e.getMessage());
                            }
                        }
                        case "2" -> {
                            System.out.println("Enter the name of the tenant that you want to remove: ");
                            String tName = scanner.nextLine();
                            try {
                                obj.removeTenant(tName);
                            } catch (TenantNotFoundException e) {
                                System.out.println(e.getMessage());
                            }
                        }
                        case "3" -> {
                            System.out.println();
                            System.out.println("Access Log");
                            for (AccessLog log : obj.getAccessLogs()) {
                                System.out.println(log.toString());
                            }
                        }
                        case "0" -> System.out.println();
                        default -> System.out.println("Not a valid option");
                    }
                }
                case "0" -> System.out.println();
                default -> System.out.println("Not a valid option");
            }
        } while (!opt.equals("0"));
    }
}
