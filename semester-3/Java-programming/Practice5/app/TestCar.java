package Practice5.app;

import Practice5.vehicles.Car;
import Practice5.vehicles.ElectricCar;

public class TestCar {
    public static void main(String[] args) {

        System.out.print("\033[H\033[2J");

        Car car = new Car("Porshe 911", "X777XX777", "Black", 2021, "Arthur V", "STR123");
        ElectricCar electricCar = new ElectricCar("Tesla", "B888BB88", "White", 2021, "Arthur V", "STR456",
                100);

        car.setYear(2023);
        car.setOwnerName("Matthew H");

        electricCar.setInsuranceNumber("STR888");

        System.out.println("Battery capacity of electric car: " + electricCar.getBatteryCapacity() + " кВт");

        System.out.println(car.toString());
        System.out.println(electricCar.toString());
    }
}
