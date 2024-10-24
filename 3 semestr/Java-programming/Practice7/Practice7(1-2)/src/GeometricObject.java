class GeometricObject {
    private String color;
    private boolean isFilled;

    public GeometricObject() {
        this.color = "white";
        this.isFilled = false;
    }

    public GeometricObject(String color, boolean isFilled) {
        this.color = color;
        this.isFilled = isFilled;
    }

    public String getColor() {
        return this.color;
    }

    public void setColor(String color) {
        this.color = color;
    }

    public boolean isFilled() {
        return this.isFilled;
    }

    public void setFilled(boolean isFilled) {
        this.isFilled = isFilled;
    }

    public String toString() {
        return "Color: " + color + ", Filled: " + isFilled;
    }
}
