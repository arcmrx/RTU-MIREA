public class Order {
    private final String mainDish;
    private final String sideDish;
    private final String drink;
    private final String dessert;

    // Приватный конструктор, чтобы только OrderBuilder мог создавать объекты
    private Order(OrderBuilder builder) {
        this.mainDish = builder.mainDish;
        this.sideDish = builder.sideDish;
        this.drink = builder.drink;
        this.dessert = builder.dessert;
    }

    @Override
    public String toString() {
        return "|Заказ|\n" +
                "Основное блюдо: " + mainDish + '\n' +
                "Гарнир: " + sideDish + '\n' +
                "Напиток: " + drink + '\n' +
                "Десерт: " + dessert + '\n';
    }

    // Вложенный статический класс Builder
    public static class OrderBuilder {
        private String mainDish = "Не выбрано";
        private String sideDish = "Не выбрано";
        private String drink = "Не выбрано";
        private String dessert = "Не выбрано";

        // Методы для задания компонентов заказа
        public OrderBuilder setMainDish(String mainDish) {
            this.mainDish = mainDish;
            return this;
        }

        public OrderBuilder setSideDish(String sideDish) {
            this.sideDish = sideDish;
            return this;
        }

        public OrderBuilder setDrink(String drink) {
            this.drink = drink;
            return this;
        }

        public OrderBuilder setDessert(String dessert) {
            this.dessert = dessert;
            return this;
        }

        // Метод для сборки заказа
        public Order build() {
            if ("Не выбрано".equals(mainDish) &&
                    "Не выбрано".equals(sideDish) &&
                    "Не выбрано".equals(drink) &&
                    "Не выбрано".equals(dessert)) {
                throw new IllegalStateException("Нельзя создать пустой заказ! Укажите хотя бы один элемент.\n");
            }
            return new Order(this);
        }
    }
}
