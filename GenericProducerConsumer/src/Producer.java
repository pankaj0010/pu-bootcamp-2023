import java.util.Queue;

public class Producer <MyType>{
    Queue<MyType> queue;
    public Producer(Queue<MyType> queue) {
        this.queue = queue;
    }
    public void produce(MyType item) {
        queue.add(item);
        System.out.println("Adding item to queue: " + item);
    }
}
