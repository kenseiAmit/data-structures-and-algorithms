# include <stdio.h>
# include <stdlib.h>

struct queue {
  /*
  The structure to store data, size, front and end of a queue.
  */
  // Size tracker.
  int size;
  // Front tracker.
  int front;
  // Rear tracekr.
  int rear;
  // Pointer to create an array to store data.
  int *values;
};

void create(struct queue *element, int size) {
  /*
  The method creates a queue of size specified, the front and end are set ...
  to -1 at the begning.
  */
  element->size = size;
  element->front = -1;
  element->rear = -1;
  element->values = (int *)malloc(sizeof(int)*size);
}

void create_circular(struct queue *element, int size) {
  /*
  The method creates a circulae queue of size specified, the front and end are set ...
  to -1 at the begning.
  */
  element->size = size;
  element->front = -1;
  element->rear = -1;
  element->values = (int *)malloc(sizeof(int)*size);
}

void enqueue_circular(struct queue *element, int value) {
  /*
  The method adds an element at the end of the circular queue.
  */
  // Check if the queue is not full.
  if(element->rear == element->size-1)
    printf("Queue is full.\n");
  else
    element->values[++element->rear] = value;
}

void enqueue(struct queue *element, int value) {
  /*
  The method adds an element at the end of the queue.
  */
  // Check if the queue is not full.
  if(element->rear == element->size-1)
    printf("Queue is full.\n");
  else
    element->values[++element->rear] = value;
}

int dequeue(struct queue *element) {
  /*
  The method removes an element from the front of a queue.
  */
  // Check if the queus is empty.
  if(element->front == element->rear) {
    printf("The queue is empty.\n");
    return -1;
  }
  else
    return element->values[++element->front];
}

void display(struct queue element) {
  if(element.rear < element.front)
    printf("The queue is empty.\n");
  while(element.rear >= element.front + 1)
    printf("%d\n", element.values[element.rear--]);
}

int main(int argc, char const *argv[]) {
  struct queue element;
  create(&element, 10);
  enqueue(&element, 11);
  enqueue(&element, 12);
  enqueue(&element, 13);
  enqueue(&element, 15);

  display(element);

  printf("%d\n", dequeue(&element));
  return 0;
}
