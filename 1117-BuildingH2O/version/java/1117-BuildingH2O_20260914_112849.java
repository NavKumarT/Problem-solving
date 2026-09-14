// Last updated: 9/14/2026, 11:28:49 AM
1import java.util.concurrent.Semaphore;
2
3class H2O {
4    
5    volatile int hydrogenCount = 0;
6    Semaphore hydrogenSemaphore = new Semaphore(1);
7    Semaphore oxygenSemaphore = new Semaphore(0);
8
9    public H2O() {
10
11    }
12
13    public void hydrogen(Runnable releaseHydrogen) throws InterruptedException {
14        hydrogenSemaphore.acquire();
15        releaseHydrogen.run();
16        hydrogenCount++;
17
18        if(hydrogenCount == 2) {
19            hydrogenCount = 0;
20            oxygenSemaphore.release();
21        }
22        else {
23            hydrogenSemaphore.release();
24        }
25        // releaseHydrogen.run() outputs "H". Do not change or remove this line.
26    }
27
28    public void oxygen(Runnable releaseOxygen) throws InterruptedException {
29
30        // releaseOxygen.run() outputs "O". Do not change or remove this line.
31        oxygenSemaphore.acquire();
32        releaseOxygen.run();
33        hydrogenSemaphore.release();
34    }
35}
36
37