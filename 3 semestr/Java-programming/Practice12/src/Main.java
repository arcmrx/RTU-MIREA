public class Main {
    public static void main(String[] args) {

        try {
            // Полный заказ
            Order Order1 = new Order.OrderBuilder()
                    .setMainDish("Стейк")
                    .setSideDish("Овощи на гриле")
                    .setDrink("Красное вино")
                    .setDessert("Мороженое")
                    .build();
            System.out.println(Order1);

        } catch (IllegalStateException e) {
            System.out.println(e.getMessage());
        }

        try {
            // Только основное блюдо
            Order Order2 = new Order.OrderBuilder()
                    .setMainDish("Рулька")
                    .build();
            System.out.println(Order2);

        } catch (IllegalStateException e) {
            System.out.println(e.getMessage());
        }

        try {
            // Пустой заказ
            Order Order3 = new Order.OrderBuilder()
                    .build();
            System.out.println(Order3);

        } catch (IllegalStateException e) {
            System.out.println(e.getMessage());
        }

        try {
            // Заказ без десерта
            Order Order4 = new Order.OrderBuilder()
                    .setMainDish("Куриные ножки")
                    .setSideDish("Паста")
                    .setDrink("Лимонад")
                    .build();
            System.out.println(Order4);

        } catch (IllegalStateException e) {
            System.out.println(e.getMessage());
        }
    }
}
