import java.io.Serializable;

public class Fruit implements Serializable {
    //attributes
    private String name;
    private String color;
    private int size;
    private double price;

    //constructor
    public Fruit(String name, String color, int size, double price) {
        this.name = name;
        this.color = color;
        this.size = size;
        this.price = price;
    }

    @Override
    public String toString() {
        return "Fruit{" +
                "name='" + name + '\'' +
                ", color='" + color + '\'' +
                ", size=" + size +
                ", price=" + price +
                '}';
    }
}
