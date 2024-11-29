public class UnderlineTextDecorator extends TextDecorator {

    public UnderlineTextDecorator(Text decoratedText) {
        super(decoratedText);
    }

    @Override
    public String display() {
        return "\033[0;4m" + super.display() + "\033[0m";
    }
}