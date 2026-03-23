package isp.lab7.safehome;

public class Door {
    //attributes
    private DoorStatus status;

    //constructor
    public Door(DoorStatus status) {
        this.status = status;
    }

    //methods
    public void lockDoor() {
        status = DoorStatus.CLOSE;
        System.out.println("Door is now closed!");
    }

    public void unlockDoor() {
        status = DoorStatus.OPEN;
        System.out.println("Door is now open!");
    }

    public DoorStatus getStatus() {
        return status;
    }
}
