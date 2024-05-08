import java.util.concurrent.Semaphore;

class Resource {
    private Semaphore semaphore;

    public Resource() {
        this.semaphore = new Semaphore(1);
    }

    public void acquire() throws InterruptedException {
        semaphore.acquire();
    }

    public void release() {
        semaphore.release();
    }
}

class Process1 extends Thread {
    private Resource resourceA;
    private Resource resourceB;

    public Process1(Resource resourceA, Resource resourceB) {
        this.resourceA = resourceA;
        this.resourceB = resourceB;
    }

    @Override
    public void run() {
        try {
            resourceA.acquire();
            System.out.println("Process 1: Acquired Resource A");
            Thread.sleep(1000); // Simulate some processing time
            resourceB.acquire();
            System.out.println("Process 1: Acquired Resource B");
            resourceB.release();
            System.out.println("Process 1: Released Resource B");
            resourceA.release();
            System.out.println("Process 1: Released Resource A");
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}

class Process2 extends Thread {
    private Resource resourceA;
    private Resource resourceB;

    public Process2(Resource resourceA, Resource resourceB) {
        this.resourceA = resourceA;
        this.resourceB = resourceB;
    }

    @Override
    public void run() {
        try {
            resourceB.acquire();
            System.out.println("Process 2: Acquired Resource B");
            Thread.sleep(1000); // Simulate some processing time
            resourceA.acquire();
            System.out.println("Process 2: Acquired Resource A");
            resourceA.release();
            System.out.println("Process 2: Released Resource A");
            resourceB.release();
            System.out.println("Process 2: Released Resource B");
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}

public class DeadlockSimulation {
    public static void main(String[] args) {
        Resource resourceA = new Resource();
        Resource resourceB = new Resource();

        Process1 process1 = new Process1(resourceA, resourceB);
        Process2 process2 = new Process2(resourceA, resourceB);

        process1.start();
        process2.start();

        try {
            process1.join();
            process2.join();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}
