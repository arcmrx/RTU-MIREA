package Num2;

public class GenericStack<E> {
    private E[] list;
    private int size = 0;

    @SuppressWarnings("unchecked")
    public GenericStack(int size) {
        list = (E[]) new Object[size];
    }

    public int getSize() {
        return list.length;
    }

    public E peek() {
        if (size == 0) {
            throw new java.util.EmptyStackException();
        }
        return list[size - 1];
    }

    public void push(E o) {
        if (size == list.length) {
            doubleList();
        }
        list[size++] = o;
    }

    private void doubleList() {
        @SuppressWarnings("unchecked")
        E[] newList = (E[]) new Object[list.length * 2];
        System.arraycopy(list, 0, newList, 0, list.length);
        list = newList;
    }

    public E pop() {
        if (size == 0) {
            throw new java.util.EmptyStackException();
        }
        E o = list[--size];
        list[size] = null;
        return o;
    }

    public boolean isEmpty() {
        return size == 0;
    }
}