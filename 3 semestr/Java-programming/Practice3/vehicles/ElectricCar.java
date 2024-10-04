package Practice3.vehicles;

public class ElectricCar extends Car {
    private int batteryCapacity;

    public ElectricCar(String ownerName, String insuranceNumber, int batteryCapacity) {
        super(ownerName, insuranceNumber, "Электрический");
        this.batteryCapacity = batteryCapacity;
    }

    public int getBatteryCapacity() {
        return batteryCapacity;
    }

    public void setBatteryCapacity(int batteryCapacity) {
        this.batteryCapacity = batteryCapacity;
    }

    public void displayInfo() {
        super.displayInfo();
        System.out.println("Емкость аккумулятора: " + batteryCapacity + " кВт");
    }
}