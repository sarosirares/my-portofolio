package isp.lab6.exercise1;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Scanner;

public class StudentManager {
    //attributes
    private List<StudentValues> students = new ArrayList<>();

    //methods
    Scanner scanner = new Scanner(System.in);

    public void addStudent() {
        System.out.println("Enter student's ID: ");
        int readID = scanner.nextInt();
        scanner.nextLine();
        StudentValues student = searchStudent(readID);
        if (!students.contains(student)) {
            System.out.println("Enter the student's name: ");
            String readName = scanner.nextLine();
            students.add(new StudentValues(readID, readName));
        } else {
            System.out.println("There is already a student with this ID!");
        }
    }

    public void addStudentGrades() {
        System.out.println("Enter the ID of the graded student: ");
        int readID = scanner.nextInt();
        scanner.nextLine();
        StudentValues student = searchStudent(readID);
        if (student != null) {
            System.out.println("Enter subject's name: ");
            String readSubject = scanner.nextLine();
            System.out.println("Enter grade: ");
            int readGrade = scanner.nextInt();
            scanner.nextLine();
            if (readGrade >= 0) {
                student.getGrades().put(readSubject, readGrade);
            } else {
                System.out.println("You can not enter a grade smaller than 0!");
            }
        } else {
            System.out.println("There is no student with this ID!");
        }

    }

    public void removeStudent() {
        System.out.println("Enter the student's ID that you want to remove: ");
        int readID = scanner.nextInt();
        scanner.nextLine();
        StudentValues student = searchStudent(readID);
        if (student != null) {
            students.remove(student);
            System.out.println("Student removed!");
        } else {
            System.out.println("There is no student with this ID!");
        }

    }

    public void updateStudent() {
        System.out.println("Enter the student's ID that you want to update: ");
        int readID = scanner.nextInt();
        scanner.nextLine();
        StudentValues student = searchStudent(readID);
        if (student != null) {
            System.out.println("Enter the new name of the student: ");
            String newName = scanner.nextLine();
            student.setName(newName);
        } else {
            System.out.println("There is no student with this ID!");
        }

    }

    public void averageGrade() {
        double avg = 0.0;
        System.out.println("Enter the student's ID of which you want to calculate the average grade: ");
        int readID = scanner.nextInt();
        scanner.nextLine();
        StudentValues student = searchStudent(readID);
        if (student != null) {
            int sum = 0;
            for (int grade : student.getGrades().values()) {
                sum += grade;
            }
            avg = (double) sum / student.getGrades().size();
            System.out.println("The average of the grades is: " + avg);
        } else {
            System.out.println("There is no student with this ID!");
        }
    }

    public void displayStudents() {
        for (StudentValues student : students) {
            System.out.println("ID: " + student.getID());
            System.out.println("Name: " + student.getName());
            System.out.println("Grades: " + student.getGrades());
            System.out.println("--------------------------------");
        }
        if (students.isEmpty()) {
            System.out.println("There is no student in the list!");
        }
    }


    //creating a method that searches the student with a specific ID introduced by keyboard
    public StudentValues searchStudent(int readID) {
        for (StudentValues student : students) {
            if (student.getID() == readID) {
                return student;
            }
        }
        return null; //if the student is not found, return null
    }

    public void menu() {
        int opt;
        do {
            System.out.println("\n\t\tMENU");
            System.out.println("1. Add student");
            System.out.println("2. Add grades");
            System.out.println("3. Remove student");
            System.out.println("4. Update student");
            System.out.println("5. Calculate average");
            System.out.println("6. Display students");
            System.out.println("7. EXIT");
            System.out.println("\nEnter your option: ");
            opt = scanner.nextInt();
            scanner.nextLine();
            switch (opt) {
                case 1 -> addStudent();
                case 2 -> addStudentGrades();
                case 3 -> removeStudent();
                case 4 -> updateStudent();
                case 5 -> averageGrade();
                case 6 -> displayStudents();
                case 7 -> System.out.println();
                default -> System.out.println("Not a valid option!");
            }
        } while (opt < 7);
    }

    //using this getter for the unit test
    public List<StudentValues> getStudents() {
        return students;
    }
}
