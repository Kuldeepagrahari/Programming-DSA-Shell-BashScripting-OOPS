import java.util.LinkedList;
import java.util.Queue;
import java.util.concurrent.Semaphore;

class BoundedBuffer {
    private Queue<Integer> buffer;
    private int capacity;
    private Semaphore mutex; // For mutual exclusion
    private Semaphore empty; // Number of empty slots in the buffer
    private Semaphore full; // Number of filled slots in the buffer

    public BoundedBuffer(int capacity) {
        this.buffer = new LinkedList<>();
        this.capacity = capacity;
        this.mutex = new Semaphore(1);
        this.empty = new Semaphore(capacity);
        this.full = new Semaphore(0);
    }

    public void produce(int item) throws InterruptedException {
        empty.acquire(); // Wait for an empty slot
        mutex.acquire(); // Enter critical section
        buffer.add(item);
        System.out.println("Produced: " + item);
        mutex.release(); // Exit critical section
        full.release(); // Signal that buffer is no longer empty
    }

    public int consume() throws InterruptedException {
        full.acquire(); // Wait for a filled slot
        mutex.acquire(); // Enter critical section
        int item = buffer.poll();
        System.out.println("Consumed: " + item);
        mutex.release(); // Exit critical section
        empty.release(); // Signal that buffer is no longer full
        return item;
    }
}

class Producer extends Thread {
    private BoundedBuffer buffer;
    private int itemsToProduce;

    public Producer(BoundedBuffer buffer, int itemsToProduce) {
        this.buffer = buffer;
        this.itemsToProduce = itemsToProduce;
    }

    @Override
    public void run() {
        for (int i = 1; i <= itemsToProduce; i++) {
            try {
                buffer.produce(i);
                Thread.sleep(1000); // Production delay
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}

class Consumer extends Thread {
    private BoundedBuffer buffer;

    public Consumer(BoundedBuffer buffer) {
        this.buffer = buffer;
    }

    @Override
    public void run() {
        while (true) {
            try {
                buffer.consume();
                Thread.sleep(1000); // Consumption delay
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}

public class ProducerConsumerWithBufferOverflowUnderflow {
    public static void main(String[] args) {
        int bufferCapacity = 3;
        int itemsToProduce = 5;

        BoundedBuffer buffer = new BoundedBuffer(bufferCapacity);
        Producer producer = new Producer(buffer, itemsToProduce);
        Consumer consumer = new Consumer(buffer);

        producer.start();
        consumer.start();
    }
}
