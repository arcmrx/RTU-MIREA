public class Car {
    private String model;
    private String license;
    private String color;
    private int year;

    public Car() {
        this.model = "-";
        this.license = "-";
        this.color = "-";
        this.year = 0;
    }

    public Car(String model, int year) {
        this.model = model;
        this.license = "-";
        this.color = "-";
        this.year = year;
    }

    public Car(String model, String license, String color, int year) {
        this.model = model;
        this.license = license;
        this.color = color;
        this.year = year;
    }

    public void output() {
        System.out.println("Model: " + model);
        System.out.println("License: " + license);
        System.out.println("Color: " + color);
        System.out.println("Year: " + year);
    }

    public static void main(String[] args) {
        System.out.print("\033[H\033[2J");
        Car car1 = new Car();
        car1.output();

        System.out.println();
        Car car2 = new Car("Porshe 924", 1982);
        car2.output();

        System.out.println();
        Car car3 = new Car("Porshe 911 Turbo S", "х777хх777", "Black Carbon", 2023);
        car3.output();
    }
}