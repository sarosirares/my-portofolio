package isp.lab8.airways;

import java.util.Objects;

/**
 * Example waypoint class which can be extended to be used in implementation of the exercise. Add constructor, getters, setters, etc.
 */
public class Waypoint {
    //attributes
    private int index;
    private String name;
    private double latitude;
    private double longitude;
    private int altitude;
    private static int contor = 1;

    //constructor
    public Waypoint() {
    }

    public Waypoint(String name) { //used for addWaypoint method
        this.name = name;
    }

    public Waypoint(String name, double latitude, double longitude, int altitude) {
        this.index = contor++;
        this.name = name;
        this.latitude = latitude;
        this.longitude = longitude;
        this.altitude = altitude;
    }

    //methods
    public int getIndex() {
        return index;
    }

    public String getName() {
        return name;
    }

    public double getLatitude() {
        return latitude;
    }

    public double getLongitude() {
        return longitude;
    }

    public int getAltitude() {
        return altitude;
    }

    @Override
    public String toString() {
        return "Waypoint{" +
                "index=" + index +
                ", name='" + name + '\'' +
                ", latitude=" + latitude +
                ", longitude=" + longitude +
                ", altitude=" + altitude +
                '}';
    }

    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        Waypoint waypoint = (Waypoint) o;
        return Objects.equals(name, waypoint.name);
    }

    @Override
    public int hashCode() {
        return Objects.hashCode(name);
    }
}
