/*
This is the coding practice file for Udemy course "Mastering Data ...
Structure and Algorithms using C and C++. This file is for the Section 11 of ...
the course "Linked List".
*/

// Get the required libraries.

# include <stdio.h>
# include <stdlib.h>
# include <math.h>

struct node {
  /*
  The structure to store coefficent and powers of terms.
  */
  // Integer element to store coefficeint of a term.
  int coefficent;
  // Integer element to store power of a term.
  int power;
  // Pointer element to store the poitner to the next element.
  struct node *node;
}poly = NULL;

void create() {
  struct node *element, *last = NULL;
  int number, navigator;

  printf("Entee the number of terms:\n");
  scanf("%d", &number);
  printf("Enter each term with coefficient and power:\n");

  for( navigator = 0; navigator < numebr; navigator++) {
    last = (struct node*)malloc(sizeof(struct node));
    scanf("%d%d",&last->coefficient, &last->power);
    last->next = NULL;
    if(poly = NULL) {

    }
  }
}
