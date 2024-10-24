package src;

public interface RoadParts {
    String terrain = "track_racing";

    int getTyreWidth(); // Ширина шины

    void setTyreWidth(int newValue);

    int getPostHeight(); // Высота сиденья

    void setPostHeight(int newValue);
}
