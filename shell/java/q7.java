import java.util.concurrent.Semaphore;

class Resource {
    public Semaphore semaphoreA;
    public Semaphore semaphoreB;

    public Resource() {
        this.semaphoreA = new Semaphore(1); // Semaphore for resource A
        this.semaphoreB = new Semaphore(1); // Semaphore for resource B
    }

    public void acquireResourceA(int processId) throws InterruptedException {
        semaphoreA.acquire();
        System.out.println("Process " + processId + ": Acquired Resource A");
    }

    public void releaseResourceA(int processId) {
        semaphoreA.release();
        System.out.println("Process " + processId + ": Released Resource A");
    }

    public void acquireResourceB(int processId) throws InterruptedException {
        semaphoreB.acquire();
        System.out.println("Process " + processId + ": Acquired Resource B");
    }

    public void releaseResourceB(int processId) {
        semaphoreB.release();
        System.out.println("Process " + processId + ": Released Resource B");
    }
}

class Process1 extends Thread {
    private Resource resource;

    public Process1(Resource resource) {
        this.resource = resource;
    }

    @Override
    public void run() {
        try {
            resource.acquireResourceA(1);
            Thread.sleep(1000); // Simulate some processing time
            resource.acquireResourceB(1);
            resource.releaseResourceA(1);
            resource.releaseResourceB(1);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}

class Process2 extends Thread {
    private Resource resource;

    public Process2(Resource resource) {
        this.resource = resource;
    }

    @Override
    public void run() {
        try {
            resource.acquireResourceB(2);
            Thread.sleep(1000); // Simulate some processing time
            resource.acquireResourceA(1);
            resource.releaseResourceB(2);
            resource.releaseResourceA(1);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}

public class DeadlockDetectionAndRecovery {
    public static void main(String[] args) {
        Resource resource = new Resource();

        Process1 process1 = new Process1(resource);
        Process2 process2 = new Process2(resource);

        process1.start();
        process2.start();

        // Wait for both processes to complete
        try {
            process1.join();
            process2.join();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        // Check for deadlock
        // This condition `if (resource.semaphoreA.availablePermits() == 0 &&
        // resource.semaphoreB.availablePermits() == 0)` is checking if both `semaphoreA` and
        // `semaphoreB` have no available permits left. In the context of this code, it is used to
        // detect a deadlock situation.
        if (resource.semaphoreA.availablePermits() == 0 && resource.semaphoreB.availablePermits() == 0) {
            System.out.println("Deadlock detected!");
            // Terminate Process 1 to resolve deadlock
            process1.interrupt();
            System.out.println("Recovery option: Terminate Process 1");
        } else {
            System.out.println("No deadlock detected");
        }
    }
}
