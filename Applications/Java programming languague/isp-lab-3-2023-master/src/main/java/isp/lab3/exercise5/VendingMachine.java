package isp.lab3.exercise5;

import java.util.Scanner;

public class VendingMachine {
    //10 is the number of products
    private int[] id = new int[10];
    private String[] productName;
    private int[] cost; //an attribute that stores the cost of every product
    private int credit; //the credits inserted in the machine

    //attribute: a string containing all information about products for testing display method
    private String products = "";

    public String getProducts() {
        return products;
    }

    public int getCredit() {
        return credit;
    }

    public VendingMachine() {      //Default constructor
        for (int i = 0; i < 10; i++) {
            this.id[i] = i + 1;
        }
        productName = new String[]{"Water", "Orange Juice",
                "Coke", "Pepsi", "Lay's", "Snickers",
                "Twist", "Kinder", "Mars", "IcedTea"};
        cost = new int[]{5, 6, 7, 7, 5, 3, 3, 4, 3, 6};
        credit = 0;
    }

    //Display Product method

    public void displayProducts() {
        System.out.println("The products present in the vending machine are: \n");
        for (int i = 0; i < 10; i++) {
            products += this.id[i] + ", " + this.productName[i] + ", " + this.cost[i] + "; ";
//          System.out.println(this.id[i] + this.productName[i]); displaying only id and product name
            System.out.println(this.id[i] + ". " + this.productName[i] + ", " + this.cost[i]);
        }
    }

    //Insert Coin method

    public void insertCoin(int value) {
        if (value > 0) {
            this.credit += value;
        } else {
            System.out.println("Please enter a valid value!");
        }
    }

    //Select Product method

    public String selectProduct(int id) {
        if (id >= 1 && id <= 10) {
            if (this.credit >= this.cost[id - 1]) {
                return this.productName[id - 1];
            } else {
                throw new IllegalArgumentException("Not enough credits!");
            }
        } else {
            throw new IllegalArgumentException("The product doesn't exist!");
        }
    }

    //Display credit method

    public void displayCredit() {
        System.out.println("The current available credit in the machine is: " + this.credit);
    }

    //The menu

    public void userMenu() {

        Scanner scanner = new Scanner(System.in);
        int opt = 0;
        do {
            System.out.println("\t\tVENDING MACHINE\n\n" +
                    "OPTIONS:\n" +
                    "1. Display all products\n" +
                    "2. Insert coin\n" +
                    "3. Select Product\n" +
                    "4. Display credit\n" +
                    "5. Exit");
            System.out.println("Please enter your option: ");
            opt = scanner.nextInt();
            scanner.nextLine();

            switch (opt) {
                case 1:
                    this.displayProducts();
                    break;
                case 2:
                    System.out.println("Enter how much credits you want to add: ");
                    int value = scanner.nextInt();
                    this.insertCoin(value);
                    break;
                case 3:
                    System.out.println("Enter the id: ");
                    int id = scanner.nextInt();
                    System.out.println("The product is: " + this.selectProduct(id));
                    break;
                case 4:
                    this.displayCredit();
                    break;
                case 5:
                    break;
                default:
                    System.out.println("\nInvalid option!\n");
            }
        } while (opt != 5);
    }
}
