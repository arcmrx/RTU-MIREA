package Num22;

import java.util.Scanner;

public class TestGenericStack {
    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);
        GenericStack<String> stack = new GenericStack<>();

        stack.pop();

        System.out.println("Пять строк сюда:");
        for (int i = 0; i < 5; i++) {
            String input = scanner.nextLine();
            stack.push(input);
        }

        System.out.println("А тут наоборот:");
        while (!stack.isEmpty()) {
            System.out.println(stack.pop());
        }

        scanner.close();
    }
}