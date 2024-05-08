import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.concurrent.Semaphore;

class Process {
    int id;
    int burstTime;
    int remainingTime;

    Process(int id, int burstTime) {
        this.id = id;
        this.burstTime = burstTime;
        this.remainingTime = burstTime;
    }
}

public class ContextSwitchingSimulation {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Accepting input
        System.out.print("Number of processes: ");
        int numProcesses = scanner.nextInt();

        List<Process> processes = new ArrayList<>();
        System.out.println("Enter Process ID and Burst Time for each process:");
        for (int i = 0; i < numProcesses; i++) {
            System.out.print("Process " + (i + 1) + " (PID BT): ");
            int pid = scanner.nextInt();
            int burstTime = scanner.nextInt();
            processes.add(new Process(pid, burstTime));
        }

        System.out.print("Time Quantum (TQ): ");
        int timeQuantum = scanner.nextInt();

        scanner.close();

        // Start the simulation
        simulateContextSwitching(processes, timeQuantum);
    }

    // Simulate context switching between processes
    public static void simulateContextSwitching(List<Process> processes, int timeQuantum) {
        // Semaphore for ensuring mutual exclusion
        Semaphore semaphore = new Semaphore(1);

        int currentTime = 0;
        int totalRemainingTime = getTotalRemainingTime(processes);

        while (totalRemainingTime > 0) {
            for (Process process : processes) {
                if (process.remainingTime > 0) {
                    try {
                        semaphore.acquire(); // Acquire semaphore to ensure mutual exclusion
                        int executeTime = Math.min(process.remainingTime, timeQuantum);
                        System.out.println("Process " + process.id + " executing for " + executeTime + " units");
                        process.remainingTime -= executeTime;
                        currentTime += executeTime;
                        totalRemainingTime -= executeTime;
                    } catch (InterruptedException e) {
                        e.printStackTrace();
                    } finally {
                        semaphore.release(); // Release semaphore
                    }
                }
            }
        }
    }

    // Calculate total remaining time for all processes
    public static int getTotalRemainingTime(List<Process> processes) {
        int total = 0;
        for (Process process : processes) {
            total += process.remainingTime;
        }
        return total;
    }
}
