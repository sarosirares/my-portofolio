package isp.lab6.exercise3;

import java.util.Objects;

public class Product {
    //attributes
    private String name;
    private double price;

    //constructor
    public Product(String name, double price) {
        this.name = name;
        this.price = price;
    }

    //methods
    public String getName() {
        return name;
    }

    public double getPrice() {
        return price;
    }

    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        Product product = (Product) o;
        return Objects.equals(name, product.name);
    }

    @Override
    public int hashCode() {
        return Objects.hash(name);
    }

    @Override
    public String toString() {
        return "Product{" +
                "name='" + name + '\'' +
                ", price=" + price +
                '}';
    }
}
