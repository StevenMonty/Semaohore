# Linux Kernel Semaphore and Syscall Implementations

### Goal: To implement a semaphore in the Linux kernel and write the syscall implementations to operate on the semaphore

The semaphore is a priority based implementation to give the highest priority process the requested
resource the semaphore is protecting.

In order to request the semaphore, two system calls were implemented:

```asmlinkage long sys_cs1550_down(struct cs1550_sem *sem)```

```asmlinkage long sys_cs1550_up(struct cs1550_sem *sem)```

In order to manipulate the counter of the semaphore, the operation must be atomic and free from race condition so it
is done inside of a spinlock ```sem_lock```. 

To add a new syscall to the Linux kernel, there are three main files that need to be modified: 
  1. linux-2.6.23.1/kernel/sys.c (This file contains the actual implementation of the system calls.)

  2. linux-2.6.23.1/arch/i386/kernel/syscall_table.S (This file declares the number that corresponds to the syscalls 
)
3. linux-2.6.23.1/include/asm/unistd.h (This file exposes the syscall number to C programs which wish to use it.)

Changes to sys.c begin at line 2361 with the priroty queue helper functions followed by the actual syscall implementations. 
