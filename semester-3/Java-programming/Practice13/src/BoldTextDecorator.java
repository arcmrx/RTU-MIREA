public class BoldTextDecorator extends TextDecorator {

    public BoldTextDecorator(Text decoratedText) {
        super(decoratedText);
    }

    @Override
    public String display() {
        return "\033[0;1m" + super.display() + "\033[0m";
    }
}