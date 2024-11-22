package Num3;

import java.util.Scanner;

public class TestMyStack {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        MyStack stack = new MyStack();

        System.out.println("Введите пять строк:");

        for (int i = 0; i < 5; i++) {
            String input = scanner.nextLine();
            stack.push(input);
        }

        MyStack stack2 = new MyStack(stack);

        System.out.println("Стек:");
        while (!stack.isEmpty()) {
            System.out.println(stack.pop());
        }

        System.out.println("Стек 2:");
        while (!stack2.isEmpty()) {
            System.out.println(stack2.pop());
        }

        scanner.close();
    }
}
