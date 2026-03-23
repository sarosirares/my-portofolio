package isp.lab3.exercise;

import isp.lab3.exercise1.Tree;
import org.junit.Assert;
import org.junit.Test;

public class TreeTest {

    @Test
    public void testGrow() {
        Tree tree = new Tree();
        tree.grow(0);
        Assert.assertEquals(15, tree.height);
        tree.grow(-1);
        Assert.assertEquals(15, tree.height);
        tree.grow(1);
        Assert.assertEquals(16, tree.height);
        tree.grow(5);
        Assert.assertEquals(21, tree.height);
    }

    @Test
    public void testToString(){
        Tree tree = new Tree();
        Assert.assertEquals("Tree{height=15}", tree.toString());
        tree.grow(5);
        Assert.assertEquals("Tree{height=20}", tree.toString());
    }

}
