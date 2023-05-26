import java.io.File;
import java.io.FileWriter;
import java.io.IOException;

public class WriterTask extends Task {
    public WriterTask(int taskId, String taskName) {
        super(taskId, taskName);
    }
    public void run() {
        File file = new File("append.txt");
        FileWriter fr;
        try {
            fr = new FileWriter(file, true);
            fr.write("Adding: " + taskName + "\n");
            fr.close();
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }
}
