public class TestGeometricObjects {
    public static void main(String[] args) {
        // Создание массива из 5 объектов GeometricObject
        GeometricObject[] shapes = new GeometricObject[5];

        // Заполнение массива
        shapes[0] = new Circle(2.5, "red", true);
        shapes[1] = new Rectangle(4.0, 5.0, "blue", false);
        shapes[2] = new Triangle(3.0, 4.0, 5.0, "green", true);
        shapes[3] = new Square(2.0); // Квадрат
        shapes[4] = new ComparableCircle(3.0, "yellow", true); // Сравниваемый круг

        // Перебор массива и вывод информации
        for (GeometricObject shape : shapes) {
            System.out.println("Площадь: " + shape.getArea());
            if (shape instanceof Colorable) {
                ((Colorable) shape).howToColor(); // Вызов метода howToColor, если объект раскрашиваемый
            }
            System.out.println(shape); // Вывод информации о фигуре
            System.out.println();
        }
    }
}