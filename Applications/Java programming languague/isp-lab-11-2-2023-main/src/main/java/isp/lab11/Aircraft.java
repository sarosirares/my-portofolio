package isp.lab11;

import java.util.Scanner;
import java.util.UUID;

public class Aircraft implements Runnable {
    String id;
    String lock = UUID.randomUUID().toString();
    private int currentAltitude;
    private int finalAltitude;

    public Aircraft(String id) {
        this.id = id;
    }

    public void start() {
        Thread t = new Thread(this);
        t.start();
    }

    public void run() {
        // on stand
        System.out.println(Thread.currentThread().getName() + ": Aircraft " + this.id + " is created. On stand.");

        synchronized (lock) {
            try {
                lock.wait();
            } catch (InterruptedException e) {

            }
        }

        // taxing
        System.out.println(Thread.currentThread().getName() + ": Aircraft " + this.id + " is taxing.");

        try {
            Thread.sleep(10_000);
        } catch (InterruptedException e) {

        }

        // take off
        System.out.println(Thread.currentThread().getName() + ": Aircraft " + this.id + " is taking off.");

        // ascending
        System.out.println(Thread.currentThread().getName() + ": Aircraft " + this.id + " is going to reach " + finalAltitude + " meters");
        while (currentAltitude < finalAltitude) {
            try {
                Thread.sleep(10_000);
                currentAltitude++;
                System.out.println(Thread.currentThread().getName() + ": Aircraft " + this.id + " is at the altitude of: " + currentAltitude + " meters.");
            } catch (InterruptedException e) {

            }
        }

        // cruising
        System.out.println(Thread.currentThread().getName() + ": Aircraft " + this.id + " reached cruising altitude " + finalAltitude + " meters.");

        synchronized (lock) {
            try {
                lock.wait();
            } catch (InterruptedException e) {

            }
        }

        // descending
        System.out.println(Thread.currentThread().getName() + ": Aircraft " + this.id + " is starting to descend.");
        while (currentAltitude > 0) {
            try {
                Thread.sleep(10_000);
                currentAltitude--;
                System.out.println(Thread.currentThread().getName() + ": Aircraft " + this.id + " is at the altitude of: " + currentAltitude + " meters.");
            } catch (InterruptedException e) {

            }
        }

        // landed
        System.out.println(Thread.currentThread().getName() + ": Aircraft " + this.id + " has landed.");
    }

    public void receiveAtcCommand(AtcCommand cmd) {
        System.out.println(Thread.currentThread().getName() + ": sends command" + cmd.getCommand() + " to aircraft " + id);
        synchronized (lock) {
            lock.notify();
        }
    }

    public static void main(String[] args) {
        Aircraft da = new Aircraft("A1234");
        da.start();

        System.out.println(Thread.currentThread().getName() + ": Please enter any key for takeoff.");
        Scanner scanner = new Scanner(System.in);
        scanner.nextLine();

        da.receiveAtcCommand(new AtcCommand("take off"));
    }
}
