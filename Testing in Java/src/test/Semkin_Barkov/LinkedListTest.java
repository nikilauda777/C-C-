package Semkin_Barkov;
import org.junit.Assert;
import org.junit.Before;
import org.junit.Test;

public class LinkedListTest {

    LinkedList<Double> linkedL = new LinkedList<>();

    @Before
    public void setUp(){
        linkedL.push(1.0);
        linkedL.push(2.0);
        linkedL.push(3.0);
        linkedL.push(4.0);
    }

    @Test
    public void testSize(){
        Assert.assertEquals(4, linkedL.getSize());

        linkedL.pop();
        linkedL.pop();
        linkedL.pop();
        linkedL.pop();

        Assert.assertEquals(0, linkedL.getSize());
    }

    @Test
    public void testEmpty(){
        Assert.assertFalse(linkedL.isEmpty());

        linkedL.pop();
        linkedL.pop();
        linkedL.pop();
        linkedL.pop();

        Assert.assertTrue(linkedL.isEmpty());
    }

    @Test
    public void testPush(){

        Assert.assertEquals(4, linkedL.getSize());

        linkedL.push(3.0);
        linkedL.push(3.0);
        linkedL.push(3.0);

        Assert.assertEquals(7, linkedL.getSize());
    }

    @Test
    public void testLastE() throws Exception {

        Assert.assertEquals(4.0, linkedL.lastElement(), 0);

        linkedL.lastElement();
        linkedL.lastElement();


        Assert.assertEquals(1, linkedL.getSize());
    }

    @Test(expected = IllegalArgumentException.class)
    public void testLastExc() throws Exception {
        linkedL.lastElement();
        linkedL.lastElement();
        linkedL.lastElement();
        linkedL.lastElement();
        linkedL.lastElement();
    }

    @Test
    public void testPop(){
        Assert.assertEquals(1.0, linkedL.pop(), 0);
        Assert.assertEquals(2.0, linkedL.pop(), 0);
        Assert.assertEquals(2, linkedL.getSize());
    }

    @Test(expected = IllegalArgumentException.class)
    public void testPopExc(){
        linkedL.pop();
        linkedL.pop();
        linkedL.pop();
        linkedL.pop();
        linkedL.pop();
        linkedL.pop();
        linkedL.pop();
    }

    @Test
    public void testPeek(){
        Assert.assertEquals(1.0, linkedL.peek(), 0);
        linkedL.pop();
        Assert.assertEquals(2.0, linkedL.peek(), 0);
    }
}
