public class Square extends GeometricObject implements Colorable {
    private double side;

    // Безаргументный конструктор
    public Square() {
        this.side = 0;
    }

    // Конструктор с параметром
    public Square(double side) {
        this.side = side;
    }

    // Getter для стороны
    public double getSide() {
        return side;
    }

    // Setter для стороны
    public void setSide(double side) {
        this.side = side;
    }

    // Метод для вычисления площади
    @Override
    public double getArea() {
        return side * side;
    }

    // Метод для вычисления периметра
    @Override
    public double getPerimeter() {
        return 4 * side;
    }

    // Реализация метода howToColor из интерфейса Colorable
    @Override
    public void howToColor() {
        System.out.println("Раскрасьте все четыре стороны.");
    }

    // Переопределение toString для отображения информации о квадрате
    @Override
    public String toString() {
        return "Квадрат: сторона = " + side;
    }
}