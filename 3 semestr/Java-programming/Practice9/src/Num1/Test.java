package Num1;

import java.util.ArrayList;

import static Num1.UniqueList.removeDuplicates;
import static Num1.LinearSearch.linearSearch;

public class Test {
    public static void main(String[] args) {

        // #1

        ArrayList<Integer> numbers = new ArrayList<>();
        numbers.add(1);
        numbers.add(2);
        numbers.add(2);
        numbers.add(3);
        numbers.add(4);
        numbers.add(4);
        numbers.add(5);

        ArrayList<Integer> uniqueNumbers = removeDuplicates(numbers);

        System.out.println("Было: " + numbers);
        System.out.println("Стало: " + uniqueNumbers);

        // #2

        String[] numbersSearch = {"3", "5", "7", "9", "11", "13", "15"};
        String target = "9";

        int position = linearSearch(numbersSearch, target);

        if (position != -1) {
            System.out.println("Элемент " + target + " на позиции: " + position);
        } else {
            System.out.println("Элемент не найден.");
        }

        // #3

        Circle[] circles = {
                new Circle(1),
                new Circle(2),
                new Circle(3),
                new Circle(4),
                new Circle(5)
        };

        double radius = circles[1].getRadius();
        System.out.println("Радиус круга: " + radius); // Сделал чтобы не было ошибки

        Circle largestCircle = LargestElementFinder.findLargest(circles);
        System.out.println("Наибольший элемент : " + largestCircle);

        Integer[] numbs = {1, 2, 3, 5, 6, 4, 9, 4, 3};
        Integer largestNum = LargestElementFinder.findLargest(numbs);
        System.out.println("Наибольший элемент : " + largestNum);

        // #4

        Integer[][] numbers2D = {
                {1, 2, 3},
                {8, 9, 4},
                {7, 6, 5}
        };
        Integer largestNumber2D = LargestElementFinder2D.findLargest(numbers2D);
        System.out.println("Наибольший элемент в двумерном массиве: " + largestNumber2D);

    }
}