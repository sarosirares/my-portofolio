package isp.lab8.airways;

import java.io.IOException;
import java.util.Scanner;

public class Exercise {
    public static void main(String[] args) {
        FlightManagementSystem obj = new FlightManagementSystem();
        Scanner scanner = new Scanner(System.in);

        int menuOpt;
        do {
            System.out.println();
            System.out.println("1. Create Route");
            System.out.println("2. Add Waypoints");
            System.out.println("3. Total distance of a Route");
            System.out.println("4. Route Details");
            System.out.println("5. Delete Route");
            System.out.println("6. Display all Routes");
            System.out.println("0. EXIT");
            System.out.println("\nEnter your option: ");
            menuOpt = scanner.nextInt();
            scanner.nextLine();
            switch (menuOpt) {
                case 1 -> {
                    System.out.println("Enter Route name: ");
                    String route = scanner.nextLine();
                    obj.createRoute(route);
                }
                case 2 -> {
                    System.out.println("Enter Route name: ");
                    String route = scanner.nextLine();
                    //even if this if structure is also in the method addWaypoint
                    //I added it here to stop the adding operation if the route is not created
                    if (obj.checkRoute(route)) {
                        System.out.println("Enter Waypoint's name: ");
                        String wpName = scanner.nextLine();
                        //if the waypoint already exists in the system it will reuse that waypoint
                        //this helps to not create the same waypoint twice
                        if (obj.getWpNames().contains(wpName)) {
                            try {
                                obj.addWaypoint(new Waypoint(wpName), route);
                            } catch (IOException e) {
                                System.out.println("Error!");
                            }
                        } else {
                            System.out.println("Enter Waypoint's latitude: ");
                            double wpLat = scanner.nextDouble();
                            System.out.println("Enter Waypoint's longitude: ");
                            double wpLong = scanner.nextDouble();
                            System.out.println("Enter Waypoint's altitude: ");
                            int wpAlt = scanner.nextInt();
                            try {
                                obj.addWaypoint(new Waypoint(wpName, wpLat, wpLong, wpAlt), route);
                            } catch (IOException e) {
                                System.out.println("Error!");
                            }
                        }
                    } else {
                        System.out.println("Route does not exist!");
                    }
                }
                case 3 -> {
                    System.out.println("Enter Route name: ");
                    String route = scanner.nextLine();
                    try {
                        System.out.println("The total distance of a route is: " + obj.totalDistance(obj.readWaypoints(route)));
                    } catch (IOException e) {
                        System.out.println("Error!");
                    }
                }
                case 4 -> {
                    System.out.println("Enter Route name: ");
                    String route = scanner.nextLine();
                    try {
                        obj.displayRoute(route);
                    } catch (IOException e) {
                        System.out.println("Error!");
                    }
                }
                case 5 -> {
                    System.out.println("Enter Route name: ");
                    String route = scanner.nextLine();
                    obj.deleteRoute(route);
                }
                case 6 -> obj.displayAvailable();
                case 0 -> System.out.println();
                default -> System.out.println("Not a valid option!");
            }
        } while (menuOpt != 0);


//        Waypoint p1 = new Waypoint("LRCL", 46.7852, 23.6862, 415);
//        Waypoint p2 = new Waypoint("TASOD", 47.0548, 23.9212, 10460);
//        Waypoint p3 = new Waypoint("SOPAV", 46.9804, 24.7365, 10900);
//        Waypoint p4 = new Waypoint("BIRGU", 45.9467, 26.0217, 10200);
//        Waypoint p5 = new Waypoint("LROP", 44.5711, 26.0858, 106);
//
//        String route1 = "LRCL-LROP";
//        obj.createRoute(route1);
//        try {
//            obj.addWaypoint(p1, route1);
//            obj.addWaypoint(p2, route1);
//            obj.addWaypoint(p3, route1);
//            obj.addWaypoint(p4, route1);
//            obj.addWaypoint(p5, route1);
//            obj.displayRoute(route1);
//        } catch (IOException e) {
//            System.out.println("IOException");
//        }
//
//        obj.deleteRoute(route1);
    }
}
