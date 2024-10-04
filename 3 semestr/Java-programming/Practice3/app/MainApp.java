package Practice3.app;

import Practice3.vehicles.Car;
import Practice3.vehicles.ElectricCar;

public class MainApp {
    public static void main(String[] args) {

        System.out.print("\033[H\033[2J");

        Car car = new Car("Джон Уик", "XXX7777777777", "Бензиновый");
        car.displayInfo();

        System.out.println();

        ElectricCar electricCar = new ElectricCar("Тони Старк", "MMM7777777777", 125);
        electricCar.displayInfo();
    }
}