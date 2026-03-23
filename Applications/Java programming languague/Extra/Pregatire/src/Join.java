class T1 extends Thread {
    public void run() {
        System.out.println("let T2 wait 5s");
        try {
            Thread.sleep(5000);
        } catch (InterruptedException e) {}
        System.out.println("I'm done");
    }
}

class T2 extends Thread {
    private Thread t1;
    public T2(Thread t1) {
        this.t1 = t1;
    }
    public void run() {
        try {
            t1.join();
        } catch (InterruptedException e) {
        }
        System.out.println("I'm also done");
    }
}

class Main4 {
    public static void main(String[] args) {
        Thread t1 = new T1();
        t1.start();
        new T2(t1).start();
    }
}
