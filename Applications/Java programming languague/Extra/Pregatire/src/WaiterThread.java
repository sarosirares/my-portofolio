import java.io.IOException;

class Main3 {
    static final Object monitor = new Object();
    public static void main(String[] args) throws IOException {
        new NotifierThread().start();
        new WaiterThread().start();
    }
}

public class WaiterThread extends Thread{
    public void run() {
        synchronized (Main3.monitor){
            try {
                Main3.monitor.wait();
            } catch (InterruptedException e) {
            }
            System.out.println("I was notified");
        }
    }
}

class NotifierThread extends Thread {
    public void run() {
        try {
            System.out.println("Lets make the waiter wait");
            Thread.sleep(2000);
            synchronized (Main3.monitor) { // uses the same instance
                Main3.monitor.notify();
                System.out.println("The waiter will wait for the next sleep. " +
                        "I'm still holding the lock (still in 'synchronized')");
                Thread.sleep(2000);
            }
        } catch (InterruptedException e) {}
    }
}
