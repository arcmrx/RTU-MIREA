package Num12;

import java.util.Scanner;

public class TestMyStack {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        MyStack stack = new MyStack();
        MyStackArray stackArray = new MyStackArray();

        System.out.println("Введите пять строк:");

        for (int i = 0; i < 5; i++) {
            String input = scanner.nextLine();
            stack.push(input);
            stackArray.push(input);
        }

        System.out.println("Строки в обратном порядке MyStack:");
        while (!stack.isEmpty()) {
            System.out.println(stack.pop());
        }

        System.out.println("Строки в обратном порядке MyStackArray:");
        while (!stackArray.isEmpty()) {
            System.out.println(stackArray.pop());
        }

        scanner.close();
    }
}
