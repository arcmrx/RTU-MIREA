public class Main {
    public static void main(String[] args) {
        Mediator chatRoom = new ChatRoom();

        User user1 = new ConcreteUser(chatRoom, "Человечек1");
        User user2 = new ConcreteUser(chatRoom, "Человечек2");
        User user3 = new ConcreteUser(chatRoom, "Человечек3");

        chatRoom.addUser(user1);
        chatRoom.addUser(user2);
        chatRoom.addUser(user3);

        user1.send("Сообщение1");
        user2.send("Сообщение2");
        user3.send("Сообщение2");
    }
}