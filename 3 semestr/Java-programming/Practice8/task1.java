public class task1 {
    private int month;

    public task1(int month) throws ArrayIndexOutOfBoundsException {
        if (month <= 0 || month > 12) {
            throw new ArrayIndexOutOfBoundsException("Такого месяца не существуют");
        }
        this.month = month;
    }
}
