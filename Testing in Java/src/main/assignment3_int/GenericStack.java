package assignment3_int;

/** Interface for a generic stack */
public interface GenericStack<E> {
   public E pop() throws Exception;
   public E peek() throws Exception;
   public void push(E element);
   public E lastElement() throws Exception;
   public boolean isEmpty();
   public int getSize() throws Exception;

}