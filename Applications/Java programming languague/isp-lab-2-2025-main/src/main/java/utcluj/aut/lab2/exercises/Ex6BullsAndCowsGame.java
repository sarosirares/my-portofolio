package utcluj.aut.lab2.exercises;

import java.awt.*;
import java.util.Random;
import java.util.Scanner;

/**
 * Class implementing the Bulls and Cows number guessing game.
 * Students should implement all methods to pass the unit tests.
 */
public class Ex6BullsAndCowsGame {
    private String secretNumber;

    /**
     * Creates a new game with a random secret number.
     */
    public Ex6BullsAndCowsGame() {
        this.secretNumber = generateSecretNumber();
    }

    /**
     * Creates a new game with the specified secret number (for testing).
     *
     * @param secretNumber the secret number to use
     */
    public Ex6BullsAndCowsGame(String secretNumber) {
        this.secretNumber = secretNumber;
    }

    /**
     * Generates a random 4-digit number with no repeated digits.
     *
     * @return a string representing the 4-digit number
     */
    public static String generateSecretNumber() {
        // TODO: Implement this method
        // 1. Generate 4 unique random digits (no repeats)

        Random random = new Random();
        int[] randomNumber = new int[4];
        randomNumber[0] = random.nextInt(10);

        for (int i = 1; i < 4; i++) {
            randomNumber[i] = random.nextInt(10);
            for (int j = i - 1; j >= 0; j--) {
                if (randomNumber[i] == randomNumber[j]) {
                    randomNumber[i] = random.nextInt(10);
                }
            }
        }

        // 2. Concatenate them into a string

        String secretNum = String.valueOf(randomNumber[0]);

        for (int i = 1; i < 4; i++) {
            secretNum = secretNum + String.valueOf(randomNumber[i]);
        }

        // 3. Return the string
        return secretNum;
    }

    /**
     * Evaluates a guess against the secret number.
     *
     * @param guess the guess to evaluate
     * @return an array with [bulls, cows]
     * @throws IllegalArgumentException if the guess is invalid
     */
    public int[] evaluateGuess(String guess) {
        // TODO: Implement this method
        // 1. Validate the guess (4 digits, no repeats)

        if (guess.length() == 4) {
            for (int i = 0; i < guess.length(); i++) {
                for (int j = 0; j < guess.length(); j++) {
                    if (i != j) {
                        char ch = guess.charAt(i);
                        if (!Character.isDigit(ch)) {
                            throw new IllegalArgumentException("The string is invalid!");
                        }
                        if (ch == guess.charAt(j)) {
                            throw new IllegalArgumentException("The digits are repeating!");
                        }
                    } else {
                        continue;
                    }

                }
            }
        } else {
            throw new IllegalArgumentException("The number is too short!");
        }

        // 2. Count bulls (correct digit in correct position)

        String secret = this.secretNumber;
        int correctPos = 0;

        for (int i = 0; i < guess.length(); i++) {
            char chr = secret.charAt(i);
            char chg = guess.charAt(i);
            if (chr == chg) {
                correctPos++;
            }
        }

        // 3. Count cows (correct digit in wrong position)

        int wrongPos = 0;

        for (int i = 0; i < guess.length(); i++) {
            for (int j = 0; j < guess.length(); j++) {
                if (i != j) {
                    char chr = secret.charAt(i);
                    char chg = guess.charAt(j);
                    if (chr == chg) {
                        wrongPos++;
                    }
                } else {
                    continue;
                }
            }
        }

        int[] counts = {correctPos, wrongPos};

        // 4. Return both counts as an array [bulls, cows]
        return counts;
    }

    /**
     * Plays the game with a predetermined list of guesses (for testing).
     *
     * @param guesses the list of guesses to try
     * @return the number of attempts needed to guess correctly
     */
    public int playTestGame(String[] guesses) {
        // TODO: Implement this method
        // 1. Iterate through each guess

        int[] counts = new int[2];

        for (int i = 0; i < +guesses.length; i++) {
            // 2. Evaluate the guess

            counts = evaluateGuess(guesses[i]);

            // 3. If all bulls, return the number of attempts

            if (counts[0] == 4) {
                return i + 1;
            }
        }
        // 4. If no correct guess, return the number of guesses

        return guesses.length;

    }

    /**
     * Plays an interactive game with user input.
     */
    public void play() {
        // TODO: Implement this method
        // 1. Create a scanner for user input

        Scanner scanner = new Scanner(System.in);

        // 2. Loop until the user guesses correctly

        int[] counts = new int[2];
        boolean done = false;
        int attempts = 1;
        while (!done) {
            System.out.println("Please enter a guess (4 digits number, no repeats) : ");
            String guess = scanner.nextLine();
            counts = evaluateGuess(guess);
            // 3. Validate and evaluate each guess
            if (counts[0] != 4) {
                // 4. Display the number of bulls and cows
                System.out.printf("Attempt %d: you guessed %d bulls (correct digits in correct position) and %d cows (correct digits in wrong position).\n", attempts, counts[0], counts[1]);
                System.out.println("Please enter another guess (4 digits number, no repeats) : ");
                guess = scanner.nextLine();
                // 5. Track the number of attempts
                attempts++;
            } else {
                done = true;
            }
        }
        // 6. Display the final result
        System.out.printf("You guessed the secret number %s in %d attempts!", this.secretNumber, attempts);
    }
}
