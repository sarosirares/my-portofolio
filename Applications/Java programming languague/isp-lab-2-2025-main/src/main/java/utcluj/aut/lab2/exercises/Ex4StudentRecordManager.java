package utcluj.aut.lab2.exercises;

/**
 * Application that manages student records using only Strings and arrays.
 * The program allows users to input student records, filter them by grade,
 * and sort them by different criteria.
 * Students should implement all methods to complete the exercise.
 */

import java.util.*;

public class Ex4StudentRecordManager {

    /**
     * Main method that runs the application.
     *
     * @param args command line arguments (not used)
     */
    public static void main(String[] args) {
        // TODO: Implement this method
        // 1. Create a scanner to read user input

        Scanner scanner = new Scanner(System.in);

        // 2. Prompt the user to enter student records (name,age,grade) on separate lines


        System.out.println("Please enter the number of records you want to introduce: ");
        int n = scanner.nextInt();
        scanner.nextLine();

        System.out.println("Please enter student records (name, age, grade) on separate lines (when you want to stop just enter \"0\"): ");

        // 3. Read and store the records until the user indicates they're done

//        String[][] inputRecords = null;
//        String[] options = new String[3];
//        String input;
//        int i = 0;
//        while(!(input = scanner.nextLine()).equalsIgnoreCase("0")){
//            inputRecords[i] = parseStudentRecord(input);
//            i++;
//        }

        String[][] inputRecords = new String[n][3];
        String[] options = new String[3];
        String input;
        int i = 0;
        while (i < n) {
            input = scanner.nextLine();
            inputRecords[i] = parseStudentRecord(input);
            i++;
        }

        // 4. Allow the user to filter records by minimum grade

        options = getFilterAndSortOptions();

        // 5. Allow the user to sort the filtered records

        String[][] orderedRecords = new String[n][3];

        if (options[2].equalsIgnoreCase("ascending")) {
            orderedRecords = sortRecords(inputRecords, options[1], true);
        } else if (options[2].equalsIgnoreCase("descending")) {
            orderedRecords = sortRecords(inputRecords, options[1], false);
        }

        // 6. Display the filtered and sorted records
        System.out.println("\nThe records filtered by minimum grade " + options[0] + " are: ");
        displayRecords(filterByGrade(inputRecords, options[0]));

        System.out.println("\nThe records sorted by " + options[1] + " in " + options[2] + " order are: ");
        displayRecords(orderedRecords);

    }

    /**
     * Parses a student record from a string in the format "name,age,grade".
     *
     * @param record the record string to parse
     * @return a string array with [name, age, grade] or null if invalid format
     */
    public static String[] parseStudentRecord(String record) {
        // TODO: Implement this method
        // 1. Split the record by commas

        String[] sRecord = record.split(",");

        // 2. Validate that there are exactly 3 parts

        if (sRecord.length == 3) {
            // 3. Return a string array with [name, age, grade]

            return sRecord;
        } else {
            // 4. Return null or handle invalid formats appropriately
            throw new IllegalArgumentException("Invalid format for the record!");
//            return null;
        }
    }

    /**
     * Filters student records by a minimum grade threshold.
     *
     * @param records  array of student records, each record is [name, age, grade]
     * @param minGrade the minimum grade threshold as a string
     * @return array of filtered student records
     */
    public static String[][] filterByGrade(String[][] records, String minGrade) {
        // TODO: Implement this method
        // 1. Parse the minimum grade threshold to an integer

        int intMinGrade = Integer.parseInt(minGrade);

        // 2. Count how many records meet the criteria

        int counter = 0;

        for (int i = 0; i < records.length; i++) {

            if (Integer.parseInt(records[i][2]) >= intMinGrade) {

                counter++;
            }

        }

        // 3. Create a new array of arrays to hold the filtered records

        String[][] filteredRecords = new String[counter][3];

        // 4. Add records with grade >= minGrade to the new array

        counter = 0;
        for (int i = 0; i < records.length; i++) {

            if (Integer.parseInt(records[i][2]) >= intMinGrade) {

                filteredRecords[counter] = records[i];
                counter++;
            }

        }

        // 5. Return the filtered records

        return filteredRecords;
    }

