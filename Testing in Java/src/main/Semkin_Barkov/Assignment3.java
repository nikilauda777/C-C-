package Semkin_Barkov;

import assignment3_int.Calculator;
import assignment3_int.GenericStack;

public class Assignment3 implements Calculator {

    public Assignment3() {
        //empty Constructor
    }


    @Override
    public double calc(String[] input, GenericStack<Double> stack) throws Exception {

        hasOperator(input);

        try {
            for (int i = 0; i < input.length; i++) {

                if (input[i].matches("[0-9]{1,13}(\\.[0-9]*)?")) {      // All digits with Doubles
                    stack.push(Double.parseDouble(input[i]));

                } else {
                    double stnext = stack.lastElement();                       // Get two last added elements
                    double st = stack.lastElement();

                    stack.push(isOperant(input[i], st, stnext));               // Add the result back to stack
                }
            }
        } catch (Exception ex) {
            ex.printStackTrace();
        }

        return stack.lastElement();
    }

    /*** Calculate the sum**/

    public double isOperant(String symbols, double a, double b) throws Exception {

        double result = 0.0;

        if (symbols.equals("+")) {
            result = a + b;
        } else if (symbols.equals("-")) {
            result = a - b;
        } else if (symbols.equals("*")) {
            result = a * b;
        } else if (symbols.equals("/")) {
            if (b == 0) {
                throw new IllegalArgumentException("DIVISION BY ZERO IS NOT POSSIBLE");
            }
            result = a / b;
        }

        return result;
    }

    public boolean hasOperator(String[] input) {

        for (int i = 0; i < input.length; i++) {
            if (input[i].matches("[-+/*]")) {
                return true;
            }
        }
        throw new IllegalArgumentException("No Operators provided in the list");
    }

    @Override
    public GenericStack<Double> getArrayStack() {
        return new ConstantArray<>();
    }

    @Override
    public GenericStack<Double> getListStack() {
        return new LinkedList<>();
    }
}