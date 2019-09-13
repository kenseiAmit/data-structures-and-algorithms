# include <iostream>

class queue {
  /*
  The class to store data, size, front and end of a queue.
  It also contains methods including insert, remove and display.
  */
private:
  // Size tracker.
  int size;
  // Front tracker.
  int front;
  // Rear tracekr.
  int rear;
  // Pointer to create an array to store data.
  int *values;
public:
  queue() {front = rear = -1; size = 10; values = new int[size];}
  queue(int size) {front = rear = -1; this->size = size; values = new int[size];}
  void enqueue(int value);
  int dequeue ();
  void display();
};

void queue::enqueue(int value) {
  /*
  The method adds an element at the end of the queue.
  */
  // Check if the queue is not full.
  if(rear == size-1)
    printf("Queue is full.\n");
  else
    values[++rear] = value;
}

int queue::dequeue() {
  /*
  The method removes an element from the front of a queue.
  */
  // Check if the queus is empty.
  if(front == rear) {
    printf("The queue is empty.\n");
    return -1;
  }
  else
    return values[++front];
}

void queue::display() {
  if(rear < front)
    printf("The queue is empty.\n");
  else {
    int navigator = rear;
    while(navigator >= front + 1)
    printf("%d\n", values[navigator--]);
  }
}

int main(int argc, char const *argv[]) {
  struct queue element(10);
  element.enqueue(11);
  element.enqueue(12);
  element.enqueue(13);
  element.enqueue(15);

  element.display();

  printf("%d\n", element.dequeue());
  return 0;
}