    /**
     * Sorts student records by the given criteria.
     *
     * @param records   array of student records, each record is [name, age, grade]
     * @param sortBy    the sorting criteria ("name", "age", or "grade")
     * @param ascending true for ascending order, false for descending
     * @return a new array with sorted student records
     */
    public static String[][] sortRecords(String[][] records, String sortBy, boolean ascending) {
        // TODO: Implement this method
        // 1. Create a copy of the records array to avoid modifying the original

        String[][] copyRecords = records.clone();

        // 2. Determine which index to sort by based on sortBy (0 for name, 1 for age, 2 for grade)

        int index = 0;
        if (sortBy.equalsIgnoreCase("name")) {
            index = 0;
        } else if (sortBy.equalsIgnoreCase("age")) {
            index = 1;
        } else if (sortBy.equalsIgnoreCase("grade")) {
            index = 2;
        }

        // 3. Implement a sorting algorithm (e.g., bubble sort) to sort the records

        boolean swap;
        String[] temp;

        switch (index) {
            case 0:
                for (int i = 0; i < copyRecords.length - 1; i++) {
                    swap = false;
                    for (int j = 0; j < copyRecords.length - i - 1; j++) {
                        if (copyRecords[j][0].compareTo(copyRecords[j + 1][0]) > 0) {
                            temp = copyRecords[j];
                            copyRecords[j] = copyRecords[j + 1];
                            copyRecords[j + 1] = temp;
                            swap = true;
                        }
                    }
                    if (!swap) {
                        break;
                    }

                }
                break;

            case 1:
                for (int i = 0; i < copyRecords.length - 1; i++) {
                    swap = false;
                    for (int j = 0; j < copyRecords.length - i - 1; j++) {
                        if (copyRecords[j][1].compareTo(copyRecords[j + 1][1]) > 0) {
                            temp = copyRecords[j];
                            copyRecords[j] = copyRecords[j + 1];
                            copyRecords[j + 1] = temp;
                            swap = true;
                        }
                    }
                    if (!swap) {
                        break;
                    }

                }
                break;
            case 2:
                for (int i = 0; i < copyRecords.length - 1; i++) {
                    swap = false;
                    for (int j = 0; j < copyRecords.length - i - 1; j++) {
                        if (copyRecords[j][2].compareTo(copyRecords[j + 1][2]) > 0) {
                            temp = copyRecords[j];
                            copyRecords[j] = copyRecords[j + 1];
                            copyRecords[j + 1] = temp;
                            swap = true;
                        }
                    }
                    if (!swap) {
                        break;
                    }

                }
                break;
        }

        // 4. If ascending is false, reverse the sorting logic

        if (!ascending)
            for (int i = 0; i < copyRecords.length / 2; i++) {
                temp = copyRecords[i];
                copyRecords[i] = copyRecords[copyRecords.length - i - 1];
                copyRecords[copyRecords.length - i - 1] = temp;
            }

        // 5. Return the sorted array

        return copyRecords;
    }

    /**
     * Displays student records in a formatted way.
     *
     * @param records array of student records to display
     */
    public static void displayRecords(String[][] records) {
        // TODO: Implement this method
        // 1. Check if there are any records to display

        if (records.length != 0) {
            // 2. Display a header for the output

            System.out.println("\nName\tAge\t\tGrade\n");

            // 3. Iterate through each record and format it for display
            // 4. Display each record on a separate line

            for (int i = 0; i < records.length; i++) {
                System.out.printf("%s, %s, %s\n", records[i][0], records[i][1], records[i][2]);
            }
        }
    }

    /**
     * Prompts for and reads user input for filtering and sorting options.
     *
     * @return a string array with [minGrade, sortBy, ascending]
     */
    public static String[] getFilterAndSortOptions() {
        // TODO: Implement this method

        String[] filterOptions = new String[3];

        // 1. Create a scanner to read user input

        Scanner scanner = new Scanner(System.in);

        // 2. Prompt the user for minimum grade threshold

        System.out.println("Please introduce the minimum grade threshold for which the records are shown: ");
        filterOptions[0] = scanner.nextLine();

        // 3. Prompt the user for sorting criteria (name, age, or grade)

        System.out.println("Please introduce the sorting criteria (name, age, or grade) : ");
        filterOptions[1] = scanner.nextLine();

        // 4. Prompt the user for sorting order (ascending or descending)

        System.out.println("Please introduce the sorting order (ascending or descending) : ");
        filterOptions[2] = scanner.nextLine();

        // 5. Return the options as a string array
        return filterOptions;
    }

    /**
     * Checks if a string can be parsed as an integer.
     *
     * @param str the string to check
     * @return true if the string is a valid integer, false otherwise
     */
    public static boolean isInteger(String str) {
        // TODO: Implement this method
        // 1. Try to parse the string as an integer
        // 2. Return true if successful, false if it causes an exception
        try {
            Integer.parseInt(str);
        } catch (NumberFormatException e) {
            return false;
        }
        return true;
    }
}