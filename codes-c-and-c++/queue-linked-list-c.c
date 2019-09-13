/*
This is the coding practice file for Udemy course "Mastering Data ...
Structure and Algorithms using C and C++. This file is for the Section 11 of ...
the course "Linked List".
*/
# include <stdio.h>
# include <stdlib.h>

struct node {
  /*
  The structure to store data and pointer to the next element.
  */
  // Integer element to use store data.
  int value;
  // Pointer to point to the next element.
  struct node *next;
};

void enqueue(struct node **element, int value) {

  struct node *start = (struct node *)malloc(sizeof(struct node));
  if(start) {
    start->value = value;
    start->next = *element;
    *element = start;
  }
  else
    printf("Cannot allocate memeory.\n");
}

int dequeue(struct node **element) {
  if(*element) {
    if((*element)->next) {
      struct node *last = *element;
      while(last->next->next)
        last = last->next;
      int value = last->next->value;
      free(last->next);
      last->next = NULL;
      return value;
    }
    else {
      int value = (*element)->value;
      free(*element);
      *element = NULL;
      return value;
    }
  }
  else {
    printf("The Queue is empty.\n");
    return -100;
  }
}

void display(struct node *element) {
  if(element)
    while(element) {
      printf("%d\n", element->value);
      element = element->next;
    }
  else
    printf("The queue is empty.\n");
}

int main(int argc, char const *argv[]) {
  struct node *element = NULL;
  enqueue(&element, 10);
  enqueue(&element, 11);
  enqueue(&element, 12);
  enqueue(&element, 13);
  enqueue(&element, 14);
  enqueue(&element, 15);
  enqueue(&element, 16);
  display(element);
  printf("%d\n",dequeue(&element) );
  printf("%d\n",dequeue(&element) );
  printf("%d\n",dequeue(&element) );
  printf("%d\n",dequeue(&element) );
  printf("%d\n",dequeue(&element) );
  printf("%d\n",dequeue(&element) );
  printf("The last dequeue.\n");
  printf("%d\n",dequeue(&element) );

  display(element);
  return 0;
}
