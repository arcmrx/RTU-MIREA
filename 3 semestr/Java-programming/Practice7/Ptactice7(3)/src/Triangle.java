class Triangle extends GeometricObject {
    private double side1;
    private double side2;
    private double side3;

    // Конструктор с параметрами
    public Triangle(double side1, double side2, double side3, String color, boolean filled) {
        super(color, filled);

        // Проверка условия треугольника
        if (side1 + side2 <= side3 || side1 + side3 <= side2 || side2 + side3 <= side1) {
            throw new IllegalArgumentException("Сумма любых двух сторон должна быть больше третьей.");
        }
        
        this.side1 = side1;
        this.side2 = side2;
        this.side3 = side3;
    }

    // Getter для сторон треугольника
    public double getSide1() {
        return side1;
    }

    public double getSide2() {
        return side2;
    }

    public double getSide3() {
        return side3;
    }

    // Метод для вычисления периметра
    @Override
    public double getPerimeter() {
        return side1 + side2 + side3;
    }

    // Метод для вычисления площади
    @Override
    public double getArea() {
        double s = getPerimeter() / 2; // Полупериметр
        return Math.sqrt(s * (s - side1) * (s - side2) * (s - side3));
    }

    // Переопределение метода toString
    @Override
    public String toString() {
        return "Triangle: side1 = " + side1 + " side2 = " + side2 + " side3 = " + side3 +
               ", color = " + getColor() + ", filled = " + isFilled();
    }
}
