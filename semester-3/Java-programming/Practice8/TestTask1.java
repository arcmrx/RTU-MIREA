import java.util.Scanner;

public class TestTask1 {
    public static void main(String[] args) {
        try {
            Scanner sc = new Scanner(System.in);
            System.out.println("Введите номер месяца");
            int month = sc.nextInt();
            sc.close();
            @SuppressWarnings("unused")
            task1 task = new task1(month);
            String[] months = {"январь", "февраль", "март", "апрель", "май",
                    "июнь", "июль", "август", "сентябрь", "октябрь", "ноябрь", "декабрь"};
            int[] dom = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
            if (month == 2) {
                System.out.println("Введите год");
                int year = sc.nextInt();
                if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) {
                    System.out.println(months[month - 1] + ' ' + 29);
                } else {
                    System.out.println(months[month - 1] + ' ' + 28);
                }
            } else {
                System.out.println(months[month - 1] + ' ' + dom[month - 1]);
            }
        } catch (ArrayIndexOutOfBoundsException e) {
            System.out.println("Ошибка: " + e.getMessage());
        }
        System.out.println("А вот и продолжение");
    }
}
