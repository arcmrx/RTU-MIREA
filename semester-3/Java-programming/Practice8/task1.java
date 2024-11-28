public class task1 {
    public task1(int month) throws ArrayIndexOutOfBoundsException {
        if (month <= 0 || month > 12) {
            throw new ArrayIndexOutOfBoundsException("Такого месяца не существуют");
        }
    }
}
