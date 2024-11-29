import java.util.Scanner;

public class Main {
    public static void main(String[] args) {

        System.out.print("\033[H\033[2J");

        Scanner scanner = new Scanner(System.in);
        System.out.print("Введите текст: ");
        String text = scanner.nextLine();
        scanner.close();

        Text simpleText = new PlainText(text);
        System.out.println(simpleText.display());

        Text boldText = new BoldTextDecorator(simpleText);
        System.out.println(boldText.display());

        Text italicBoldText = new ItalicTextDecorator(simpleText);
        System.out.println(italicBoldText.display());

        Text underlinedItalicBoldText = new UnderlineTextDecorator(simpleText);
        System.out.println(underlinedItalicBoldText.display());

        // То, что я мог сделать, но не стал
        System.out.println("\n\n\n");
        System.out.println("\033[0;0mTestText\033[0m");
        System.out.println("\033[0;1mTestText\033[0m");
        System.out.println("\033[0;2mTestText\033[0m");
        System.out.println("\033[0;3mTestText\033[0m");
        System.out.println("\033[0;4mTestText\033[0m");
        System.out.println("\033[0;5mTestText\033[0m");
        System.out.println("\033[0;7mTestText\033[0m");
        System.out.println("\033[0;9mTestText\033[0m");
        System.out.println("\033[0;30mTestText\033[0m");
        System.out.println("\033[0;31mTestText\033[0m");
        System.out.println("\033[0;32mTestText\033[0m");
        System.out.println("\033[0;33mTest Text\033[0m");
        System.out.println("\033[0;34mTest Text\033[0m");
        System.out.println("\033[0;35mTest Text\033[0m");
        System.out.println("\033[0;36mTest Text\033[0m");
        System.out.println("\033[0;37mTest Text\033[0m");
        System.out.println("\033[1;30mTest Text\033[0m");
        System.out.println("\033[1;31mTest Text\033[0m");
        System.out.println("\033[1;32mTest Text\033[0m");
        System.out.println("\033[1;33mTest Text\033[0m");
        System.out.println("\033[1;34mTest Text\033[0m");
        System.out.println("\033[1;35mTest Text\033[0m");
        System.out.println("\033[1;36mTest Text\033[0m");
        System.out.println("\033[1;37mTest Text\033[0m");
    }
}