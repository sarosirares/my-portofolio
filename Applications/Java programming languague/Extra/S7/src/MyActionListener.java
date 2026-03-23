import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.*;

public class MyActionListener implements ActionListener {
    private JTextField street, number, city, country;

    public MyActionListener(JTextField name, JTextField color, JTextField size, JTextField price) {
        this.street = name;
        this.number = color;
        this.city = size;
        this.country = price;
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        int i = 0;
        String streetO = street.getText();
        int numberO = Integer.parseInt(number.getText());
        String cityO = city.getText();
        String countryO = country.getText();

        Address address = new Address(streetO, numberO, cityO, countryO);

        street.setText("");
        number.setText("");
        city.setText("");
        country.setText("");

        String path = "Addresses\\";
        File f;
        do {
            f = new File(path + "Address" + i + ".txt");
            i++;
        } while (f.exists());

        try (PrintWriter writer = new PrintWriter(f)) {
            writer.println(streetO);
            writer.println(numberO);
            writer.println(cityO);
            writer.println(countryO);
        } catch (IOException ex) {
            System.out.println("Error writing to file: " + ex.getMessage());
        }
    }
}
