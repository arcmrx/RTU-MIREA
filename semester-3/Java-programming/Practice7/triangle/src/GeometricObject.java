public abstract class GeometricObject implements Comparable<GeometricObject> {
    private String color = "белый";
    private boolean filled;
    private java.util.Date dateCreated;

    /**
     * Создает по умолчанию заданный геометрический объект
     */
    public GeometricObject() {
        dateCreated = new java.util.Date();
    }

    /**
     * Создает геометрический объект с указанным цветом и заливкой
     */
    public GeometricObject(String color, boolean filled) {
        dateCreated = new java.util.Date();
        this.color = color;
        this.filled = filled;
    }

    /**
     * Возвращает цвет
     */
    public String getColor() {
        return color;
    }

    /**
     * Присваивает новый цвет
     */
    public void setColor(String color) {
        this.color = color;
    }

    /**
     * Возвращает заливку. Поскольку filled типа boolean,
     * getter-метод называется isFilled
     */
    public boolean isFilled() {
        return filled;
    }

    /**
     * Присваивает новую заливку
     */
    public void setFilled(boolean filled) {
        this.filled = filled;
    }

    /**
     * Получает dateCreated
     */
    public java.util.Date getDateCreated() {
        return dateCreated;
    }

    /**
     * Возвращает строковое представление этого объекта
     */
    public String toString() {
        return "создан " + dateCreated + ",\nцвет: " + color +
                ", заливка: " + filled;
    }

    public abstract double getArea();

    public abstract double getPerimeter();

    public static double max(GeometricObject o1, GeometricObject o2) {
        return (o1.compareTo(o2) > 0 ? o1 : o2).getArea();
    }

    public int compareTo(GeometricObject o) {
        return Double.compare(this.getArea(), o.getArea());
    }

}