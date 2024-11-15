package Num2;

public class TestGenericStack {
    public static void main(String[] args) {
        GenericStack<String> stack1 = new GenericStack<>(5);

        stack1.push("London");
        stack1.push("Paris");
        stack1.push("Berlin");
        stack1.push("New York");
        stack1.push("San Francisco");

        System.out.println("Размер: " + stack1.getSize()); // проверка getSize()
        stack1.push("San Francisco");
        System.out.println("Размер: " + stack1.getSize()); // проверка getSize()

        System.out.println("stack1:");
        while (!stack1.isEmpty()) {
            System.out.print(stack1.pop() + " ");
        }

        GenericStack<Integer> stack2 = new GenericStack<>(5);

        stack2.push(1);
        stack2.push(2);
        stack2.push(3);
        stack2.push(4);
        stack2.push(5);


        System.out.println("\n" + stack2.peek()); // проверка Pick-Me Girl()

        System.out.println("\nstack2:");
        while (!stack2.isEmpty()) {
            System.out.print(stack2.pop() + " "); // проверка церкви
        }

        System.out.println("\n" + stack2.isEmpty());
        stack2.push(5);
        System.out.println(stack2.isEmpty());

    }
}
