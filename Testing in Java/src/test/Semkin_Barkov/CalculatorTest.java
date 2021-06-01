package Semkin_Barkov;
import org.junit.Assert;
import org.junit.Before;
import org.junit.Test;

public class CalculatorTest {

    private Assignment3 test3;
    private String[] input, input1, input2, input3, input4, input5, input6;

    @Before
    public void setUp() {

        test3 = new Assignment3();
        input = new String[]{"1.5", "2", "+", "3", "4", "-", "*"};     // -3.5
        input1 = new String[]{"5", "0.5", "/", "8", "*"};              // 80
        input2 = new String[]{"3", "5", "3", "*", "-"};                // -12
        input3 = new String[]{"3", "3", "5", "*", "+"};                // 18
        input4 = new String[]{"2", "2", "+", "5", "*"};                // 20
        input5 = new String[]{"2", "2", "+", "0", "/"};                // Nan
        input6 = new String[]{"2","3","4","6"};
    }

    @Test
    public void testCalc () throws Exception {

        Assert.assertEquals(test3.calc(input, test3.getArrayStack()), -3.5, 0);
        Assert.assertEquals(test3.calc(input1, test3.getArrayStack()), 80.0, 0);
        Assert.assertEquals(test3.calc(input2, test3.getArrayStack()), -12.0, 0);
        Assert.assertEquals(test3.calc(input3, test3.getArrayStack()), 18.0, 0);
        Assert.assertEquals(test3.calc(input4, test3.getArrayStack()), 20.0, 0);
    }

    @Test(expected = IllegalArgumentException.class)
    public void testDivision() throws Exception {
        test3.calc(input5, test3.getListStack());
    }

    @Test(expected = IllegalArgumentException.class)
    public void testOperators() throws Exception{
        test3.calc(input6, test3.getArrayStack());
    }

    @Test(expected = IllegalArgumentException.class)
    public void testIsOper(){
        test3.hasOperator(input6);
    }
}
