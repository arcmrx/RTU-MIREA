package src;

public class BikeDriver {

	public static void main(String[] args) {

		RoadBike bike1 = new RoadBike();
		RoadBike bike2 = new RoadBike("drop", "tourer", "semi-grip", "comfort", 14, 25, 18);
		MountainBike bike3 = new MountainBike();
		Bike bike4 = new Bike();

		bike1.printDescription();
		bike2.printDescription();
		bike3.printDescription();
		bike4.printDescription();

		bike1.setPostHeight(20); // Обновляем высоту столба для bike1

		System.out.println("\nUpdate Post Height bike1: " + bike1.getPostHeight());
	}
}
