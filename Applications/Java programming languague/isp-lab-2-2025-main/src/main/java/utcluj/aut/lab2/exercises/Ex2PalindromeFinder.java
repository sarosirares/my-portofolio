package utcluj.aut.lab2.exercises;

import java.lang.reflect.Array;
import java.util.Arrays;
import java.util.Scanner;

/**
 * Class for finding palindromic numbers in a given range.
 * Students should implement all methods to pass the unit tests.
 */
public class Ex2PalindromeFinder {

    /**
     * Checks if a number is palindromic (reads the same backward as forward).
     *
     * @param number the number to check
     * @return true if the number is palindromic, false otherwise
     */
    public boolean isPalindromic(int number) {
        String string = number + "";
        String reversedString = new StringBuilder(string).reverse().toString();
        return string.equals(reversedString);
    }

    /**
     * Finds all palindromic numbers in the given range [a, b], inclusive.
     *
     * @param a the lower bound of the range
     * @param b the upper bound of the range
     * @return an array of all palindromic numbers in the range
     * @throws IllegalArgumentException if a > b
     */
    public int[] findPalindromes(int a, int b) {
        int[] intialResult = new int[b - a + 1];
        int c = 0;

        for (int i = a; i <= b; i++) {
            if (isPalindromic(i)) {
                intialResult[c++] = i;
            }
        }

        int[] finalResult = new int[c];

        for (int i = 0; i < c; i++) {
            finalResult[i] = intialResult[i];
        }

        return finalResult;
    }

    private int[] readInterval() {
        boolean isALessThanB = false;
        int a, b;
        Scanner scanner = new Scanner(System.in);

        do {
            System.out.println("Please enter 'a': ");
            a = scanner.nextInt();
            scanner.nextLine();
            System.out.println("Please enter 'b': ");
            b = scanner.nextInt();
            scanner.nextLine();

            if (a < b) {
                isALessThanB = true;
            } else {
                System.out.println("Please enter a valid range!");
            }
        } while (!isALessThanB);

        return new int[]{a, b};
    }

    public static void main(String[] args) {
        Ex2PalindromeFinder palindromeFinder = new Ex2PalindromeFinder();
        int[] interval = palindromeFinder.readInterval();
        int[] palindromes = palindromeFinder.findPalindromes(interval[0], interval[1]);

        System.out.printf("Beetween %d and %d thre are %d palindroms.\n", interval[0], interval[1], palindromes.length);
        System.out.println("They are: " + Arrays.toString(palindromes));
    }
}
