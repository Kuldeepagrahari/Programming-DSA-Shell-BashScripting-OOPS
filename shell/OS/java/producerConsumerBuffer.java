import java.util.concurrent.Semaphore;

class Buffer {
    private int[] buffer;
    private int size;
    private int in, out;
    private Semaphore mutex;
    private Semaphore empty;
    private Semaphore full;

    public Buffer(int size) {
        this.size = size;
        this.buffer = new int[size];
        this.in = 0;
        this.out = 0;
        this.mutex = new Semaphore(1);
        this.empty = new Semaphore(size);
        this.full = new Semaphore(0);
    }

    public void produce(int item) throws InterruptedException {
        empty.acquire(); // Wait if buffer is full
        mutex.acquire(); // Obtain lock to the buffer

        // Add item to buffer
        buffer[in] = item;
        in = (in + 1) % size;

        System.out.println("Produced: " + item);

        mutex.release(); // Release lock
        full.release(); // Increment count of full slots
    }

    public int consume() throws InterruptedException {
        full.acquire(); // Wait if buffer is empty
        mutex.acquire(); // Obtain lock to the buffer

        // Remove item from buffer
        int item = buffer[out];
        out = (out + 1) % size;

        System.out.println("Consumed: " + item);

        mutex.release(); // Release lock
        empty.release(); // Increment count of empty slots

        return item;
    }
}

class Producer extends Thread {
    private Buffer buffer;

    public Producer(Buffer buffer) {
        this.buffer = buffer;
    }

    public void run() {
        try {
            for (int i = 0; i < 10; i++) {
                buffer.produce(i);
                Thread.sleep((int) (Math.random() * 100));
            }
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}

class Consumer extends Thread {
    private Buffer buffer;

    public Consumer(Buffer buffer) {
        this.buffer = buffer;
    }

    public void run() {
        try {
            for (int i = 0; i < 10; i++) {
                int item = buffer.consume();
                Thread.sleep((int) (Math.random() * 100));
            }
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}

public class producerConsumerBuffer {
    public static void main(String[] args) {
        Buffer buffer = new Buffer(5);
        Producer producer = new Producer(buffer);
        Consumer consumer = new Consumer(buffer);
        producer.start();
        consumer.start();
    }
}
