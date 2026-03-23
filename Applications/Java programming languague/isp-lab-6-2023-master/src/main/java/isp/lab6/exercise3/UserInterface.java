package isp.lab6.exercise3;

import java.util.Scanner;

public class UserInterface {
    //attributes
    private LoginSystem loginSyst;
    private OnlineStore store;

    //constructors
    public UserInterface(LoginSystem loginSyst, OnlineStore store) {
        this.loginSyst = loginSyst;
        this.store = store;
    }

    //methods
    Scanner scanner = new Scanner(System.in);

    public void loadInterface() {
        int optMain;
        do {
            System.out.println();
            System.out.println("1. Register");
            System.out.println("2. Login");
            System.out.println("3. EXIT");
            System.out.println("\nEnter your option: ");
            optMain = scanner.nextInt();
            scanner.nextLine();
            switch (optMain) {
                case 1 -> {
                    System.out.println();
                    System.out.println("Please enter a username: ");
                    String username = scanner.nextLine();
                    System.out.println("Please enter a password: ");
                    String password = scanner.nextLine();
                    loginSyst.register(username, password);
                }
                case 2 -> {
                    System.out.println();
                    System.out.println("Please enter your username");
                    String username = scanner.nextLine();
                    System.out.println("Please enter your password: ");
                    String password = scanner.nextLine();
                    if (loginSyst.login(username, password)) {
                        int optLogged;
                        do {
                            System.out.println();
                            System.out.println("1. List Products");
                            System.out.println("2. List Products(sorted)");
                            System.out.println("3. Add to cart");
                            System.out.println("4. Logout");
                            System.out.println("5. Checkout");
                            System.out.println("\nEnter your option: ");
                            optLogged = scanner.nextInt();
                            scanner.nextLine();
                            switch (optLogged) {
                                case 1 -> {
                                    for (Product product : store.getProducts()) {
                                        System.out.println(product.toString());
                                    }
                                }
                                case 2 -> {
                                    int optSort;
                                    do {
                                        System.out.println();
                                        System.out.println("1. Ascending by name");
                                        System.out.println("2. Descending by name");
                                        System.out.println("3. Ascending by price");
                                        System.out.println("4. Descending by price");
                                        System.out.println("5. Back");
                                        System.out.println("\nEnter your option: ");
                                        optSort = scanner.nextInt();
                                        scanner.nextLine();
                                        switch (optSort) {
                                            case 1 -> {
                                                for (Product product : store.getProductsSorted(store.ascName)) {
                                                    System.out.println(product.toString());
                                                }
                                            }
                                            case 2 -> {
                                                for (Product product : store.getProductsSorted(store.desName)) {
                                                    System.out.println(product.toString());
                                                }
                                            }
                                            case 3 -> {
                                                for (Product product : store.getProductsSorted(store.ascPrice)) {
                                                    System.out.println(product.toString());
                                                }
                                            }
                                            case 4 -> {
                                                for (Product product : store.getProductsSorted(store.desPrice)) {
                                                    System.out.println(product.toString());
                                                }
                                            }
                                            case 5 -> System.out.println();
                                            default -> System.out.println("Not a valid option!");
                                        }
                                    } while (optSort < 5);
                                }
                                case 3 -> {
                                    System.out.println();
                                    System.out.println("Enter the product name: ");
                                    String pName = scanner.nextLine();
                                    Product product = store.searchProduct(pName);
                                    System.out.println("Please enter the quantity: ");
                                    int pQuantity = scanner.nextInt();
                                    scanner.nextLine();
                                    store.addToCart(username, product, pQuantity);
                                }
                                case 4 -> loginSyst.logout(username);
                                case 5 -> {
                                    System.out.println(store.checkout(username));
                                }
                                default -> System.out.println("Not a valid option!");
                            }
                        } while (optLogged < 4);
                    }
                }
                case 3 -> System.out.println();
                default -> System.out.println("Not a valid option!");
            }
        } while (optMain < 3);
    }
}
