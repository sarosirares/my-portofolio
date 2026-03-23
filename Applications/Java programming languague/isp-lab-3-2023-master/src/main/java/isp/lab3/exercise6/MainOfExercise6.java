package isp.lab3.exercise6;

public class MainOfExercise6 {
    public static void main(String[] args) {
        //First I'm testing if it's the same instance
        VendingMachineSingleton obj1 = VendingMachineSingleton.getInstance();
        VendingMachineSingleton obj2 = VendingMachineSingleton.getInstance();
        if (obj1 == obj2) { //if it is the same instance, run the vending machine code
            obj1.userMenu();
        }
    }
}
