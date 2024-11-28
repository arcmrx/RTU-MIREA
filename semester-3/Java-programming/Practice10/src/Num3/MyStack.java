package Num3;

import java.util.ArrayList;

public class MyStack {
    private ArrayList<Object> list;

    public MyStack() {
        list = new ArrayList<>();
    }

    public MyStack(MyStack other) {
        this.list = new ArrayList<>(other.list);
    }

    public boolean isEmpty() {
        return list.isEmpty();
    }

    public int getSize() {
        return list.size();
    }

    public Object peek() {
        return list.get(getSize() - 1);
    }

    public Object pop() {
        return list.remove(getSize() - 1);
    }

    public void push(Object o) {
        list.add(o);
    }
}
