package Semkin_Barkov;

import assignment3_int.GenericStack;

public class ConstantArray<E> implements GenericStack<E> {

    private Object[] storage;
    private int size;

    public ConstantArray() {
        storage = new Object[0];
        size = 0;
    }

    @Override
    public E pop() throws Exception {                   //Returns the top item of this Array and removes it

        if (size == 0) {
            throw new IllegalArgumentException("Please do not pop on empty stack");
        } else {
            E output = (E) storage[0];                  // first element
            Object[] recover = new Object[storage.length - 1];
            System.arraycopy(storage, 1, recover, 0, recover.length);

            size--;
            return output;
        }
    }

    @Override
    public E peek() throws Exception {                 //Returns the top item of this Array without removing it
        if (size == 0) {
            throw new IllegalArgumentException("The Stack is empty.");
        }
        return (E) storage[0];
    }

    @Override
    public void push(E element) {                       //Adds a new Element to the Array

        if (size == 0) {
            storage = new Object[1];
            storage[0] = element;
            size++;
        } else {
            Object[] recover = new Object[storage.length + 1];
            System.arraycopy(storage, 0, recover, 0, storage.length);
            recover[recover.length - 1] = element;

            storage = recover;
            size++;
        }
    }

    @Override
    public E lastElement() throws Exception {           //Same as pop but returns and deletes the last element

        if (size == 0) {
            throw new IllegalArgumentException("The Array is empty. Please insert Elements before delete them.");
        } else {
            E output = (E) storage[storage.length - 1];
            Object[] recover = new Object[storage.length - 1];
            System.arraycopy(storage, 0, recover, 0, recover.length);

            storage = recover;

            size--;
            return output;
        }
    }

    @Override
    public boolean isEmpty() {                          //Returns true if this array contains no items
        return size == 0;
    }

    @Override
    public int getSize() throws Exception {
        return size;
    }
}