## Solaris Synchronization

Solaris, developed by Sun Microsystems (now owned by Oracle), is known for its robust multi-threading capabilities and its support for high-performance applications. Key features of Solaris synchronization include:

* **Adaptive Locks:** Uses spin locks and a block/sleep method.
* **Condition Variables:** Allow threads to wait for certain conditions to be true, often used with mutexes for more complex synchronization scenarios.
* **Reader-Writer Locks:** Provide shared access for reading while allowing exclusive access for longer critical sections.
* **Mutexes (Mutual Exclusion Locks):** Used to ensure that only one thread accesses a critical section at a time.
* **Semaphores:** Counting semaphores allow multiple threads to access a limited number of resources.
* **Spin Locks:** Often used in kernel-level programming for short waiting periods; threads "spin" in a loop, checking for resource availability without sleeping.
* **Turnstile:** Turnstiles are designed to help manage threads waiting on kernel synchronization objects like adaptive mutexes.

## Linux Synchronization Mechanisms

| Mechanism         | Primary Use                     | Where Used            |
|-------------------|---------------------------------|-----------------------|
| Mutexes           | Mutual exclusion                | Kernel and User space |
| Spinlocks         | Short critical sections         | Primarily Kernel      |
| Semaphores        | Limited access to resources     | Kernel and User space |
| Read-Write Locks  | Concurrent reading              | Kernel and User space |
| Condition Vars    | Waiting for conditions          | Primarily User space  |
| Futexes           | Fast mutex operations           | User space (with kernel help) |
| Barriers          | Checkpoints for threads         | Primarily User space  |
| Atomic Ops        | Low-overhead shared access      | Kernel and User space |
| ReadCopyUpdate    | Efficient concurrent reads      | Primarily Kernel      |

## POSIX Threads, or Pthreads

POSIX Threads (Pthreads) provide a set of synchronization primitives to manage concurrency in multi-threaded applications. It is OS independent and includes mutex locks, condition variables, semaphores, and read-write locks.

### Mutexes (Mutual Exclusion Locks)

Used to prevent multiple threads from simultaneously accessing a shared resource.

```c
pthread_mutex_t mutex;

pthread_mutex_lock(&mutex);

// critical section

pthread_mutex_unlock(&mutex);
```

### Condition Variables

Condition variables allow threads to wait for specific conditions to be met.

```c
pthread_cond_t cond;
pthread_mutex_t mutex;

pthread_mutex_lock(&mutex);
while (!condition) {
    pthread_cond_wait(&cond, &mutex); // Wait until condition is met
}

// Proceed when condition is met
pthread_mutex_unlock(&mutex);

// To signal the condition change:
pthread_cond_signal(&cond); // Wake one waiting thread
pthread_cond_broadcast(&cond); // Wake all waiting threads
```

### Read-Write Locks

Pthreads read-write locks in C allow multiple threads to read a shared resource simultaneously, but they ensure exclusive access when a thread wants to write to the resource.

* `pthread_rwlock_init`: Initializes a read-write lock. You can pass a pointer to `pthread_rwlockattr_t` attributes, or set it to `NULL` for default attributes.
* `pthread_rwlock_rdlock`: Acquires a read lock.
* `pthread_rwlock_tryrdlock`: Attempts to acquire a read lock without blocking.
* `pthread_rwlock_wrlock`: Acquires a write lock.
* `pthread_rwlock_trywrlock`: Attempts to acquire a write lock without blocking.
* `pthread_rwlock_unlock`: Releases a lock (read or write).
* `pthread_rwlock_destroy`: Destroys a read-write lock.

### Barriers

A barrier allows threads to wait until a predefined number of threads reach the barrier, at which point all threads are released.

## OpenMP

OpenMP provides compiler directive APIs in C++ for parallel programming.

```c++
#pragma omp critical

{
    // Critical section code
}
```

The `#pragma omp parallel` directive creates a team of threads, each executing the code inside the block.