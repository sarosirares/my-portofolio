import javax.swing.*;
import java.awt.*;

public class GUI extends JFrame {
    public GUI() {
        JLabel streetL, numberL, cityL, countryL;
        JTextField street, number, city, country;
        JButton saveB = new JButton("Save");
        setTitle("S7");
        setSize(400, 300);
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        setLayout(new GridLayout(5, 2));
        streetL = new JLabel("Street name: ");
        numberL = new JLabel("Number : ");
        cityL = new JLabel("City: ");
        countryL = new JLabel("Country: ");
        street = new JTextField();
        number = new JTextField();
        city = new JTextField();
        country = new JTextField();
        add(streetL);
        add(street);
        add(numberL);
        add(number);
        add(cityL);
        add(city);
        add(countryL);
        add(country);
        add(saveB);
        saveB.addActionListener(new MyActionListener(street, number, city, country));
        setVisible(true);
    }
}
