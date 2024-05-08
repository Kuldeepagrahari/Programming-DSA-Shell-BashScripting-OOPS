import java.util.*;

class Process {
    int pid;
    int burstTime;
    int remainingTime;

    Process(int pid, int burstTime) {
        this.pid = pid;
        this.burstTime = burstTime;
        this.remainingTime = burstTime;
    }
}

public class contextSwitching {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the number of processes: ");
        int numProcesses = scanner.nextInt();
        Process[] processes = new Process[numProcesses];

        for (int i = 0; i < numProcesses; i++) {
            System.out.print("Enter Process ID and Burst Time for process " + (i + 1) + ": ");
            int pid = scanner.nextInt();
            int burstTime = scanner.nextInt();
            processes[i] = new Process(pid, burstTime);
        }

        System.out.print("Enter the time quantum (TQ): ");
        int timeQuantum = scanner.nextInt();

        simulateContextSwitching(processes, timeQuantum);
    }

    public static void simulateContextSwitching(Process[] processes, int timeQuantum) {
        Queue<Process> readyQueue = new LinkedList<>();
        int currentTime = 0;

        for (Process process : processes) {
            readyQueue.add(process);
        }

        System.out.println("Process Execution Order:");
        while (!readyQueue.isEmpty()) {
            Process currentProcess = readyQueue.poll();
            int executionTime = Math.min(currentProcess.remainingTime, timeQuantum);
            System.out.println("Executing Process " + currentProcess.pid + " for " + executionTime);
            currentProcess.remainingTime -= executionTime;
            currentTime += executionTime;
            if (currentProcess.remainingTime > 0) {
                readyQueue.add(currentProcess);
            }
        }
    }
}
