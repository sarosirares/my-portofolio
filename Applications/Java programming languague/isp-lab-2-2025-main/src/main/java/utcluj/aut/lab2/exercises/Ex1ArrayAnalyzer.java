package utcluj.aut.lab2.exercises;
/**
 * Class for generating and analyzing arrays of random integers.
 * Students should implement all methods to pass the unit tests.
 */

import java.util.*;

public class Ex1ArrayAnalyzer {

    /**
     * Generates an array of random size between 25 and 150,
     * filled with random integers between -100 and 100.
     *
     * @return an array of random integers
     */
    public int[] generateArray() {
        // TODO: Implement this method
        // 1. Generate a random size between 25 and 150

        Random random = new Random();
        int randomNumber = random.nextInt(126) + 25; // Between 25 and 150

        // 2. Create an array of that size

        int[] randNum = new int[randomNumber];

        // 3. Fill the array with random integers between -100 and 100

        for (int i = 0; i < randomNumber; i++) {

            randNum[i] = random.nextInt(201) - 100; // Between -100 and 100
        }

        // 4. Return the array
        return randNum;
    }

    /**
     * Calculates the average value of all elements in the given array.
     *
     * @param array the array to analyze
     * @return the average value of all elements
     */
    public double calculateAverage(int[] array) {
        // TODO: Implement this method
        // 1. Calculate the sum of all elements in the array

        double sum = 0;

        for (int i = 0; i < array.length; i++) {

            sum = sum + array[i];

        }

        // 2. Return the average (sum divided by length)

        if (array.length != 0) {

            System.out.println("\nThe sum is: " + sum);
            return sum / array.length;

        } else {

            // 3. Handle edge case of empty array
            return 0.0;

        }
    }

    /**
     * Counts how many elements are above and below the given average.
     *
     * @param array   the array to analyze
     * @param average the average value to compare against
     * @return an array of 2 integers: [countAbove, countBelow]
     */
    public int[] countAboveBelowAverage(int[] array, double average) {
        // TODO: Implement this method

        int[] result = new int[2];

        // 1. Count elements above the average

        for (int i = 0; i < array.length; i++) {

            if (array[i] > average) {

                result[0]++; //above
            } else if (array[i] < average) {

                // 2. Count elements below the average

                result[1]++; //below

            }
        }

        // 3. Return both counts as an array [countAbove, countBelow]

        return result;
    }

    public static void main(String[] args) {
        // TODO: Implement the main method

        // 1. Create an instance of ArrayAnalyzer

        Ex1ArrayAnalyzer ArrayAnalyzer = new Ex1ArrayAnalyzer();

        // 2. Generate a random array

        int[] rArray = ArrayAnalyzer.generateArray();

        System.out.printf("\nThere are %d elements in the next array: ", rArray.length);

        for (int i = 0; i < rArray.length; i++) {

            System.out.printf("%d; ", rArray[i]);

        }

        // 3. Calculate the average of the array

        double arrayAverage = ArrayAnalyzer.calculateAverage(rArray);

        // 4. Count elements above and below the average

        int[] countElem = ArrayAnalyzer.countAboveBelowAverage(rArray, arrayAverage);

        // 5. Print the results

        System.out.printf("The average of the array is: %f and there are %d elements above average and %d elements below average.\n", arrayAverage, countElem[0], countElem[1]);
    }
}
