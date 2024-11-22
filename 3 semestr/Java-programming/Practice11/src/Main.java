public class Main {
    public static void main(String[] args) {

        StackOnQueue stack = new StackOnQueue();

        stack.push(1);
        stack.push(2);

        System.out.println(stack);
        System.out.println(stack.top());
        System.out.println(stack);
        System.out.println(stack.pop());
        System.out.println(stack);
        System.out.println(stack.empty());
        System.out.println(stack);
    }
}