import java.io.*;

public class FileAccess {
    private File f = new File("myFile.txt");
    private PrintWriter pw = new PrintWriter(new FileWriter(f, true));
    private BufferedReader br = new BufferedReader(new FileReader(f));

    public FileAccess() throws IOException {
        f.createNewFile();
    }

    public synchronized void writeLine(String line) {
        pw.println(line);
        pw.flush();
    }

    public synchronized String readLine() throws IOException {
        if (br.ready()) {
            return br.readLine();
        } else {
            return null;
        }
    }
}
