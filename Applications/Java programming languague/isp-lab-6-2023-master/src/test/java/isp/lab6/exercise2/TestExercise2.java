package isp.lab6.exercise2;

import org.junit.Assert;
import org.junit.Test;

public class TestExercise2 {
    @Test
    public void addTest() {
        VehicleSystem obj = new VehicleSystem();

        //checking if the Set is empty before entering any vehicle
        Assert.assertTrue(obj.getVehicles().isEmpty());

        //adding a vehicle and checking if it is added
        obj.addVehicle("testVIN", "testLP", "testMake", "testModel",1999);
        Assert.assertFalse(obj.getVehicles().isEmpty());

        //trying to add a vehicle with the same VIN
        obj.addVehicle("testVIN", "testLP2", "testMake2", "testModel2",2000);
        Assert.assertEquals(1 ,obj.getVehicles().size()); //expected 1 vehicle because it has the same VIN
    }

    @Test
    public void removeTest() {
        VehicleSystem obj = new VehicleSystem();

        //adding a vehicle and then deleting it
        obj.addVehicle("testVIN", "testLP", "testMake", "testModel",1999);
        Assert.assertEquals(1 ,obj.getVehicles().size());
        obj.removeVehicle("testVIN");
        Assert.assertEquals(0 ,obj.getVehicles().size());
    }

    @Test
    public void checkTest() {
        VehicleSystem obj = new VehicleSystem();

        Vehicle vehicle = new Vehicle("testVIN", "testLP", "testMake", "testModel",1999);
        obj.addVehicle("testVIN", "testLP", "testMake", "testModel",1999); //adding the same object into the system

        //checking if the method returns the same object
        Assert.assertEquals(vehicle, obj.checkVehicle("testVIN"));
    }
}
