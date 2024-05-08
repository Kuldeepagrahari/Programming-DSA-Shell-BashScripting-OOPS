import java.util.concurrent.Semaphore;

class SharedResource {
    private int data;
    private Semaphore readLock;
    private Semaphore writeLock;
    private int readers;

    public SharedResource() {
        this.data = 0;
        this.readLock = new Semaphore(1);
        this.writeLock = new Semaphore(1);
        this.readers = 0;
    }

    public void startReading(int readerId) throws InterruptedException {
        readLock.acquire();
        readers++;
        if (readers == 1) {
            writeLock.acquire();
        }
        readLock.release();
        System.out.println("Reader " + readerId + ": Started reading. Data = " + data);
    }

    public void endReading(int readerId) throws InterruptedException {
     
        readLock.acquire();
        readers--;
        if (readers == 0) {
            writeLock.release();
        }
        readLock.release();
        System.out.println("Reader " + readerId + ": Stopped reading.");
    }

    public void startWriting(int writerId) throws InterruptedException {
        writeLock.acquire();
        System.out.println("Writer " + writerId + ": Started writing.");
    }

    public void endWriting(int writerId) {
        writeLock.release();
        System.out.println("Writer " + writerId + ": Stopped writing.");
    }

    public int getData() {
        return data;
    }

    public void setData(int data) {
        this.data = data;
    }
}

class Reader extends Thread {
    private SharedResource resource;
    private int readerId;

    public Reader(SharedResource resource, int readerId) {
        this.resource = resource;
        this.readerId = readerId;
    }

    @Override
    public void run() {
        try {
            resource.startReading(readerId);
            // Simulating reading
            Thread.sleep(1000);
            resource.endReading(readerId);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}

class Writer extends Thread {
    private SharedResource resource;
    private int writerId;

    public Writer(SharedResource resource, int writerId) {
        this.resource = resource;
        this.writerId = writerId;
    }

    @Override
    public void run() {
        try {
            resource.startWriting(writerId);
            // Simulating writing
            Thread.sleep(1000);
            resource.endWriting(writerId);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}

public class ReaderWriterProblem {
    public static void main(String[] args) {
        SharedResource resource = new SharedResource();
        int numReaders = 3;
        int numWriters = 2;

        for (int i = 0; i < numReaders; i++) {
            Reader reader = new Reader(resource, i + 1);
            reader.start();
        }

        for (int i = 0; i < numWriters; i++) {
            Writer writer = new Writer(resource, i + 1);
            writer.start();
        }
    }
}
