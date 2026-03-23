//Thread Inheritance

class Main {
    public static void main(String[] args) {
        Activity activity = new Activity(); // we have to use the SAME OBJECT
        new MyThread(activity).start();
        new MyThread(activity).start();
    }
}
//
//class MyThread extends Thread {
//    @Override
//    public void run() {
//        for (int i = 0; i < 10; i++) {
//            System.out.println(
//                    Thread.currentThread().getName()
//                            + " msg " + i);
//            try {
//                Thread.sleep(1000); // we will come back to this
//            } catch (InterruptedException e) { // and this
//            }
//        }
//    }
//}

//public class MyThread extends Thread {
//    private static final Object LOCK = new Object();
//
//    public void run() {
//        System.out.println("Activity 1");
//        synchronized (LOCK) {
//            System.out.println("Critical Activity 2");
//        }
//        System.out.println("Activity 3");
//    }
//}

//public class MyThread extends Thread {
//    public void run() {
//        System.out.println("Activity 1");
//        synchronized (MyThread.class) {
//            System.out.println("Critical Activity 2");
//        }
//        System.out.println("Activity 3");
//    }
//}

//public class MyThread extends Thread {
//    private Integer lock;
//    public MyThread(Integer lock) {
//        this.lock = lock;
//    }
//    public void run() {
//        System.out.println("Activity 1");
//        synchronized (lock) {
//            System.out.println("Critical Activity 2");
//        }
//        System.out.println("Activity 3");
//    }
//}

class Activity {
    public synchronized void doActivity() {
        System.out.println("Critical Activity 2");
    }
}

public class MyThread extends Thread {
    private Activity activity;
    public MyThread(Activity activity) {
        this.activity = activity;
    }
    public void run() {
        System.out.println("Activity 1");
        activity.doActivity();
        System.out.println("Activity 3");
    }
}
