package isp.lab5.exercise1;

public class Product {
    private String productId;
    private String name;
    private double price;
    private ProductCategory productCategory;

    //constructor
        //i should implement a setter for price to check if it is a positive number
        //or in this case i used an if in the constructor and if the number is wrote in
        //negative form, i just transform it in the absolute value

    public Product(String productIdC, String nameC, double priceC, ProductCategory pc) {
        this.productId = productIdC;
        this.name = nameC;
        if (priceC < 0) {
            priceC = -priceC;
        }
        this.price = priceC;
        this.productCategory = pc;
    }

    public double getPrice() {
        return price;
    }

    //added toString to display the products
    @Override
    public String toString() {
        return "Product{" +
                "productId='" + productId + '\'' +
                ", name='" + name + '\'' +
                ", price=" + price +
                ", productCategory=" + productCategory +
                '}';
    }
}
