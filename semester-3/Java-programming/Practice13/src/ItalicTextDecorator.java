public class ItalicTextDecorator extends TextDecorator {

    public ItalicTextDecorator(Text decoratedText) {
        super(decoratedText);
    }

    @Override
    public String display() {
        return "\033[3m" + super.display() + "\033[0m";
    }
}