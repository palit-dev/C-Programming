# Inter Process Communication

Interprocess communication is the mechanism provided by the operating system that allows cooperative processes to communicate with each other. 

## Requirement of IPC

* Computational Speedup
* Modularity

## Approaches for Inter Process Communication

* **Pipes:** Pipes are a half-duplex (unidirectional) mechanism in which one process is used to write to the Pipe and another Process is used to retrive from the Pipe. A unique pipe exists between two Processes.
* **Shared Memory:** A common Shared Memory is created which can be accessed by multiple processes. The Processes can then communicate by reading or writing to the Shared memory.
* **Message Passing:** Processes can send messages to each other by implementing a message queue in the Kernel e.g., DBUS.
* **Direct Communication:** A direct link is established between two Processes using Process identifiers.
* **Indirect Communication:** Processes share a common mailbox. While one process puts in the message, the process fetches it.

## Semahpore

Semaphores are a synchronization mechanism used to enforce mutual exclusion, avoid race conditions and implement synchronization between processes.

Semaphores provide two operations: wait (P) and signal (V). The wait operation decrements the value of the semaphore, and the signal operation increments the value of the semaphore. When the value of the semaphore is zero, any process that performs a wait operation will be blocked until another process performs a signal operation.

Semaphores are used to implement critical sections, which are regions of code that must be executed by only one process at a time. By using semaphores, processes can coordinate access to shared resources, such as shared memory or I/O devices.

### Types of Semaphore

* **Binary Semaphore:**  This is also known as a mutex lock. It can have only two values – 0 and 1. Its value is initialized to 1. It is used to implement the solution of critical section problems with multiple processes.

* **Counting Semaphore:** Its value can range over an unrestricted domain. It is used to control access to a resource that has multiple instances.

### Structure of Semaphore

```c
P(Semaphore s)
{
    // Wait if Semaphore is 0
    while (s<=0);

    // If semaphore is non-zero, decrement the semaphore value and 
    // continue to execute the critical section
    s--;
}

V(Semaphore s)
{
    // Increment the value of Semaphore such that waiting Processes
    // can execute the Critical Section
    s++;
}


P(s);
// Critical Section
V(s);
```

`P` operation is also known as wait, sleep or down operation while `Q` is called the signal, wake or uip operation. Both the operations need to be atomic such that there is no racing condition between threads during execution of the function blocks i.e., the Semaphore variable must not have pre-emption.

### Disadvantages of Semaphore

* It can lead to performace degradation due to overhead associated with wait and signal operations.
* It can lead to priority inversion.
* It is complex to implement.

### Difference between Binary Semaphore and Mutex Lock

In Binary Semaphore, the semaphore value can be incremented by any thread. Mutex Locks has a sense of Ownership and hence, Mutex locks can be released only by the Process that acquired it. Therefore, Mutex Locks are prone to Deadlocks.

## Reader Write Problem

Reader-Writer Problem refers to situation where there are multiple Processes reading or writing to the same memory.
Here, multiple readers are allowed to access the Critical Section simultaneously but only one writer can be present in a given instance of time. Further, Reading while Writing or vice-versa is not allowed.

The Solution utilizes two Binary Semaphores. One Semaphore is used to control the write access of the Data i.e., A and another Semaphore is used to synchronize the Readers i.e., B.

* **Case I: R-W ->** When the first reader arrives, it downs the A Semaphore within the B Semaphore. The A Semaphore prevents any writer to enter the Critical Section while Reader is within the critical Section.
* **Case I: W-R ->** When the first writer arrives, it downs the A semaphore before entering the Critical Section. Hence, if a reader arrives and it tries to down the A semaphore, the Reader waits.
* **Case I: W-W ->** When the first writer arrives, it downs the A Semaphore hence preventing any other Writer to enter.
* **Case I: R-R ->** The reader only downs the A semaphore and hence it does not stops another Reader to access the Critical Section.

```C
int readerCount = 0;
Semaphore mutex = 1;
Semaphore critical = 1;

void Reader(){

    while(1)
    {
        down(mutex);
        readerCount++;
        if (readerCount == 1)
            down(critical);
        up(mutex);
        // Critical Section

        down(mutex);
        readerCount--;
        if (readerCount == 0)
            up(critical);
        up(mutex);

    }
}

void Writer(){
    
    while(1)
    {
        down(critical);
        // Critical Section
        up(critcial);
    }
}
```