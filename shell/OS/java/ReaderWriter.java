import java.util.concurrent.Semaphore;

public class ReaderWriter {

    private final Semaphore canRead; 
    private final Semaphore canWrite; 
    private int readingReaders = 0;

    private int data = 0;

    public ReaderWriter(int readerCount) {
        this.canRead = new Semaphore(0);
        this.canWrite = new Semaphore(2);
    }

    public void read() throws InterruptedException {
        canRead.acquire();
        readingReaders++;
        System.out.println("Reader reading: ");
        readingReaders--;
        canRead.release();
    }

    public void write() throws InterruptedException {
        canWrite.acquire();
        System.out.println("Writer writing: ");
        canRead.release();
        canWrite.release();
    }

    public static void main(String[] args) throws InterruptedException {
        int numReaders = 3;
        int numWriters = 2;

        ReaderWriter rw = new ReaderWriter(numReaders);

        for (int i = 0; i < numReaders; i++) {
            new Thread(() -> {
                    try {
                        rw.write();
                        rw.read();
                        Thread.sleep(2000);
                    } catch (InterruptedException e) {
                        e.printStackTrace();
                    }
            }).start();
        }
    }
}
