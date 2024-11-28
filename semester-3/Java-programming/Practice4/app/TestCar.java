package Practice4.app;

import Practice4.vehicles.Car;
import Practice4.vehicles.ElectricCar;
import Practice4.vehicles.Vehicle;

public class TestCar {
    public static void main(String[] args) {

        System.out.print("\033[H\033[2J");
        
        Vehicle myCar = new Car("Porshe 911", "X777XX777", "Black", 2023, "Arthur V", "STR123");
        Vehicle myElectricCar = new ElectricCar("Tesla", "B888BB88", "White", 2023, "Arthur V", "STR456", 100);

        myCar.setColor("Red");
        myElectricCar.setOwnerName("Matthew H");

        System.out.println(myCar.toString());
        System.out.println(myElectricCar.toString());
    }
}