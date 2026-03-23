package isp.lab6.exercise3;

import java.util.List;

public class Exercise3 {

    public static void main(String[] args) {
        OnlineStore store = new OnlineStore();
        LoginSystem loginSystem = new LoginSystem(store);

        Product product1 = new Product("Apple", 3);
        Product product2 = new Product("Phone", 3000);
        Product product3 = new Product("Vacuum cleaner", 300);
        Product product4 = new Product("Burger", 25);
        Product product5 = new Product("Juice", 8);
        store.getProducts().addAll(List.of(product1, product2, product3, product4, product5));

        UserInterface obj = new UserInterface(loginSystem, store);
        obj.loadInterface();
    }
}
