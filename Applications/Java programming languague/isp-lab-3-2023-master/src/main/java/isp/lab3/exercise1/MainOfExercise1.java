package isp.lab3.exercise1;

import java.util.Scanner;

public class MainOfExercise1 {
    public static void main(String[] args) {
        Tree tree = new Tree();
        System.out.println(tree);

        System.out.println("How much should the tree grow? Enter a value:");
        Scanner scanner = new Scanner(System.in);
        int value = scanner.nextInt();
        tree.grow(value);
        System.out.println(tree);
    }
}
