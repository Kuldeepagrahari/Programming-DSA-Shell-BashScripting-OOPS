import java.util.concurrent.Semaphore;
import java.util.*;
class ResourceManager {
    private Semaphore semaphore;

    public ResourceManager(int numResources) {
        this.semaphore = new Semaphore(numResources, true);
    }

    public void acquireResource(int processId) throws InterruptedException {
        semaphore.acquire();
        System.out.println("Process " + processId + ": Acquired resource");
    }

    public void releaseResource(int processId) {
        semaphore.release();
        System.out.println("Process " + processId + ": Released resource");
    }
}

class Process extends Thread {
    private int id;
    private ResourceManager resourceManager;

    public Process(int id, ResourceManager resourceManager) {
        this.id = id;
        this.resourceManager = resourceManager;
    }

    public void run() {
        try {
            resourceManager.acquireResource(id);
            resourceManager.acquireResource(id);
            Thread.sleep(1000);
            resourceManager.releaseResource(id);
            resourceManager.releaseResource(id);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}

public class resourceAlocSemaphore {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int numProcesses = scanner.nextInt();
        int numResources = scanner.nextInt();
        ResourceManager resourceManager = new ResourceManager(numResources);

        Process[] processes = new Process[numProcesses];
        for (int i = 0; i < numProcesses; i++) {
            processes[i] = new Process(i + 1, resourceManager);
            processes[i].start();
        }
    }
}
