package isp.lab6.exercise1;

import org.junit.Assert;
import org.junit.Test;

import java.util.SimpleTimeZone;

public class TestExercise1 {
    @Test
    public void addTest() {
        StudentManager_v2 obj = new StudentManager_v2();

        //testing if the list is empty before calling the method
        Assert.assertEquals(0, obj.getStudents().size());

        //testing if the function is able to add students into the list
        obj.addStudent(1, "test1");
        Assert.assertEquals(1, obj.getStudents().size());

        //testing if we add a student with the same ID works
        obj.addStudent(1, "test2");
        Assert.assertEquals(1, obj.getStudents().size());

        //adding another student
        obj.addStudent(2, "test2");
        Assert.assertEquals(2, obj.getStudents().size());
    }

    @Test
    public void addGradeTest() {
        StudentManager_v2 obj = new StudentManager_v2();

        obj.addStudent(1, "test");

        //testing if the Map is empty before calling the method
        Assert.assertEquals(0, obj.getStudents().getFirst().getGrades().size());

        //testing if the method works
        obj.addStudentGrades(1, "Math", 10);
        Assert.assertEquals(1, obj.getStudents().getFirst().getGrades().size());

        //testing if we can add a grade smaller than 0
        obj.addStudentGrades(1, "Math", -8);
        Assert.assertEquals(1, obj.getStudents().getFirst().getGrades().size());
    }

    @Test
    public void removeTest() {
        StudentManager_v2 obj = new StudentManager_v2();

        obj.addStudent(1, "test");

        //testing to remove a nonexistent student
        obj.removeStudent(0);
        Assert.assertEquals(1, obj.getStudents().size());

        //testing if the method works
        obj.removeStudent(1);
        Assert.assertEquals(0, obj.getStudents().size());
    }

    @Test
    public void updateTest() {
        StudentManager_v2 obj = new StudentManager_v2();

        //testing if the name is saved correctly
        obj.addStudent(1, "test");
        Assert.assertEquals("test", obj.getStudents().getFirst().getName());

        //testing if the name is updated after calling the method
        obj.updateStudent(1, "updatedTest");
        Assert.assertEquals("updatedTest", obj.getStudents().getFirst().getName());
    }
}