package isp.lab6.exercise1;

import java.util.HashMap;

public class StudentValues {
    //attributes
    private int ID;
    private String name;
    private HashMap<String, Integer> grades;

    //constructor
    public StudentValues(int ID, String name) {
        this.ID = ID;
        this.name = name;
        this.grades = new HashMap<String, Integer>();
    }

    //getters and setters
    public int getID() {
        return ID;
    }

    public String getName() {
        return name;
    }

    public void setID(int ID) {
        this.ID = ID;
    }

    public void setName(String name) {
        this.name = name;
    }

    public HashMap<String, Integer> getGrades() {
        return grades;
    }
}
