public class PrinterTask extends Task {
    public PrinterTask(int taskId, String taskName) {
        super(taskId, taskName);
    }
    public void run() {
        System.out.println("I am a printer task: " + taskName);
    }
}
