public class ComparableCircleTest {
    public static void main(String[] args) {
        // Создаем два объекта ComparableCircle
        ComparableCircle circle1 = new ComparableCircle(3.0, "red", true);
        ComparableCircle circle2 = new ComparableCircle(5.0, "blue", false);

        // Находим наибольший круг
        GeometricObject biggerCircle = (circle1.compareTo(circle2) >= 0) ? circle1 : circle2;
        System.out.println("Наибольший круг: " + biggerCircle);

        // Сравнение круга с прямоугольником
        Rectangle rect = new Rectangle(6.0, 4.0, "yellow", true);
        GeometricObject bigger = GeometricObject.max(circle1, rect);
        System.out.println("Наибольший между кругом и прямоугольником: " + bigger);
    }
}
