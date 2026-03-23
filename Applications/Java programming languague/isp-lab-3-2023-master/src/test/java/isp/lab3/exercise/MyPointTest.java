package isp.lab3.exercise;

import isp.lab3.exercise4.MyPoint;
import org.junit.Assert;
import org.junit.Test;

public class MyPointTest {

    @Test
    public void TestDistance() {
        MyPoint point1 = new MyPoint(4, 5, 3);
        MyPoint point2 = new MyPoint(6, 5, -1);

        point1.distance(2, 5, -2);
        point2.distance(point1);

        Assert.assertEquals(4.472, point1.distance(point2), 0.001);
        Assert.assertEquals(4.472, point2.distance(point1), 0.001);
        Assert.assertEquals(0.000, point1.distance(4, 5, 3), 0.001);

    }
}
