/*
This is the coding practice file for Udemy course "Mastering Data ...
Structure and Algorithms using C and C++. This file is for the Section 11 of ...
the course "Linked List".
*/

// Get desired libraries.
# include <stdio.h>
# include <stdlib.h>

struct stack {
  /*
  A structure to store data, keep tack of the size and the top element.
  */

  // Integer to track the maximum size.
  int size;
  // Integer to track the top element.
  int top;
  // Pointer to create data storing elements.
  int *values;
};

struct node {
  /*
  Structure to store elements of a stack using linked list.
  */
  // Integer element to store data.
  int value;
  // Pointer to point at the next element;
  struct node *next;
}*top = NULL;

void push_linked_list(struct node **element, int value) {
  /*
  The method pushes, "inserts at the top", an element in the stack.
  */
  // Create a new element using apointer.
  struct node *start = (struct node *)malloc(sizeof(struct node));
  // Check if memory is allocated.
  if(start == NULL)
    printf("The stack is full.\n");
  start->value = value;
  start->next = *element;
  // Start is set as the first element.
  *element = start;
}

int pop_linked_list(struct node **element) {
  if(*element) {
    struct node *start = *element;
    int value = (*element)->value;
    *element = (*element)->next;
    free(start);
    return value;
  }
}

void display_linked_list(struct node *element) {
  while(element) {
    printf("%d\n", element->value);
    element = element->next;
  }
}

void create(struct stack *element) {
  printf("Enter the size of stack:\n");
  scanf("%d", &element->size);
  element->top = -1;
  element->values = (int *)malloc(sizeof(int));
}

void display(struct stack *element) {
  if(element->top == -1)
    printf("The stack is empty\n");
  else {
    int navigator = element->top;
    while(navigator != -1)
      printf("%d\n", element->values[navigator--]);
  }
}

void push(struct stack *element, int value) {
  if(element->top > (element->size - 1))
    printf("Stack overflow !\n");
  else
    element->values[++element->top] = value;
}

int pop(struct stack *element) {
  if(element->top == -1)
    printf("Stack underflow\n");
  else
    return element->values[element->top--];
}

int peek(struct stack *element, int index) {
  if(index < 0 || index > element->top)
  printf("Invalid index\n");
  else
  return element->values[element->top - index];
}

int is_empty(struct stack *element) {
  if(element->top == -1)
  return 1;
  else
  return 0;
}

int is_full(struct stack *element) {
  if((element->top +1) == element->size)
  return 0;
  else
  return 1;
  }

int stack_top(struct stack *element) {
  if(!is_empty(element))
  return element->values[element->top];
  else
  return -1;
}

int main(int argc, char const *argv[]) {

  push_linked_list(&top, 10);
  push_linked_list(&top, 11);
  push_linked_list(&top, 12);
  int x = pop_linked_list(&top);
  display_linked_list(top);
  // struct stack element;
  // create(&element);
  // push(&element, 10);
  // push(&element, 11);
  // push(&element, 12);
  // push(&element, 13);
  // display(&element);
  return 0;
}
