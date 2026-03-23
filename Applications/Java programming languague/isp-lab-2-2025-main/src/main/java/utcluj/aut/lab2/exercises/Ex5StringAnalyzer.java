package utcluj.aut.lab2.exercises;

import java.util.Scanner;

/**
 * Class for analyzing strings.
 * Students should implement all methods to pass the unit tests.
 */

public class Ex5StringAnalyzer {

    /**
     * Parses the input string into an array of strings, splitting by semicolons.
     *
     * @param input the input string to parse
     * @return an array of strings
     */
    public String[] parseInput(String input) {
        // TODO: Implement this method
        // 1. Split the input by semicolons

//        String[] splited = input.split(";");

        // 2. Return the resulting array of strings

//        return splited;

        return input.split(";");
    }

    /**
     * Finds the longest string(s) in the array.
     * If multiple strings have the same length, all are returned.
     *
     * @param strings the array of strings to analyze
     * @return an array of the longest strings
     */
    public String[] findLongest(String[] strings) {
        // TODO: Implement this method
        // 1. Find the maximum string length in the array

        int max = 0;

        for (int i = 0; i < strings.length; i++) {
            if (strings[i].length() >= max) {
                max = strings[i].length();
            }
        }

        // 2. Collect all strings with that length
        int size = 0;

        for (int i = 0; i < strings.length; i++) {
            if (strings[i].length() == max) {
                size++;
            }
        }

        String[] longestStrings = new String[size];

        int j = 0;
        for (int i = 0; i < strings.length; i++) {
            if (strings[i].length() == max) {
                longestStrings[j] = strings[i];
                j++;
            }
        }


        // 3. Return the array of longest strings
        return longestStrings;
    }

    /**
     * Finds the shortest string(s) in the array.
     * If multiple strings have the same length, all are returned.
     *
     * @param strings the array of strings to analyze
     * @return an array of the shortest strings
     */
    public String[] findShortest(String[] strings) {
        // TODO: Implement this method
        // 1. Find the minimum string length in the array

        int min = strings[0].length();

        for (int i = 0; i < strings.length; i++) {
            if (strings[i].length() <= min) {
                min = strings[i].length();
            }
        }


        // 2. Collect all strings with that length

        int size = 0;

        for (int i = 0; i < strings.length; i++) {
            if (strings[i].length() == min) {
                size++;
            }
        }

        String[] shortestStrings = new String[size];

        int j = 0;
        for (int i = 0; i < strings.length; i++) {
            if (strings[i].length() == min) {
                shortestStrings[j] = strings[i];
                j++;
            }
        }

        // 3. Return the array of shortest strings
        return shortestStrings;
    }

    /**
     * Counts the number of vowels in each string.
     *
     * @param strings the array of strings to analyze
     * @return a map from string to vowel count
     */
    public int[] countVowels(String[] strings) {
        // TODO: Implement this method
        // 1. Create a map to store the counts

        int[] vowels = new int[strings.length];

        // 2. For each string, count the vowels (a, e, i, o, u)

        for (int i = 0; i < strings.length; i++) {
            for (int j = 0; j < strings[i].length(); j++) {
                char ch = strings[i].charAt(j);
                ch = Character.toLowerCase(ch);
                if ((ch == 'a') || (ch == 'e') || (ch == 'i') || (ch == 'o') || (ch == 'u')) {
                    vowels[i]++;
                }
            }
        }

//        for (int i = 0; i < strings.length; i++) {
//            int count = 0;
//            for (char c : strings[i].toCharArray()) {
//                if (Character.isLetter(c) && "aeiouAEIOU".indexOf(c) != -1) {
//                    count++;
//                }
//            }
//            vowels[i] = count;
//        }


        // 3. Store the counts in the map

        // 4. Return the map
        return vowels;
    }

    /**
     * Counts the number of consonants in each string.
     *
     * @param strings the array of strings to analyze
     * @return an array of integers representing the consonant count for each string
     */
    public int[] countConsonants(String[] strings) {
        // TODO: Implement this method
        // 1. Create an array to store the counts
        int[] consonantCounts = new int[strings.length];
        // 2. For each string, count the consonants (non-vowels that are letters)
        for (int i = 0; i < strings.length; i++) {
            int count = 0;
            for (char c : strings[i].toCharArray()) {
                if (Character.isLetter(c) && "aeiouAEIOU".indexOf(c) == -1) {
                    count++;
                }
            }
            consonantCounts[i] = count;
        }
        // 3. Return the array
        return consonantCounts;
    }

