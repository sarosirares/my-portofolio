package isp.lab3.exercise;

import isp.lab3.exercise5.VendingMachine;
import org.junit.*;
import org.junit.Test;

public class VendingMachineTest {

    @Test
    public void displayTest() {
        VendingMachine obj = new VendingMachine();
        obj.displayProducts();
        Assert.assertEquals("1, Water, 5; 2, Orange Juice, 6; 3, Coke, 7; 4, Pepsi, 7; 5, Lay's, 5; 6, Snickers, 3;" +
                " 7, Twist, 3; 8, Kinder, 4; 9, Mars, 3; 10, IcedTea, 6; ", obj.getProducts());

        //This would've been more useful if the display function returned a string, I think
    }

    @Test
    public void insertTest() {
        VendingMachine obj = new VendingMachine();
        obj.insertCoin(-2);
        Assert.assertEquals(0, obj.getCredit());
        obj.insertCoin(5);
        Assert.assertEquals(5, obj.getCredit());
        obj.insertCoin(0);
        Assert.assertEquals(5, obj.getCredit());
    }

    @Test
    public void selectProductTest() {
        VendingMachine obj = new VendingMachine();
        Assert.assertEquals("IcedTea", obj.selectProduct(10));
        Assert.assertThrows(IllegalArgumentException.class, () -> obj.selectProduct(-3));
    }
}
