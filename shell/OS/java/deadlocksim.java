import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

class Resource {
    private String name;
    private Lock lock = new ReentrantLock();

    public Resource(String name) {
        this.name = name;
    }

    public void acquire() {
        lock.lock();
        System.out.println("Process acquired " + name);
    }

    public void release() {
        lock.unlock();
        System.out.println("Process released " + name);
    }
}

class Process implements Runnable {
    private Resource resource1;
    private Resource resource2;

    public Process(Resource resource1, Resource resource2) {
        this.resource1 = resource1;
        this.resource2 = resource2;
    }

    @Override
    public void run() {
        // Acquire resource 1
        resource1.acquire();
        System.out.println("Process acquired " + resource1);

        // Simulate some processing time
        try {
            Thread.sleep(100);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        // Acquire resource 2
        resource2.acquire();
        System.out.println("Process acquired " + resource2);

        // Release resources
        resource2.release();
        resource1.release();
    }
}

public class deadlocksim {
    public static void main(String[] args) {
        // Create resources
        Resource resourceA = new Resource("Resource A");
        Resource resourceB = new Resource("Resource B");

        // Create processes
        Process process1 = new Process(resourceA, resourceB);
        Process process2 = new Process(resourceB, resourceA);

        // Start threads
        Thread thread1 = new Thread(process1);
        Thread thread2 = new Thread(process2);
        thread1.start();
        thread2.start();
    }
}
