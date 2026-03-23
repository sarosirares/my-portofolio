//Runnable Implementation

class Main2 {
    public static void main(String[] args) {
        SlowExec se = new SlowExec();
        Intrerruptor obj = new Intrerruptor(se);
        se.start();
        obj.start();
    }
}

public class MyRunnable implements Runnable{
    @Override
    public void run() {
        for (int i = 0; i < 10; i++) {
            System.out.println(
                    Thread.currentThread().getName()
                            + " msg " + i);
            try {
                Thread.sleep(1000);
            } catch (InterruptedException e) {
            }
        }
    }
}
