public class Message {
    String title;
    String body;
    public Message(String title, String body) {
        this.title = title;
        this.body = body;
    }

    public String toString() {
        return this.title + "\n" + this.body;
    }
}
