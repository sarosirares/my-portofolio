package isp.lab11;

import java.util.Scanner;
import java.util.UUID;

public class AirCraft implements Runnable{

    String id;
    Object lock= UUID.randomUUID().toString();
    private int currentAltitude = 0;
    private int cruisingAltitude = 0;
    private long cruisingStartTime = 0;
    private long cruisingTime = 0;

    public AirCraft(String id){
        this.id = id;
    }

    public void start(){
        Thread t=new Thread(this);
        t.start();
    }

    public void run(){
        //initialise threads
        //---ON STAND---
        System.out.println(Thread.currentThread().getName() + ": Aircraft with id " + id + " is created. On stand");

        synchronized (lock){
            try {
                lock.wait();
            } catch (InterruptedException e) {
            }
        }

        //----TAXING---
        System.out.println(Thread.currentThread().getName() + ": Aircraft with id " + id + " is taxing");

        try{
            Thread.sleep(10_000);
        }catch(InterruptedException e){
        }

        //----TAKE OFF----
        System.out.println(Thread.currentThread().getName() + ": Aircraft with id " + id + " is taking off");

        //----ASCENDING----
        System.out.println(Thread.currentThread().getName() + ": Aircraft " + id + " is ascending to " + cruisingAltitude + "000 meters");
        while (currentAltitude < cruisingAltitude) {
            try {
                Thread.sleep(10_000);
                currentAltitude++;
                System.out.println(Thread.currentThread().getName() + ": Aircraft " + id + " reached " + currentAltitude + "000 meters");
            } catch (InterruptedException e) {
            }
        }

        //----CRUISING----
        System.out.println(Thread.currentThread().getName() + ": Aircraft " + id + " reached cruising altitude " + cruisingAltitude + "000 meters");
        cruisingStartTime = System.currentTimeMillis();

        // Wait for land command
        synchronized (lock) {
            try {
                lock.wait();
            } catch (InterruptedException e) {
            }
        }

        // Calculate cruising time
        cruisingTime = (System.currentTimeMillis() - cruisingStartTime) / 1000;
        System.out.println(Thread.currentThread().getName() + ": Aircraft " + id + " spent " + cruisingTime + " seconds in cruising");

        //----DESCENDING----
        System.out.println(Thread.currentThread().getName() + ": Aircraft " + id + " is descending");
        while (currentAltitude > 0) {
            try {
                Thread.sleep(10_000);
                currentAltitude--;
                System.out.println(Thread.currentThread().getName() + ": Aircraft " + id + " reached " + currentAltitude + "000 meters");
            } catch (InterruptedException e) {
            }
        }

        //----LANDED----
        System.out.println(Thread.currentThread().getName() + ": Aircraft " + id + " has landed");
    }


    public void receiveAtcCommand(AtcCommand command){
        System.out.println(Thread.currentThread().getName() + ": sends command" + command.getCommand() + " to aircraft " + id);
        if (command.getCommand().equals("take off")) {
            this.cruisingAltitude = command.getAltitude();
        }

        synchronized (lock) {lock.notify();}

    }
    public static void main(String[] args) {
        AirCraft airCraft = new AirCraft("A1234");
        airCraft.start();

        System.out.println(Thread.currentThread().getName() + ": Please enter to send the takeoff command to the aircraft.");
        Scanner scanner = new Scanner(System.in);
        scanner.nextLine();

        airCraft.receiveAtcCommand(new AtcCommand("take off"));
    }


}
