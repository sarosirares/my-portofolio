package edu.tucn.aut.isp.lab4.exercise1;

import java.time.LocalTime;

public class Exercise1 {

    public static void main(String[] args) {
        //create an object
        //if we set the current time
        AquariumController aquariumC = new AquariumController("Neptune", "Test");
        aquariumC.setCurrentTime(LocalTime.of(14,0));
        System.out.println("\nThe controller specifications: \n" + aquariumC);
        //if we do not set the current time
        AquariumController aquariumCNew = new AquariumController("HYDROS", "Model 1");
        System.out.println("\nThe controller specifications: \n" + aquariumCNew);
    }
}
