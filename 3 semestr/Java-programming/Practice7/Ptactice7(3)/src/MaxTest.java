public class MaxTest {
    public static void main(String[] args) {
        // Создаем два круга
        Circle circle1 = new Circle(3.0, "red", true);
        Circle circle2 = new Circle(4.0, "blue", false);

        // Находим наибольший круг
        System.out.println("Наибольший круг: " + GeometricObject.max(circle1, circle2));

        // Создаем два прямоугольника
        Rectangle rect1 = new Rectangle(2.0, 5.0, "green", true);
        Rectangle rect2 = new Rectangle(3.0, 4.0, "yellow", false);

        // Находим наибольший прямоугольник
        System.out.println("Наибольший прямоугольник: " + GeometricObject.max(rect1, rect2));
    }
}
