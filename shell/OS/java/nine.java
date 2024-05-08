import java.util.Scanner;

class MyThread extends Thread {
    public MyThread(String name, int priority) {
        super(name);
        Thread.currentThread().setPriority(priority);
    }

    public void run() {
        try{
            Thread.sleep(1000);
            System.out.println(Thread.currentThread().getName() + " running...");
        }
        catch (InterruptedException e){
            System.out.println("EXCEPTION");
        }
    }
}

public class nine {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.println("priority:");
        int priority1 = scanner.nextInt();
        System.out.println("priority:");
        int priority2 = scanner.nextInt();
        System.out.println("priority:");
        int priority3 = scanner.nextInt();

        MyThread thread1 = new MyThread("Thread 1", priority1);
        MyThread thread2 = new MyThread("Thread 2", priority2);
        MyThread thread3 = new MyThread("Thread 3", priority3);

        thread1.start();
        thread2.start();
        thread3.start();

        scanner.close();
    }
}