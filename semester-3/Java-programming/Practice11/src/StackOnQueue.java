import java.util.LinkedList;
import java.util.Queue;

public class StackOnQueue {
    private Queue<Integer> queue1;
    private Queue<Integer> queue2;

    public StackOnQueue() {
        queue1 = new LinkedList<>();
        queue2 = new LinkedList<>();
    }

    void push(int x) {
        queue2.offer(x); // добавить
        while (!queue1.isEmpty()) {
            queue2.offer(queue1.poll()); // 1 вернуть удалить
        }
        Queue<Integer> temp = queue1;
        queue1 = queue2;
        queue2 = temp;
    }

    int pop() {
        if (queue1.isEmpty()) {
            throw new RuntimeException("Тут пусто");
        }
        return queue1.poll();
    }

    int top() {
        if (queue1.isEmpty()) {
            throw new RuntimeException("Тут пусто");
        }
        return queue1.peek();
    }

    boolean empty() {
        return queue1.isEmpty();
    }

    public String toString() {
        return queue1.toString();
    }
}
