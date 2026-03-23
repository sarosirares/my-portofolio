import javax.swing.*;
import java.awt.*;

public class GUI extends JFrame {
    public GUI() {
        setSize(400, 200);
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        setLayout(new GridLayout(5, 2));
        JLabel nameL = new JLabel("Name: ");
        JLabel colorL = new JLabel("Color: ");
        JLabel sizeL = new JLabel("Size: ");
        JLabel priceL = new JLabel("Price: ");
        JButton saveB = new JButton("Save");
        JTextField name = new JTextField(15);
        JTextField color = new JTextField(15);
        JTextField size = new JTextField(15);
        JTextField price = new JTextField(15);
        add(nameL);
        add(name);
        add(colorL);
        add(color);
        add(sizeL);
        add(size);
        add(priceL);
        add(price);
        add(saveB);
        saveB.addActionListener(new MyActionListener(name, color, size, price));
        setVisible(true);
    }
}
