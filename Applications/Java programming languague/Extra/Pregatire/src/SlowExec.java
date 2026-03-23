class SlowExec extends Thread{
    @Override
    public void run() {
        try {
            Thread.sleep(1000 * 60 * 60 * 24); // 1 day
        } catch (InterruptedException e) {
            System.out.println("I've been interrupted");
        }
    }
}

class Intrerruptor extends Thread{
    private SlowExec slowExec; //...constructor association
    public Intrerruptor(SlowExec slowExec) {
        this.slowExec = slowExec;
    }
    @Override
    public void run() {
        try {
            Thread.sleep(5000); // 5 sec
        } catch (InterruptedException e) {}
        slowExec.interrupt();
    }
}
