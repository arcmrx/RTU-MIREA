import java.util.Scanner;

public class TestGeometricObjects {
    public static void main(String[] args) {
        try {
            Scanner input = new Scanner(System.in);

            // Ввод данных для треугольника
            System.out.print("Введите три стороны треугольника: ");
            double side1 = input.nextDouble();
            double side2 = input.nextDouble();
            double side3 = input.nextDouble();
            System.out.print("Введите цвет: ");
            String color = input.next();
            System.out.print("Треугольник закрашен? (true/false): ");
            boolean filled = input.nextBoolean();

            input.close();

            Triangle triangle = new Triangle(side1, side2, side3);
            triangle.setColor(color);
            triangle.setFilled(filled);

            System.out.println(triangle);
            System.out.println("Площадь треугольника: " + triangle.getArea());
            System.out.println("Периметр треугольника: " + triangle.getPerimeter());
            System.out.println("Цвет треугольника: " + triangle.getColor());
            System.out.println("Треугольник закрашен? " + triangle.isFilled());

            // Тестирование max() и Comparable
            Circle circle1 = new Circle(5);
            Circle circle2 = new Circle(3);
            double biggerCircle = GeometricObject.max(circle1, circle2);
            System.out.println("Больший из двух кругов c площадью: " + biggerCircle);

            Rectangle rectangle1 = new Rectangle(2, 5);
            Rectangle rectangle2 = new Rectangle(3, 4);
            double biggerRectangle = GeometricObject.max(rectangle1, rectangle2);
            System.out.println("Больший из двух прямоугольников с площадью: " + biggerRectangle);

            System.out.println("Больший из прямоугольника и круга фигура с площадью: " + Math.max(biggerCircle, biggerRectangle));
            // Тестирование Square и Colorable
            Square[] squares = {new Square(1), new Square(2), new Square(3), new Square(4), new Square(5)};
            for (Square square : squares) {
                square.howToColor();
                System.out.println(square);
                System.out.println("Площадь: " + square.getArea());
            }

        } catch (IllegalTriangleException ex) {
            System.out.println("Ошибка: " + ex.getMessage());
        }
    }
}
