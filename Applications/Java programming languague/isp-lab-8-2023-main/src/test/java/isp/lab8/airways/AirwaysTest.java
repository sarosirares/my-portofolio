package isp.lab8.airways;

import org.junit.Assert;
import org.junit.Before;
import org.junit.Test;

import javax.swing.plaf.PanelUI;

import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

import static org.junit.Assert.*;

public class AirwaysTest {
    @Test
    public void createRouteTest() {
        FlightManagementSystem obj = new FlightManagementSystem();

        String route = "test";
        obj.createRoute(route);

        Assert.assertTrue(obj.getFiles("routes").contains(route));
    }

    @Test
    public void addWPTest() {
        FlightManagementSystem obj = new FlightManagementSystem();

        String route = "test";
        obj.createRoute(route);

        Waypoint p1 = new Waypoint("LRCL", 46.7852, 23.6862, 415);

        try {
            obj.addWaypoint(p1, route);
        } catch (IOException e) {
            System.out.println("IOException");
        }

        try {
            Assert.assertTrue(obj.readWaypoints(route).contains(p1));
        } catch (IOException e) { }

        Waypoint p2 = new Waypoint("TASOD", 47.0548, 23.9212, 10460);
        try {
            obj.addWaypoint(p2, route);
        } catch (IOException e) {
            System.out.println("IOException");
        }

        try {
            Assert.assertTrue(obj.readWaypoints(route).contains(p2));
        } catch (IOException e) { }
    }

    @Test
    public void deleteTest() {
        FlightManagementSystem obj = new FlightManagementSystem();

        String route = "test";
        obj.createRoute(route);

        Assert.assertTrue(obj.getFiles("routes").contains(route));

        obj.deleteRoute(route);

        Assert.assertFalse(obj.getFiles("routes").contains(route));
    }

    @Test
    public void totalDTest() {
        FlightManagementSystem obj = new FlightManagementSystem();

        String route = "test";
        obj.createRoute(route);
        Waypoint p1 = new Waypoint("LRCL", 46.7852, 23.6862, 415);
        Waypoint p2 = new Waypoint("TASOD", 47.0548, 23.9212, 10460);
        Waypoint p3 = new Waypoint("SOPAV", 46.9804, 24.7365, 10900);
        try {
            obj.addWaypoint(p1, route);
            obj.addWaypoint(p2, route);
            obj.addWaypoint(p3, route);
        } catch (IOException e) {
            System.out.println("IOException");
        }

        try {
            Assert.assertEquals(97.24746630719872, obj.totalDistance(obj.readWaypoints(route)), 0.001);
        } catch (IOException e) { }
    }
}
