import java.util.concurrent.Semaphore;

class Resource {
    private Semaphore semaphore;

    public Resource(int maxResources) {
        this.semaphore = new Semaphore(maxResources, true);
    }

    public void acquire(int processId) throws InterruptedException {
        semaphore.acquire();
        System.out.println("Process " + processId + ": Acquired resource");
    }

    public void release(int processId) {
        semaphore.release();
        System.out.println("Process " + processId + ": Released resource");
    }
}

class Process extends Thread {
    private Resource resource;
    private int processId;

    public Process(Resource resource, int processId) {
        this.resource = resource;
        this.processId = processId;
    }

    @Override
    public void run() {
        try {
            resource.acquire(processId);
            Thread.sleep(1000); // Simulate some processing time
            resource.release(processId);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}

public class SemaphoreResourceAllocation {
    public static void main(String[] args) {
        int numProcesses = 3;
        int numResources = 2;
        int maxResourcesPerProcess = 1;

        Resource resource = new Resource(numResources);

        for (int i = 1; i <= numProcesses; i++) {
            Thread process = new Process(resource, i);
            process.start();
        }
    }
}
