package src;

public interface MountainParts {
    String TERRAIN = "off_road";

    String getSuspension(); // Подвеска

    void setSuspension(String newValue);

    String getType(); // Тип велосипеда

    void setType(String newValue);
}
