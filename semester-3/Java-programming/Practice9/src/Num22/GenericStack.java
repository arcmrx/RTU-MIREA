package Num22;

import java.util.ArrayList;

public class GenericStack<E> extends ArrayList<E> {
    public void push(E item) {
        add(item);
    }

    public E pop() {
        if (isEmpty()) {
            throw new java.util.EmptyStackException();
        }
        return remove(size() - 1);
    }

    public E peek() {
        if (isEmpty()) {
            throw new java.util.EmptyStackException();
        }
        return get(size() - 1);
    }

    public boolean isEmpty() {
        return size() == 0;
    }
}