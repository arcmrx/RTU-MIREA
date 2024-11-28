public class Square extends GeometricObject implements Colorable {
    private double side;

    public Square() {
    }

    public Square(double side) {
        this.side = side;
    }

    public double getSide() {
        return side;
    }

    public void setSide(double side) {
        this.side = side;
    }

    public double getArea() {
        return side * side;
    }

    public double getPerimeter() {
        return 4 * side;
    }

    @Override
    public void howToColor() {
        System.out.println("Закрасьте все стороны квадрата.");
    }

    @Override
    public String toString() {
        return "Квадрат со стороной " + side;
    }
}