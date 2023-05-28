import java.util.*;

public class Main {
    private static void simulateMessages() {
        Queue<Message> queue = new LinkedList<>();
        Producer<Message> producer = new Producer<>(queue);
        Consumer<Message> consumer = new Consumer<>(queue);
        for (int i = 0; i < 10; i++) {
            Message msg = new Message("Title" + i, "Body" + i);
            producer.produce(msg);
        }
        for (int i = 0; i < 5; i++) {
            consumer.consume();
        }
    }
    private static void simulateStrings() {
        Queue<String> queue = new LinkedList<>();
        Producer<String> producer = new Producer<>(queue);
        Consumer<String> consumer = new Consumer<>(queue);
        for (int i = 0; i < 10; i++) {
            String str = "String msg: " + i;
            producer.produce(str);
        }
        for (int i = 0; i < 5; i++) {
            consumer.consume();
        }
    }
    public static void main(String[] args) {
        simulateStrings();
        simulateMessages();
    }
}