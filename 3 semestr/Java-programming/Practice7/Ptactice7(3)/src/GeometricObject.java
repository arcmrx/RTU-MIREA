public abstract class GeometricObject implements Comparable<GeometricObject> {
    private String color;
    private boolean filled;

    // Конструктор по умолчанию
    public GeometricObject() {
        this.color = "white";
        this.filled = false;
    }

    // Конструктор с параметрами
    public GeometricObject(String color, boolean filled) {
        this.color = color;
        this.filled = filled;
    }

    // Getter и Setter для color
    public String getColor() {
        return color;
    }

    public void setColor(String color) {
        this.color = color;
    }

    // Getter и Setter для filled
    public boolean isFilled() {
        return filled;
    }

    public void setFilled(boolean filled) {
        this.filled = filled;
    }

    // Абстрактные методы для вычисления площади и периметра
    public abstract double getArea();

    public abstract double getPerimeter();

    // Реализация метода compareTo для интерфейса Comparable
    @Override
    public int compareTo(GeometricObject o) {
        return Double.compare(this.getArea(), o.getArea());
    }

    // Статический метод для поиска наибольшего объекта
    public static GeometricObject max(GeometricObject o1, GeometricObject o2) {
        return (o1.compareTo(o2) >= 0) ? o1 : o2;
    }
}
