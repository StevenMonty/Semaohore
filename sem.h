
// The struct to represent a Semaphore used to reduce race conditions using
// spinlocks
typedef struct cs1550_sem {
  int value;  //TODO init value of 0 or 1?
  struct Node* head;  // PriorityQueue of processes waiting on 'this' semaphore
} cs1550_sem;

// The Priority Queue Node struct
typedef struct Node {
  struct task_struct* proc;
  int priority;
  struct Node* next;
} Node;
