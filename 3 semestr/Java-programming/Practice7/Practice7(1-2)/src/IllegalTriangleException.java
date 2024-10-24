// Класс для обработки исключения, связанного с некорректным треугольником
class IllegalTriangleException extends Exception {
    public IllegalTriangleException(String message) {
        super(message); // Передаем сообщение об ошибке в конструктор суперкласса
    }
}
