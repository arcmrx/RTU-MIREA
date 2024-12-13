import java.util.ArrayList;
import java.util.List;

public class ChatRoom implements Mediator {
    private List<User> users;

    public ChatRoom() {
        this.users = new ArrayList<>();
    }

    public void sendMessage(String message, User user) {
        for (User u : users) {
            if (u != user) {
                u.receive(message);
            }
        }
    }

    public void addUser(User user) {
        this.users.add(user);
    }
}