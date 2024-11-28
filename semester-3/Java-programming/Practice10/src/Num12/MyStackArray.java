package Num12;

import java.util.ArrayList;

public class MyStackArray extends ArrayList<Object> {
    public boolean isEmpty() {
        return super.isEmpty();
    }

    public int getSize() {
        return super.size();
    }

    public Object peek() {
        return super.get(getSize() - 1);
    }

    public Object pop() {
        return super.remove(getSize() - 1);
    }

    public void push(Object o) {
        super.add(o);
    }
}
