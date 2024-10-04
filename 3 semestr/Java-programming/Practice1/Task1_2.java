package Practice1;
import java.util.Scanner;

public class Task1_2 {
    public static void main(String args[]) {
        final double ROUBLES_PER_YUAN = 1;
        Scanner in = new Scanner(System.in);
        System.out.print("Введите кол-во денег в юанях: ");
        double yuan = in.nextDouble();
        double roubles = ROUBLES_PER_YUAN * yuan;
        int digit = (int) yuan % 10;
        if (digit == 1) {
            System.out.printf(yuan + " китайский юань в рублях: %.2f \n", roubles);
        }
        if (digit > 1 && digit < 5) {
            System.out.printf(yuan + " китайских юаня в рублях: %.2f \n", roubles);
        }
        if (digit >= 5 || digit == 0) {
            System.out.printf(yuan + " китайских юаней в рублях: %.2f \n", roubles);
        }
        in.close();
    }
}
