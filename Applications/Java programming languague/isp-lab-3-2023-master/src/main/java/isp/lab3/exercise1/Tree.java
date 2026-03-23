package isp.lab3.exercise1;

public class Tree {
    public int height;

    public Tree() {
        height = 15;
    }

    public void grow(int meters) {
        if (meters > 0) {
            this.height += meters;
        }
    }

    @Override
    public String toString() {
        return "Tree{" +
                "height=" + height +
                '}';
    }
}
