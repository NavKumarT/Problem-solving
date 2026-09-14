// Last updated: 9/14/2026, 11:30:53 AM
1import java.util.concurrent.Semaphore;
2
3class H2O {
4    
5    private final Semaphore hSem = new Semaphore(2); // Allow 2 Hydrogen threads concurrently
6    private final Semaphore oSem = new Semaphore(0); // Oxygen waits for 2 Hydrogen signals
7
8    public H2O() {
9    }
10
11    public void hydrogen(Runnable releaseHydrogen) throws InterruptedException {
12        hSem.acquire();           // Take 1 of 2 Hydrogen permits
13        releaseHydrogen.run();
14        oSem.release();           // Signal Oxygen (adds 1 permit to oSem)
15    }
16
17    public void oxygen(Runnable releaseOxygen) throws InterruptedException {
18        oSem.acquire(2);          // Wait until 2 Hydrogen threads have completed
19        releaseOxygen.run();
20        hSem.release(2);          // Replenish 2 Hydrogen permits for the next cycle
21    }
22}