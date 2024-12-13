public class ConcreteUser extends User {

    public ConcreteUser(Mediator mediator, String name) {
        super(mediator, name);
    }

    public void send(String message) {
        System.out.println(this.name + " отправил(-а): " + message);
        mediator.sendMessage(message, this);
    }

    public void receive(String message) {
        System.out.println(this.name + " получил(-а): " + message);
    }
}