package Practice2;
public class Car2 {
    private String model;
    private String license;
    private String color;
    private int year;

    public Car2() {
        this.model = "-";
        this.license = "-";
        this.color = "-";
        this.year = 0;
    }

    public Car2(String model, int year) {
        this.model = model;
        this.license = "-";
        this.color = "-";
        this.year = year;
    }

    public Car2(String model, String license, String color, int year) {
        this.model = model;
        this.license = license;
        this.color = color;
        this.year = year;
    }

    public String toString() {
        return "Model: " + model + "\nLicense: " + license +
                "\nColor: " + color + "\nYear: " + year;
    }

    public int getYear() {
        return year;
    }

    public void setYear(int year) {
        this.year = year;
    }

    public static void main(String[] args) {
        System.out.print("\033[H\033[2J");
        Car2 car1 = new Car2();
        System.out.println(car1.toString());
        System.out.println();

        Car2 car2 = new Car2("Porshe 924", 1982);
        System.out.println(car2.toString());
        System.out.println();

        Car2 car3 = new Car2("Porshe 911 Turbo S", "X777XX777", "Black Carbon", 2023);
        System.out.println(car3.toString());
        System.out.println();

        car3.setYear(2019);
        System.out.println("После смены года: \n" + car3.toString());
    }
}
