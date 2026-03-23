package utcluj.aut.lab2.exercises;
/**
 * Class for calculating factorials using recursive and non-recursive approaches.
 * Students should implement all methods to pass the unit tests.
 */

import java.util.Scanner;

public class Ex3FactorialCalculator {

    /**
     * Calculates the factorial of n using recursion.
     *
     * @param n the number to calculate factorial for
     * @return the factorial of n
     * @throws IllegalArgumentException if n is negative
     */
    public long recursiveFactorial(int n) {
        // TODO: Implement this method using recursion
        // 1. Validate that n is not negative, throw IllegalArgumentException if it is

        if (n < 0) {
            throw new IllegalArgumentException("The number n must be a positive number!");
        } else {

            // 2. Implement the recursive algorithm for factorial
            // 3. Remember the base case (0! = 1)
            if (n == 0) {

                return 1;
            }

            return n * recursiveFactorial(n - 1);
        }
    }

    /**
     * Calculates the factorial of n using a non-recursive approach.
     *
     * @param n the number to calculate factorial for
     * @return the factorial of n
     * @throws IllegalArgumentException if n is negative
     */
    public long nonRecursiveFactorial(int n) {
        // TODO: Implement this method using a loop (not recursion)
        // 1. Validate that n is not negative, throw IllegalArgumentException if it is

        if (n < 0) {
            throw new IllegalArgumentException("The number n must be a positive number!");
        } else {

            // 2. Implement the recursive algorithm for factorial
            // 3. Remember the base case (0! = 1)

            long result = 1;

            for (int i = 1; i <= n; i++) {
                result *= i;
            }
            return result;
        }
    }

    /**
     * Compares the execution time of both factorial methods.
     *
     * @param n the number to calculate factorial for
     * @return an array with [recursiveTime, nonRecursiveTime] in nanoseconds
     */
    public long[] compareExecutionTime(int n) {
        // TODO: Implement this method

        long[] time = new long[2];
        long startTime;
        long stopTime;

        // 1. Measure the execution time of recursiveFactorial

        startTime = System.nanoTime();
        recursiveFactorial(n);
        stopTime = System.nanoTime();
        time[0] = stopTime - startTime;

        // 2. Measure the execution time of nonRecursiveFactorial

        startTime = System.nanoTime();
        nonRecursiveFactorial(n);
        stopTime = System.nanoTime();
        time[1] = stopTime - startTime;

        // 3. Return both times in an array

        return time;
    }

    public static void main(String[] args) {
        // TODO: Implement the main method
        // 1. Create an instance of FactorialCalculator

        Ex3FactorialCalculator FactorialCalculator = new Ex3FactorialCalculator();

        // 2. Read an integer input from the user

        Scanner scanner = new Scanner(System.in);

        System.out.println("Please enter a positive number for n: ");
        int n = scanner.nextInt();
        scanner.nextLine();

        // 3. Calculate the factorial using both recursive and non-recursive methods

        long recursiveResult = FactorialCalculator.recursiveFactorial(n);
        long nonRecursiveResult = FactorialCalculator.nonRecursiveFactorial(n);

        // 4. Compare the execution times of both methods

        long[] executionTime = FactorialCalculator.compareExecutionTime(n);

        // 5. Print the results (factorials and execution times)

        System.out.println("The result of the recursive function is " + recursiveResult + " and the result of the non-recursive function is " + nonRecursiveResult);
        System.out.println("The execution time of the recursive function is " + executionTime[0] + " and the execution time of the non-recursive function is " + executionTime[1]);


        scanner.close();
    }
}
