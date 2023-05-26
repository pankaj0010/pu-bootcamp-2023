public class Main {
    public static void main(String[] args) {
        Scheduler sch = new Scheduler();
        // Create tasks and schedules them.
        for (int i = 0; i < 5; i++) {
            Task writerTask = new WriterTask(i, "writerTask" + i);
            Task printerTask = new PrinterTask(i, "printerTask" + i);
            sch.scheduleTask(writerTask);
            sch.scheduleTask(printerTask);
        }
        // Runs the task based on what needs to be run next.
        for (int i = 0; i < 10; i++) {
            Task taskToRun = sch.getNextTask();
            sch.runTask(taskToRun);
        }
    }
}