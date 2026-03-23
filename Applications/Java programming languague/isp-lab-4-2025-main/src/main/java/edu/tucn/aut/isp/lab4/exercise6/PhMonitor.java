package edu.tucn.aut.isp.lab4.exercise6;

public class PhMonitor extends Sensor {
    //attributes
    private boolean canpH;
    private float value;

    //methods

    public boolean isCanpH() {
        return canpH;
    }

    public void setCanpH(boolean canpH) {
        this.canpH = canpH;
    }

    public float getValue() {
        return value;
    }

    public void setValue(float value) {
        this.value = value;
    }
}
