package Semkin_Barkov;

import assignment3_int.GenericStack;

public class LinkedList<E> implements GenericStack<E> {

    private Node head;
    private Node tail;
    private int size;


    public LinkedList() {
        head = null;
        tail = null;
        size = 0;
    }


    @Override
    public void push(E element) {                   //LIFO - add new element

        if (head == null || head.data == null) {
            head = new Node(element);
            tail = null;
        } else {
            Node n = head;
            while (n.next != null) {
                n = n.next;
            }
            n.next = new Node(element);
            tail = n.next;
            tail.next = null;
        }
        size++;
    }

    @Override
    public E lastElement() throws Exception {        // Same as pop but with the last element

        if (head == null) {                         // If the Stack is empty
            throw new IllegalArgumentException("The List is empty. Please insert new elements before delete them.");
        }
        if (head.next == null) {// If only head is provided
            E l = head.data;
            head = null;
            size--;
            return l;
        }
        if (head == tail) {
            E l = head.data;
            head = null;
            size--;
            return l;
        }

        Node last = head;


        while (last.next != tail) {                 // Go to the tail

            last = last.next;
        }

        E l = tail.data;                            // return data of the last element
        tail = last;
        tail.next = null;                           // Set tail on the previous element
        size--;

        return l;
    }

    @Override
    public E pop() {                                //Returns the top item of this stack and removes it
        if (head == null) {
            throw new IllegalArgumentException("The List is empty. Please insert new elements before delete them");
        }

        E d = head.data;
        head = head.next;
        size--;
        return d;
    }

    @Override                                       //Returns the top item of this stack without removing it
    public E peek() {
        if (head == null) {
            throw new IllegalArgumentException("The List is empty. Please insert new elements before delete them");
        }
        return head.data;
    }

    @Override
    public boolean isEmpty() {
        if (head == null) {
            return true;
        }
        return false;
    }

    @Override
    public int getSize() {
        return size;
    }

    private class Node {

        E data;
        Node next;

        Node(E d) {
            data = d;
            next = null;
        }
    }
}