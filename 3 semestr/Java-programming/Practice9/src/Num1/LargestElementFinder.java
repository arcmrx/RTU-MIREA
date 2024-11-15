package Num1;

public class LargestElementFinder {
    public static <T extends Comparable<T>> T findLargest(T[] elements) {
        if (elements == null || elements.length == 0) {
            return null;
        }
        T largest = elements[0];
        for (T element : elements) {
            if (element.compareTo(largest) > 0) {
                largest = element;
            }
        }
        return largest;
    }
}
