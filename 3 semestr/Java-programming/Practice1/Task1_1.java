package Practice1;
import java.util.Scanner;

public class Task1_1 {
    public static void main(String args[]) {
        final double ROUBLES_PER_YUAN = 11.91;
        Scanner in = new Scanner(System.in);
        System.out.print("Введите кол-во денег в юанях: ");
        double yuan = in.nextDouble();
        double roubles = ROUBLES_PER_YUAN * yuan;
        System.out.printf("Кол-во денег в рублях: %.2f \n", roubles);
        in.close();
    }
}