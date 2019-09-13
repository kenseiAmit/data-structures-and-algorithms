

# include <stdio.h>
# include <stdlib.h>

struct queue {
  int size;
  int front;
  int rear;
  int *elements;
};

void create(struct queue *line, int size) {
  line->size = size;
  line->front = line->rear = 0;
  line->elements = (int *)malloc(sizeof(int));
}

void enqueue(struct queue *list, int value) {
  if((list->rear + 1) % list->size == list->front)
    printf("Queue is full.\n");
  else {
    list->rear = (list->rear + 1) % list->size;
    list->elements[list->rear] = value;
  }
}

int dequeue(struct queue *list) {
  if(list->front == list->rear) {
    printf("Queue is empty\n");
    return -1;
  }
  else {
    list->front = (list->front + 1) % list->size;
    int value = list->elements[list->front];
    return value;
  }
}

void display(struct queue list) {
  int value = list.front + 1;
  do {
    printf("%d\n", list.elements[value]);
    value = (value+1)%list.size;
  }while(value != (list.rear+1)%list.size);
  printf("\n");
}

int main() {
  struct queue line;
  create(&line, 10);

  enqueue(&line, 10);
  enqueue(&line, 20);
  enqueue(&line, 30);
  enqueue(&line, 40);
  enqueue(&line, 50);
  enqueue(&line, 60);

  display(line);
  printf("The last elemetn is %d\n", dequeue(&line));

  display(line);

  return 0;
}
