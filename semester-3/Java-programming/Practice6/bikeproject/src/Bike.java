package src;

public class Bike implements BikeParts {

	private String handleBars, frame, tyres, seatType; // руль, рама, шины, сиденье
	private int NumGears; // передачи
	private final String make; // создатель

	public Bike() {
		this.make = BikeParts.companyName;
	}

	public Bike(String handleBars, String frame, String tyres, String seatType, int numGears) {
		this.handleBars = handleBars;
		this.frame = frame;
		this.tyres = tyres;
		this.seatType = seatType;
		NumGears = numGears;
		this.make = BikeParts.companyName;
	}

	public String getCompanyName() {
		return this.make;
	}

	protected void printDescription() {
		System.out.println("\n" + this.make + "\n"
				+ "This bike has " + this.handleBars + " handlebars on a "
				+ this.frame + " frame with " + this.NumGears + " gears."
				+ "\nIt has a " + this.seatType + " seat with " + this.tyres + " tyres.");
	}
}
