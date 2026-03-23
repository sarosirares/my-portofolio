package isp.lab5.exercise1;

import org.junit.Assert;
import org.junit.Test;

import java.time.LocalDateTime;

/**
 * @author Radu Miron
 * @version 1
 */
public class Exercise1Test {
    @Test
    public void totalPriceTest() {
        Address testAddress = new Address();
        Customer testCustomer = new Customer("1234", "Sarosi", "0712459234", testAddress);
        Product testProduct1 = new Product("1", "test", 30.00, ProductCategory.ELECTRONICS);
        Product testProduct2 = new Product("2", "test", 0.0, ProductCategory.BEAUTY);
        Product testProduct3 = new Product("3", "test", -2354.00, ProductCategory.FASHION);
        Product[] testProducts = {testProduct1, testProduct2, testProduct3};

        Order obj = new Order("9876", LocalDateTime.of(2025, 9, 20, 5, 12), testProducts);

        obj.setTotalPrice();

        Assert.assertEquals(2384.00, obj.getTotalPrice(), 0.0);
    }
}
