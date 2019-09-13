/*
This is the coding practice file for Udemy course "Mastering Data ...
Structure and Algorithms using C and C++. This file is for the Section 11 of ...
the course "Linked List".
*/

struct node {
  struct node *lchild;
  int data;
  struct node *rchild;
};

struct queue {
  int size;
  int front;
  int rear;
  struct node **elements;
};

void create(struct queue *line, int size) {
  line->size = size;
  line->front = line->rear = 0;
  line->elements = (struct node **)malloc(size*sizeof(struct node *));
}

void enqueue(struct queue *line, struct node *nodule) {
  if((line->rear + 1) % line->size == line->front)
    printf("Queue is full.\n");
  else {
    line->rear = (line->rear + 1) % line->size;
    line->elements[line->rear] = nodule;
  }
}

struct node *dequeue(struct queue *line) {
  struct node *nodule = NULL;

  if(line->front == line->rear)
    printf("Queue is empty.\n");
  else {
    line->front = (line->front + 1) % line->size;
    nodule = line->elements[line->front];
  }
  return nodule;
}

int is_empty(struct queue line) {
  return line.front == line.rear;
}
