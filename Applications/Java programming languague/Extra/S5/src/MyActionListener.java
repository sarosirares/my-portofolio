import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.*;

public class MyActionListener implements ActionListener {
    private JTextField name, color, size, price;

    public MyActionListener(JTextField name, JTextField color, JTextField size, JTextField price) {
        this.name = name;
        this.color = color;
        this.size = size;
        this.price = price;
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        String nameO = name.getText();
        String colorO = color.getText();
        int sizeO = Integer.parseInt(size.getText());
        double priceO = Double.parseDouble(price.getText());

        Fruit fruit = new Fruit(nameO, colorO, sizeO, priceO);

        name.setText("");
        color.setText("");
        size.setText("");
        price.setText("");

        String path = "Fruits\\";
        try (ObjectOutputStream out = new ObjectOutputStream(new FileOutputStream(path + nameO))) {
            out.writeObject(fruit);
        } catch (Exception exception) {

        }
    }
}
