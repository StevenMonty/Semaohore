# Linux Kernel Semaphore and Syscall Implementations

### Goal: To implement a semaphore in the Linux kernel and write the syscall implementations to operate on the semaphore

The semaphore is a priority based implementation to give the highest priority process the requested
resource the semaphore is protecting.

In order to request the semaphore, two system calls were implemented:

```asmlinkage long sys_cs1550_down(struct cs1550_sem *sem)```

```asmlinkage long sys_cs1550_up(struct cs1550_sem *sem)```
