/**
 * Task is defined as an abstract class since it has
 * variables which need to be initialised from outside.
 * These variables are defined as protected to allow
 * access to inheriting classes but not to all classes
 * (public), and private members would restrict access
 * to only the abstract class. This uses the concept
 * of encapsulation (data hiding).
 *
 * The run method is abstract since each class can have
 * its own run method to execute the task. The Task class
 * should only be used as an abstraction to the Scheduler
 * and hence the run method needs to be defined.
 *
 * Play around with changing the access specifier for
 * member variables and see what happens.
 */

public abstract class Task {
    protected int taskId;
    protected String taskName;

    /**
     * Note that even though Task class has a constructor,
     * it cannot be initialised (i.e, you cannot do:
     * Task t = new Task(id, name) - try it yourself).
     * The purpose of this constructor is to simplify the
     * work of the inheriting classes so that they do not
     * have to keep defining their own constructors.
     */
    public Task(int taskId, String taskName) {
        this.taskId = taskId;
        this.taskName = taskName;
    }
    abstract void run();
}
