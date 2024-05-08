class Counter {
    private int count;

    public Counter() {
        this.count = 0;
    }

    // Without synchronization
    public void incrementWithoutSynchronization() {
        count++;
        System.out.println(Thread.currentThread().getName() + ": Incremented value to " + count);
    }

    // With synchronization
    public synchronized void incrementWithSynchronization() {
        count++;
        System.out.println(Thread.currentThread().getName() + ": Incremented value to " + count);
    }
}

class IncrementThread extends Thread {
    private Counter counter;
    private boolean withSynchronization;

    public IncrementThread(Counter counter, boolean withSynchronization) {
        this.counter = counter;
        this.withSynchronization = withSynchronization;
    }

    @Override
    public void run() {
        if (withSynchronization) {
            counter.incrementWithSynchronization();
        } else {
            counter.incrementWithoutSynchronization();
        }
    }
}

public class CriticalSectionProblem {
    public static void main(String[] args) {
        Counter counter = new Counter();
        int numThreads = 2;

        // Without synchronization
        System.out.println("Output (without synchronization):");
        for (int i = 0; i < numThreads; i++) {
            IncrementThread thread = new IncrementThread(counter, false);
            thread.start();
        }

        // With synchronization
        System.out.println("\nOutput (with synchronization):");
        for (int i = 0; i < numThreads; i++) {
            IncrementThread thread = new IncrementThread(counter, true);
            thread.start();
        }
    }
}
