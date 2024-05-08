import java.io.*;
import java.util.Scanner;

public class ten{
    public static void main(String[] args) throws IOException {
        PipedInputStream input = new PipedInputStream();
        PipedOutputStream output = new PipedOutputStream();
        input.connect(output);
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter message to send from process 1 to process 2: ");
        String message = scanner.nextLine();

        Process1 process1 = new Process1(output, message);
        Thread thread1 = new Thread(process1);
        thread1.start();

        Process2 process2 = new Process2(input);
        Thread thread2 = new Thread(process2);
        thread2.start();

        scanner.close();
    }
}

class Process1 implements Runnable {
    private OutputStream out;
    private String message;

    public Process1(OutputStream out, String message) {
        this.out = out;
        this.message = message;
    }

    public void run() {
        try {
            out.write(message.getBytes());
            out.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}

class Process2 implements Runnable {
    private InputStream in;

    public Process2(InputStream in) {
        this.in = in;
    }
    public void run() {
        try {
            ByteArrayOutputStream buffer = new ByteArrayOutputStream();
            int n;
            byte[] data = new byte[1024];
            while ((n = in.read(data, 0, data.length)) != -1) {
                buffer.write(data, 0, n);
            }
            String message = buffer.toString();
            System.out.println("Output (read by process 2): " + message);
            in.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}