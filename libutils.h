#include<stdio.h>
#include<stdlib.h>

int *scanArray(int len) {
  int *arr = (int *)malloc(sizeof(int) * len);
  int i;
  for(i = 0;i < len;i++) {
    scanf("%d", &arr[i]);
  }
  return arr;
}

void printArray(int *arr, int len) {
  for(int i = 0; i < len; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

typedef struct QNode {
  int val;
  struct QNode *next;
} QueueNode;

typedef struct {
  QueueNode *start;
  QueueNode *end;
} Queue;

Queue * initQ() {
  Queue *q;
  q = (Queue *)malloc(sizeof(Queue));
  q->start = NULL;
  q->end = NULL;
  return q;
}

QueueNode *createQNode(int val) {
  QueueNode *qnode;
  qnode = (QueueNode *)malloc(sizeof(QueueNode));
  qnode->val = val;
  qnode->next = NULL;
  return qnode;
}

void enqueue(Queue *q, int val) {
  QueueNode *qnode = createQNode(val);
  if (q->end == NULL) {
    q->end = qnode;
    q->start = qnode;
  } else {
    q->end->next = qnode;
    q->end = qnode;
  }
}

int dequeue(Queue *q) {
  if (q->start == NULL) {
    // printf("Queue is empty");
    return -1;
  }
  QueueNode *temp = q->start;
  q->start = q->start->next;
  if (q->start == NULL) {
    q->end = NULL;
  }
  int val = temp->val;
  free(temp);
  return val;
}

void printQ(Queue *q) {
  QueueNode *temp = q->start;
  printf("Elements in Q:\n");
  while(temp != NULL) {
    printf("%d ", temp->val);
    temp = temp->next;
  }
  printf("\n");
}

int isEmptyQ(Queue *q) {
  if (q->start == NULL || q->end == NULL) {
    return 1;
  }
  return 0;
}

void QTest1() {
  Queue *q = initQ();
  printf("--Testing enqueing--\n");
  printf("enq 1\n");
  enqueue(q, 1);
  printf("dequeue %d\n", dequeue(q));
  printf("enq 2\n");
  enqueue(q, 2);
  printf("dequeue %d\n", dequeue(q));
  printf("enq 3\n");
  enqueue(q, 3);
  printf("enq 4\n");
  enqueue(q, 4);

  printf("--Testing dequeing--\n");
  printf("dequeue %d\n", dequeue(q));
  printf("enq 5\n");
  enqueue(q, 5);
  printf("dequeue %d\n", dequeue(q));
  printf("dequeue %d\n", dequeue(q));
  printf("Testing empty dequeue\n");
  printf("dequeue %d\n", dequeue(q));
}