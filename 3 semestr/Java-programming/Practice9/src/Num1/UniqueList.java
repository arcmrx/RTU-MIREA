package Num1;

import java.util.ArrayList;

public class UniqueList {
    public static <T> ArrayList<T> removeDuplicates(ArrayList<T> list) {
        ArrayList<T> uniqueList = new ArrayList<>();

        for (T element : list) {
            if (!uniqueList.contains(element)) {
                uniqueList.add(element);
            }
        }

        return uniqueList;
    }
}