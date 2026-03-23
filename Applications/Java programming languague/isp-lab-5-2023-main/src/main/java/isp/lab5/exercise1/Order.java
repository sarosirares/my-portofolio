package isp.lab5.exercise1;

import java.time.LocalDateTime;

public class Order {
    //attributes
    private String orderId;
    private LocalDateTime date;
    private Double totalPrice;
    private Product[] orderProduct = new Product[10];

    //constructor
    public Order(String orderIdC, LocalDateTime dateC, Product[] orderProductC) {
        this.orderId = orderIdC;
        this.date = dateC;
        this.orderProduct = orderProductC;
        this.totalPrice = 0.0;
    }

    //methods

    public void setTotalPrice() {
        for (int i = 0; i < orderProduct.length; i++) {
            this.totalPrice += orderProduct[i].getPrice();
        }
    }

    public double getTotalPrice() {
        return totalPrice;
    }
}
