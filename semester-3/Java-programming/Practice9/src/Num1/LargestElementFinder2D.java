package Num1;

public class LargestElementFinder2D {
    public static <T extends Comparable<T>> T findLargest(T[][] elements) {
        if (elements == null || elements.length == 0 || elements[0].length == 0) {
            return null;
        }
        T largest = elements[0][0];
        for (T[] row : elements) {
            for (T element : row) {
                if (element.compareTo(largest) > 0) {
                    largest = element;
                }
            }
        }
        return largest;
    }
}