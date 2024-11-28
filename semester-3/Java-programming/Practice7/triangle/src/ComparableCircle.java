public class ComparableCircle extends Circle implements Comparable<GeometricObject> {
    public ComparableCircle(double radius) {
        super(radius);
    }

    public int compareTo(ComparableCircle o) {
        return Double.compare(this.getArea(), o.getArea());
    }
}