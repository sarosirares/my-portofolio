package isp.lab5.exercise1;

import java.time.LocalDateTime;

public class Exercise1 {

    public static void main(String[] args) {
        Address addressObj = new Address();
        Customer customerObj = new Customer("0001", "Sarosi", "0712459234", addressObj);
        Product product1 = new Product("1", "Phone", 3000.00, ProductCategory.ELECTRONICS);
        Product product2 = new Product("2", "Laptop", 5000.00, ProductCategory.ELECTRONICS);
        Product product3 = new Product("3", "Tablet", 3500.00, ProductCategory.ELECTRONICS);
        Product product4 = new Product("4", "Tennis Ball", 40.00, ProductCategory.TOYS);
        Product product5 = new Product("5", "Tennis Paddle", 300.00, ProductCategory.TOYS);
        Product product6 = new Product("6", "Pickaxe", 150.00, ProductCategory.HOME_AND_GARDEN);
        Product product7 = new Product("7", "Axe", 100.00, ProductCategory.HOME_AND_GARDEN);
        Product product8 = new Product("8", "Car", 300000.00, ProductCategory.HOME_AND_GARDEN);
        Product product9 = new Product("9", "Cream", 40.00, ProductCategory.BEAUTY);
        Product product10 = new Product("10", "Mouse", 70.00, ProductCategory.ELECTRONICS);

        Product[] products = {product1, product2, product3, product4, product5, product6,
                product7, product8, product9, product10};

        Order orderObj = new Order("7263", LocalDateTime.of(2025, 4, 25, 12, 30), products);

        //displaying all products in this order
        for (int i = 0; i < products.length; i++) {
            System.out.println(products[i]);
        }
        //calculating the total price of this order
        orderObj.setTotalPrice();
        System.out.println("The total price of the order is: " + orderObj.getTotalPrice());
    }
}
