package isp.lab10.raceapp;

class Car extends Thread {
    private String name;
    private int distance = 0;
    private CarPanel carPanel;
    private int power;
    private long execTime;

    public Car(String name, CarPanel carPanel, int power) {
        //set thread name;
        setName(name);
        this.name = name;
        this.carPanel = carPanel;
        this.power = power;
    }

    public long getExecTime() {
        return execTime;
    }

    public void run() {
        long startTime = System.currentTimeMillis();
        while (distance < 400) {
            // simulate the car moving at a random speed
            int speed = (int) (Math.random() * power) + 1;
            distance += speed;

            carPanel.updateCarPosition(name, distance);

            try {
                // pause for a moment to simulate the passage of time
                Thread.sleep(100);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
        this.execTime = System.currentTimeMillis() - startTime;
        carPanel.carFinished(name);
    }
}
