import java.util.LinkedList;
import java.util.Queue;

/**
 * This is a simple scheduler which schedules
 * tasks to a FIFO queue. As the task comes,
 * it gets scheduled to the queue and is the first
 * one to be picked up.
 */
public class Scheduler {
    Queue<Task> queue;
    public Scheduler() {
        queue = new LinkedList<Task>();
    }

    /**
     * Adds the task to the queue. If x tasks
     * already exist in the queue, the Task
     * 'task' gets added to (x+1)th position.
     */
    void scheduleTask(Task task) {
        queue.add(task);
    }

    /**
     * Fetches the Task from the beginning of the
     * queue and removes it. Returns the same.
     */
    Task getNextTask() {
        return queue.remove();
    }
    void runTask(Task task) {
        task.run();
    }
    void cancelTask(Task task) {
        System.out.println("Nothing to do after cancel");
    }
}
