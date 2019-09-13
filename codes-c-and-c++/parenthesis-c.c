# include <stdio.h>
# include <stdlib.h>
# include <strings.h>

struct node {
  /*
  A structure to store the data and a pointer to the  next element of the stack.
  */
  // The data element.
  char alphabet;
  // The pointer elemnet to point to the next element.
  struct node *next;
}*top;
// A stack instanace.

void push(struct node **element, char alphabet) {
  /*
  The method inserts an element to the top of the array.
  */
  // Create a new elemnt using a pointer.
  struct node *start = (struct node *)malloc(sizeof(struct node));
  // Check if the stack is not empty.
  if(start) {
    start->alphabet = alphabet;
    start->next = *element;
    // Assign the newely created emement to the pointer to the stack.
    *element = start;
  }
  else
    printf("The stack is full.\n");
}

char pop(struct node **element) {
  /*
  The method removes the top element of the stack and returns it.
  */
  // If the stack is not empty.
  if(*element) {
    struct node *dummy = *element;
    char alphabet = (*element)->alphabet;
    *element = (*element)->next;
    // Free the memeory space occupied by the top element.
    free(dummy);
    return alphabet;
  }
  else {
    printf("The stack is empty.\n");
    return '~';
  }
}

void display(struct node *element) {
  /*
  The method displays the stack from top to bottom.
  */
  // Check if the stack is not empty.
  if(element) {
    while(element) {
      printf("%c\n", element->alphabet);
      element = element->next;
    }
  }
  else
    printf("The stack is empty.\n");
}

int is_balanced(char *expression) {
  /*
  The method returns 0 if an expression is not balanced, else it returns 1.
  The method uses stack to do this.
  */
  // Create the stack to store parenthesis.
  struct node *stack = NULL;
  char alphabet;
  int navigator;
  for(navigator = 0; expression[navigator] != '\0'; navigator++) {
    // Push opening parenthesis to a stack.
    if(expression[navigator] == '(')
      push(&stack, expression[navigator]);
    // Check if the stack is empty.
    else if(expression[navigator] == ')')
      if(stack)
        // Pop closing parenthesis from stack.
        alphabet = pop(&stack);
      else
        // Return 0 if closing parenthesis is being popped from a empty stack.
        return 0;
    else
      continue;
  }
  // Return 1 is stack is balanced at the end.
  if(stack)
    return 1;
  else
    return 0;
}

int is_operand(char value) {
  if(value == '+' || value == '-' || value == '*' || value == '/')
    return 0;
  else
    return 1;
}

int precedence(char value) {
  if(value == '+' || value == '-')
    return 1;
  else if(value == '*' || value == '/')
    return 2;
  else
    return 0;
}

char * in_to_post(char * infix) {
  int navigator1 = 0, navigator2 = 0;
  struct node *stack;
  push(&stack, '#');
  int  length = strlen(infix) + 2;
  char * postfix = (char *)malloc(sizeof(char)*length);
  while(infix[navigator1] != '\0') {
    if(is_operand(infix[navigator1]))
      postfix[navigator2++] = infix[navigator1++];
    else if(precedence(infix[navigator1]) > precedence(stack->alphabet))
        push(&stack, infix[navigator1++]);
    else
        postfix[navigator2++] = pop(&stack);
  }
  display(stack);
  while (stack->alphabet != '#')
    postfix[navigator2++] = pop(&stack);
  postfix[navigator2] = '\0';
  return postfix;
}

int evaluate(char *postfix) {
  struct node *stack;
  int navigator = 0, oprand1, operand2, result = 0;
  while (postfix[navigator] != '\0') {
    if(is_operand(postfix[navigator]))
      push(&stack, postfix[navigator] - '0');
    else {
      operand1 = pop(&stack);
      operand2 = pop(&stack);
      switch(postfix[navigator]) {
        case '+' : result = operand1 + operand2; break;
        case '-' : result = operand1 - operand2; break;
        case '*' : result = operand1 * operand2; break;
        case '/' : result = operand1 / operand2; break;
      }
      push(&stack, result)
    }
  }
  return 0;
}


int main(int argc, char const *argv[]) {
  char *infix = "a+b*c-d/e";
  char *postfix = in_to_post(infix);
  printf("%s\n", postfix);
  return 0;
}
