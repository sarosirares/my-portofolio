package isp.lab8.airways;

import com.fasterxml.jackson.databind.ObjectMapper;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.stream.Collectors;

public class FlightManagementSystem {
    //attributes
    private ObjectMapper objectMapper = new ObjectMapper();
    List<String> wpNames = new ArrayList<>(); //this list contains all waypoints names stored in the system

    //constructor
    public FlightManagementSystem() {
        this.wpNames = searchWPNames();
    }

    //methods
    public void createRoute(String folderName) {
        String path = "routes\\" + folderName;
        File d = new File(path);
        if (!checkRoute(folderName)) {
            d.mkdirs();
            System.out.println("Route added!");
        } else {
            System.out.println("Route already exists!");
        }
    }

    public void addWaypoint(Waypoint wp, String folderName) throws IOException {
        String path = "routes\\" + folderName;
        wpNames = searchWPNames();
        if (!wpNames.contains(wp.getName())) {
            wpNames.add(wp.getName()); //storing the waypoints names
        }
        if (checkRoute(folderName)) {
            List<String> routes = getFiles("routes");
            for (String route : routes) {
                List<Waypoint> waypoints = readWaypoints(route);
                for (Waypoint waypoint : waypoints) {
                    if (wp.equals(waypoint)) {
                        System.out.println("This waypoint already exists in the system and it will be reused");
                        wp = waypoint;
                    }
                }
            }
            objectMapper.writeValue(new FileWriter(path + "\\" + "wp" + wp.getIndex()), wp);
            System.out.println("Waypoint was added!");
        } else {
            System.out.println("The route does not exist yet!");
        }
    }

    //this method is from WaypointDistanceCalculator
    public double distanceWP(double lat1, double lon1, double lat2, double lon2) {
        int earthRadius = 6371; // Radius of the Earth in kilometers
        double dLat = Math.toRadians(lat2 - lat1);
        double dLon = Math.toRadians(lon2 - lon1);
        double a = Math.sin(dLat / 2) * Math.sin(dLat / 2) +
                Math.cos(Math.toRadians(lat1)) * Math.cos(Math.toRadians(lat2)) *
                        Math.sin(dLon / 2) * Math.sin(dLon / 2);
        double c = 2 * Math.atan2(Math.sqrt(a), Math.sqrt(1 - a));
        double distance = earthRadius * c;
        return distance;
    }

    public double totalDistance(List<Waypoint> waypoints) {
        double total = 0.0;
        for (int i = 0; i < waypoints.size() - 1; i++) {
            Waypoint wp1 = waypoints.get(i);
            Waypoint wp2 = waypoints.get(i + 1);
            total += distanceWP(wp1.getLatitude(), wp1.getLongitude(), wp2.getLatitude(), wp2.getLongitude());
        }
        return total;
    }

    //this returns a list with all waypoints from a certain folder
    public List<Waypoint> readWaypoints(String folderName) throws IOException {
        String path = "routes\\" + folderName;
        List<Waypoint> waypoints = new ArrayList<>();
        if (checkRoute(folderName)) {
            List<String> files = getFiles(path);
            for (String file : files) {
                String content = readAllFileLines(path + "\\" + file).stream().collect(Collectors.joining("\n"));
                Waypoint wp = objectMapper.readValue(content, Waypoint.class);
                waypoints.add(wp);
            }
        } else {
            System.out.println("The route does not exist yet!");
            return null;
        }
        return waypoints;
    }

    //this display the total distance of the route and the waypoints of it
    public void displayRoute(String folderName) throws IOException {
        String path = "routes\\" + folderName;
        if (checkRoute(folderName)) {
            List<Waypoint> waypoints = readWaypoints(folderName);
            System.out.println("The total distance of the route " + folderName + " is: " + totalDistance(waypoints));
            System.out.println("The route's waypoints are: ");
            for (Waypoint wp : waypoints) {
                System.out.println(wp);
            }
        } else {
            System.out.println("The route does not exist yet!");
        }
    }

    public void deleteRoute(String folderName) {
        String path = "routes\\" + folderName;
        File d = new File(path);
        if (checkRoute(folderName)) {
            File[] files = d.listFiles();
            for (File file : files) {
                file.delete();
            }
            d.delete();
            System.out.println("Route deleted!");
        } else {
            System.out.println("The route does not exist yet!");
        }
    }

    //this displays all the routes stored in the system
    public void displayAvailable() {
        String path = "routes";
        File d = new File(path);
        if (d.exists() && d.isDirectory()) {
            System.out.println("All the available routes are: ");
            System.out.println();
            getFiles(path).stream().forEach(s -> System.out.println(s));
        } else {
            System.out.println("The folder \"routes\" does not exist yet!");
        }
    }

    //this method is from FileReadUtil and returns a list with the content of a file
    public List<String> readAllFileLines(String file) throws IOException {
        Path path = Paths.get(file);
        return Files.readAllLines(path, StandardCharsets.UTF_8);
    }

    //this method is from FilesAndFoldersUtil and returns a list that contains all the names of the folders form root folder
    public List<String> getFiles(String folderName) {
        File file = null;
        file = new File(folderName);
        return Arrays.asList(file.list());
    }

    //checking if route already exists
    public boolean checkRoute(String folderName) {
        String path = "routes\\" + folderName;
        File d = new File(path);
        return d.exists() && d.isDirectory();
    }

    //used to update the list with all the waypoint names to be sure that the same waypoint is not created twice
    public List<String> searchWPNames() {
        List<String> wpNames = new ArrayList<>();
        List<String> routes = getFiles("routes");
        for (String route : routes) {
            try {
                List<Waypoint> waypoints = readWaypoints(route);
                for (Waypoint waypoint : waypoints) {
                    wpNames.add(waypoint.getName());
                }
            } catch (IOException e) {
                System.out.println("Error!");
            }
        }
        return wpNames;
    }

    public List<String> getWpNames() {
        return wpNames;
    }
}
