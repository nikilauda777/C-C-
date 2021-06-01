package Semkin_Barkov;
import org.junit.Assert;
import org.junit.Before;
import org.junit.Test;

public class ConstantArrayTest {

    private ConstantArray<Double> constantA = new ConstantArray<>();

    @Before
    public void setUp() throws Exception {
        constantA.push(1.5);
        constantA.push(2.0);
        constantA.push(2.0);
    }

    @Test
    public void testSize() throws Exception {

        Assert.assertEquals(3, constantA.getSize());

        constantA.pop();
        constantA.pop();

        Assert.assertEquals(1, constantA.getSize());
    }

    @Test
    public void testEmpty() throws Exception {

        Assert.assertFalse(constantA.isEmpty());

        constantA.pop();
        constantA.pop();
        constantA.pop();

        Assert.assertTrue(constantA.isEmpty());
    }


    @Test
    public void testpeek() throws Exception{

        Assert.assertEquals(1.5, constantA.peek(), 0);

        constantA.pop();
        constantA.pop();

        Assert.assertEquals(1.5, constantA.peek(), 0);
    }

    @Test
    public void testPush() throws Exception {

        Assert.assertEquals(3, constantA.getSize());

        constantA.push(1.0);
        constantA.push(1.0);
        constantA.push(1.0);

        Assert.assertEquals(6, constantA.getSize());
    }

    @Test
    public void testPop() throws Exception {

        Assert.assertEquals(1.5, constantA.pop(), 0);
        Assert.assertEquals(1.5, constantA.pop(), 0);

        Assert.assertEquals(1, constantA.getSize());
    }

    @Test(expected = IllegalArgumentException.class)
    public void testPopExc() throws Exception {
        constantA.pop();
        constantA.pop();
        constantA.pop();
        constantA.pop();
        constantA.pop();
    }

    @Test
    public void testLastE() throws Exception {
        Assert.assertEquals(2.0, constantA.lastElement(), 0);
        Assert.assertEquals(2.0, constantA.lastElement(), 0);
        Assert.assertEquals(1.5, constantA.lastElement(), 0);
    }

    @Test(expected = IllegalArgumentException.class)
    public void testLastExc() throws Exception {
        constantA.lastElement();
        constantA.lastElement();
        constantA.lastElement();
        constantA.lastElement();
        constantA.lastElement();
        constantA.lastElement();
    }
}
