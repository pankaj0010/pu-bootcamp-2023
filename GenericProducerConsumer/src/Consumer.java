import java.util.Queue;

public class Consumer <MyType>{
    Queue<MyType> queue;
    public Consumer(Queue<MyType> queue) {
        this.queue = queue;
    }
    public void consume() {
        MyType item = queue.remove();
        System.out.println("Consuming item from queue: " + item);
    }
}
