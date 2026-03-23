package isp.lab10.raceapp;

import javax.swing.*;
import java.util.ArrayList;
import java.util.List;
import java.util.Map;

public class Main {
    public static void main(String[] args) {

        JFrame frame = new JFrame("Car Race");
        JFrame semaphoreFrame = new JFrame("Semaphore");

        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        semaphoreFrame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        CarPanel carPanel = new CarPanel();

        SemaphorePanel semaphorePanel = new SemaphorePanel();

        frame.getContentPane().add(carPanel);
        frame.pack();frame.setSize(500,300);
        frame.setVisible(true);

        semaphoreFrame.getContentPane().add(semaphorePanel);
        semaphoreFrame.pack();
        semaphoreFrame.setVisible(true);

        SemaphoreThread semaphoreThread = new SemaphoreThread(semaphorePanel);


        Car car1 = new Car("Red car", carPanel, 10);
        Car car2 = new Car("Blue car", carPanel, 12);
        Car car3 = new Car("Green car", carPanel, 20);
        Car car4 = new Car("Yellow car", carPanel, 5);

        PlaySound sound = new PlaySound();
        semaphoreThread.start();

        try{
            semaphoreThread.join();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        sound.playSound();
        car1.start();
        car2.start();
        car3.start();
        car4.start();

        try {
            car1.join();
            car2.join();
            car3.join();
            car4.join();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        sound.stopSound();

        Map<String, Long> raceTimes = Map.of(
                car1.getName(), car1.getExecTime(),
                car2.getName(), car2.getExecTime(),
                car3.getName(), car3.getExecTime(),
                car4.getName(), car4.getExecTime()

        );
        System.out.println("Standings: ");
        //sort the map by value
        List<Map.Entry<String, Long>> sortedEntries = new ArrayList<>(raceTimes.entrySet());
        sortedEntries.sort(Map.Entry.comparingByValue());

        for (Map.Entry<String, Long> entry : sortedEntries) {
            System.out.println(entry.getKey() + ": " + entry.getValue() + " ms");
        }
    }
}
