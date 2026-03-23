package isp.lab3.exercise4;

import static java.lang.Math.*;

public class MyPoint {

    private int x;
    private int y;
    private int z;

    public MyPoint() {
        this.x = 0;
        this.y = 0;
        this.z = 0;
    }

    public MyPoint(int x, int y, int z) {
        this.x = x;
        this.y = y;
        this.z = z;
    }

    public void setX(int x) {
        this.x = x;
    }

    public void setY(int y) {
        this.y = y;
    }

    public void setZ(int z) {
        this.z = z;
    }

    public int getX() {
        return x;
    }

    public int getY() {
        return y;
    }

    public int getZ() {
        return z;
    }


    public void setXYZ(int x, int y, int z) {
        this.x = x;
        this.y = y;
        this.z = z;
    }

    @Override
    public String toString() {
        return "(" +
                x + ", " +
                y + ", " +
                z + ")";
    }

    public double distance(int x, int y, int z) {
        return sqrt(pow((this.x - x), 2) + pow((this.y - y), 2) + pow((this.z - z), 2));
    }

    public double distance(MyPoint point) {
        return sqrt(pow((this.x - point.x), 2) + pow((this.y - point.y), 2) + pow((this.z - point.z), 2));
    }
}
