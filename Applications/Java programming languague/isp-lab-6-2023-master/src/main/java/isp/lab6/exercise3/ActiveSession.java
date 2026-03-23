package isp.lab6.exercise3;

import java.util.HashMap;
import java.util.Map;

public class ActiveSession {
    //attributes
    private String username;
    private Map<Product, Integer> shoppingCart = new HashMap<>();

    //constructor
    public ActiveSession(String username) {
        this.username = username;
    }

    //methods
    public void addToCart(Product product, int quantity) {
        shoppingCart.put(product, quantity);
        System.out.println("Product added to the cart");
    }

    public Map<Product, Integer> getShoppingCart() {
        return shoppingCart;
    }
}
