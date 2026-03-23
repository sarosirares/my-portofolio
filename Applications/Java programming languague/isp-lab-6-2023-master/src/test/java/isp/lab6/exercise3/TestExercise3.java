package isp.lab6.exercise3;

import org.junit.Assert;
import org.junit.Test;

import java.util.List;
import java.util.Scanner;

public class TestExercise3 {
    @Test
    public void sortingTest() {
        OnlineStore obj = new OnlineStore();

        Product product1 = new Product("aaaa", 3000);
        Product product2 = new Product("bbbb", 3);
        Product product3 = new Product("cccc", 300);
        obj.getProducts().addAll(List.of(product1, product2, product3));

        //trying every type of comparator
        Assert.assertEquals("[" + product1.toString() +
                ", " + product2.toString() +
                ", " + product3.toString() + "]", obj.getProductsSorted(obj.ascName).toString());

        Assert.assertEquals("[" + product3.toString() +
                ", " + product2.toString() +
                ", " + product1.toString() + "]", obj.getProductsSorted(obj.desName).toString());

        Assert.assertEquals("[" + product2.toString() +
                ", " + product3.toString() +
                ", " + product1.toString() + "]", obj.getProductsSorted(obj.ascPrice).toString());

        Assert.assertEquals("[" + product1.toString() +
                ", " + product3.toString() +
                ", " + product2.toString() + "]", obj.getProductsSorted(obj.desPrice).toString());
    }

    @Test
    public void addToCartTest() {
        OnlineStore obj = new OnlineStore();

        Product product1 = new Product("aaaa", 3000);
        Product product2 = new Product("bbbb", 3);
        Product product3 = new Product("cccc", 300);
        obj.getProducts().addAll(List.of(product1, product2, product3));

        obj.addSession("test");

        //adding a valid product
        obj.addToCart("test", product1, 3);
        Assert.assertEquals(1, obj.getSessions().get("test").getShoppingCart().size());

        //adding a product that is not in the store
        Product product4 = new Product("not in store", 999);

        obj.addToCart("test", product4, 3);
        Assert.assertEquals(1, obj.getSessions().get("test").getShoppingCart().size());

        //adding another product
        obj.addToCart("test", product2, 3);
        Assert.assertEquals(2, obj.getSessions().get("test").getShoppingCart().size());
    }

    @Test
    public void checkoutTest() {
        OnlineStore obj = new OnlineStore();

        //The session is created
        obj.addSession("test");
        Assert.assertFalse(obj.getSessions().isEmpty());

        //calling the "checkout" method, the session is removed
        obj.checkout("test");
        Assert.assertTrue(obj.getSessions().isEmpty());
    }

    @Test
    public void registerTest() {
        OnlineStore store = new OnlineStore();
        LoginSystem obj = new LoginSystem(store);

        //creating a user
        obj.register("test", "testP");
        Assert.assertEquals(1, obj.getUsers().size());

        //trying to create a user that has the same username as the previous one
        obj.register("test", "testP2");
        Assert.assertEquals(1, obj.getUsers().size()); //we can't create two users with same username
    }

    @Test
    public void loginTest() {
        OnlineStore store = new OnlineStore();
        LoginSystem obj = new LoginSystem(store);

        //creating a user
        obj.register("test", "testP");
        Assert.assertEquals(1, obj.getUsers().size());

        //logging in
        Assert.assertTrue(obj.login("test", "testP"));

        //trying to log in with the wrong password
        Assert.assertFalse(obj.login("test", "wrongP"));

        //trying to log in with a nonexistent username
        Assert.assertFalse(obj.login("test1", "testP"));
    }

    @Test
    public void logoutTest() {
        OnlineStore store = new OnlineStore();
        LoginSystem obj = new LoginSystem(store);

        //creating a user
        obj.register("test", "testP");
        Assert.assertEquals(1, obj.getUsers().size());

        //logging out
        Assert.assertTrue(obj.logout("test"));

        //trying to log out with a nonexistent username
        Assert.assertFalse(obj.logout("test1"));
    }
}