    /**
     * Finds the string(s) with the most vowels.
     * If multiple strings have the same number of vowels, all are returned.
     *
     * @param strings the array of strings to analyze
     * @return an array of strings with the most vowels
     */
    public String[] findMostVowels(String[] strings) {
        // TODO: Implement this method
        // 1. Count vowels in each string

        int[] vowels = countVowels(strings);

        // 2. Find the maximum vowel count

        int max = 0;

        for (int i = 0; i < vowels.length; i++) {
            if (vowels[i] >= max) {
                max = vowels[i];
            }
        }

        // 3. Collect all strings with that count

        int size = 0;

        for (int i = 0; i < vowels.length; i++) {
            if (vowels[i] == max) {
                size++;
            }
        }

        String[] mostVowels = new String[size];

        int j = 0;
        for (int i = 0; i < vowels.length; i++) {
            if (vowels[i] == max) {
                mostVowels[j] = strings[i];
                j++;
            }
        }

        // 4. Return the array
        return mostVowels;
    }

    /**
     * Finds the string(s) with the most consonants.
     * If multiple strings have the same number of consonants, all are returned.
     *
     * @param strings the array of strings to analyze
     * @return an array of strings with the most consonants
     */
    public String[] findMostConsonants(String[] strings) {
        // TODO: Implement this method
        // 1. Count consonants in each string

        int[] consonants = countConsonants(strings);

        // 2. Find the maximum consonant count

        int max = 0;

        for (int i = 0; i < consonants.length; i++) {
            if (consonants[i] >= max) {
                max = consonants[i];
            }
        }

        // 3. Collect all strings with that count

        int size = 0;

        for (int i = 0; i < consonants.length; i++) {
            if (consonants[i] == max) {
                size++;
            }
        }

        String[] mostConsonants = new String[size];

        int j = 0;
        for (int i = 0; i < consonants.length; i++) {
            if (consonants[i] == max) {
                mostConsonants[j] = strings[i];
                j++;
            }
        }

        // 4. Return the array
        return mostConsonants;
    }

    public static void main(String[] args) {
        // TODO: Implement the main method
        // 1. Create an instance of StringAnalyzer

        Ex5StringAnalyzer StringAnalyzer = new Ex5StringAnalyzer();

        // 2. Parse the input string into an array of strings

        Scanner scanner = new Scanner(System.in);

        System.out.println("Please enter a list and separate strings by semicolon \";\" ");
        String input = scanner.nextLine();
        String[] records = StringAnalyzer.parseInput(input);

        // 3. Find and print the longest and shortest strings

        System.out.println("The longest strings are: ");
        for (int i = 0; i < StringAnalyzer.findLongest(records).length; i++) {
            System.out.println(StringAnalyzer.findLongest(records)[i]);
        }

        System.out.println("The shortest strings are: ");
        for (int i = 0; i < StringAnalyzer.findShortest(records).length; i++) {
            System.out.println(StringAnalyzer.findShortest(records)[i]);
        }

        // 4. Count and print the number of vowels and consonants in each string

        System.out.println("The number of vowels in each string are presented: ");
        for (int i = 0; i < StringAnalyzer.countVowels(records).length; i++) {
            System.out.println("The string " + records[i] + " has " + StringAnalyzer.countVowels(records)[i] + " vowels.");
        }

        System.out.println("The number of consonants in each string are presented: ");
        for (int i = 0; i < StringAnalyzer.countConsonants(records).length; i++) {
            System.out.println("The string " + records[i] + " has " + StringAnalyzer.countConsonants(records)[i] + " consonants.");
        }

        // 5. Find and print the strings with the most vowels and consonants

        System.out.println("The strings with the most vowels are: ");
        for (int i = 0; i < StringAnalyzer.findMostVowels(records).length; i++) {
            System.out.println(StringAnalyzer.findMostVowels(records)[i]);
        }

        System.out.println("The strings with the most consonants are: ");
        for (int i = 0; i < StringAnalyzer.findMostConsonants(records).length; i++) {
            System.out.println(StringAnalyzer.findMostConsonants(records)[i]);
        }

    }
}