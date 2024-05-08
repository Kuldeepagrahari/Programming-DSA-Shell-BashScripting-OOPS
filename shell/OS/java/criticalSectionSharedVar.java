import java.util.*;
import java.util.concurrent.Semaphore; 

class IncrementThread extends Thread {
    static int sharedVariable = 0;
    static Semaphore semCon = new Semaphore(1); 
    int id;

    public IncrementThread(int id) {
        this.id = id;
    }

    public void run() {
        for (int i = 0; i < 5; i++) {
            try { 
                semCon.acquire(); 
                int temp = sharedVariable;
                System.out.println("Thread " + id + ": Current value of shared variable: " + temp);
                temp++;
                sharedVariable = temp;
                System.out.println("Thread " + id + ": Incremented value to " + sharedVariable);
                semCon.release(); 
            } 
            catch (InterruptedException e) { 
                System.out.println("InterruptedException caught"); 
            }  
            
        }
    }
}
class IncrementThreadAsync extends Thread {
    int sharedVariable = 0;
    int id;

    public IncrementThreadAsync(int id) {
        this.id = id;
    }

    public void run() {
        for (int i = 0; i < 5; i++) {
            int temp = sharedVariable;
            System.out.println("Thread Async " + id + ": Current value of shared variable: " + temp);
            temp++;
            sharedVariable = temp;
            System.out.println("Thread Async " + id + ": Incremented value to " + sharedVariable);
        }
    }
}


public class criticalSectionSharedVar {
    static int sharedVariable = 0;
    
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int numThreads = scanner.nextInt();
        IncrementThreadAsync[] threadsAsync = new IncrementThreadAsync[numThreads];
        IncrementThread[] threads = new IncrementThread[numThreads];
        for (int i = 0; i < numThreads; i++) {
            threads[i] = new IncrementThread(i + 1);
            threadsAsync[i] = new IncrementThreadAsync(i + 1);
        }

        for (IncrementThread thread : threads) {
            thread.start();
        }
        for (IncrementThreadAsync thread : threadsAsync) {
            thread.start();
        }
    }
}
