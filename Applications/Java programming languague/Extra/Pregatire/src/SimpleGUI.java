import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

class SimpleGUI extends JFrame {
    SimpleGUI() {
        setSize(400, 400); //set frames size in pixels
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        JButton button1 = new JButton("Click me");
        JButton button2 = new JButton("Exit");
        MyActionListener al = new MyActionListener();
        setLayout(new FlowLayout(FlowLayout.CENTER));
        add(button1);
        add(button2);
        button1.addActionListener(al);
        button2.addActionListener(al);
        setVisible(true);
    }

    class MyActionListener implements ActionListener {
        @Override
        public void actionPerformed(ActionEvent e) {
            switch (e.getActionCommand()) {
                case "Click me":
                    JOptionPane.showMessageDialog(null, "I've been clicked");
                    break;
                case "Exit":
                    System.exit(0);
            }
        }
    }

    public static void main(String[] args) {
        SimpleGUI gui = new SimpleGUI();
        System.out.println("main thread continues");
    }
}