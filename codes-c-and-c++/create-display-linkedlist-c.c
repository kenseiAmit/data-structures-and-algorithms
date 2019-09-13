/*
This is the coding practice file for Udemy course "Mastering Data ...
Structure and Algorithms using C and C++. This file is for the Section 11 of ...
the course "Linked List".
*/

// Get the required libraries.
# include <stdio.h>
# include <stdlib.h>

struct node {
  /*
  Node structure that stores elements of linked list.
  */
  // Date element.
  int data;
  // Pointer element that points to the last element.
  struct node *next;
}*first = NULL, *second = NULL, *third = NULL;

struct node_double {
  /*
  Node structure that stores elements of linked list.
  */
  // Date element.
  int data;
  // Pointer element that points to the last element.
  struct node_double *next;
  struct node_double *previous;
}*first_double = NULL, *second_double = NULL, *third_double = NULL;

struct node* create(int arr[], int length) {
  /*
  The method creates a linked list of specified length from data provided ...
  in form of an arrya.
  */
  if(length == 0)
    return NULL;
  else {
    // A varibale to navigate the linked list.
    int navigator;
    // A new structure to hold the temporary and last element.
    struct node *start, *element, *last;
    // Create a new node.
    start = (struct node*)malloc(sizeof(struct node));
    // Set the first element.
    start->data = arr[0];
    start->next = NULL;
    last = start;
    // Set subsequent elements.
    for(navigator = 1; navigator < length; navigator++) {
      element = (struct node*)malloc(sizeof(struct node));
      element->data = arr[navigator];
      element->next = NULL;
      last->next = element;
      last = element;
    }
    return start;
  }
}

struct node* create_circular(int arr[], int length) {
  /*
  The method creates a linked list of specified length from data provided ...
  in form of an arrya.
  */
  if(length == 0)
    return NULL;
  else {
    // A varibale to navigate the linked list.
    int navigator;
    // A new structure to hold the temporary and last element.
    struct node *start, *element, *last;
    // Create a new node.
    start = (struct node*)malloc(sizeof(struct node));
    // Set the first element.
    start->data = arr[0];
    start->next = start;
    last = start;
    // Set subsequent elements.
    for(navigator = 1; navigator < length; navigator++) {
      element = (struct node*)malloc(sizeof(struct node));
      element->data = arr[navigator];
      element->next = start;
      last->next = element;
      last = element;
    }
    return start;
  }
}


struct node_double* create_double(int arr[], int length) {
  /*
  The method creates a linked list of specified length from data provided ...
  in form of an arrya.
  */
  if(length == 0)
    return NULL;
  else {
    // A varibale to navigate the linked list.
    int navigator;
    // A new structure to hold the temporary and last element.
    struct node_double *start, *element, *last;
    // Create a new node.
    start = (struct node_double*)malloc(sizeof(struct node_double));
    // Set the first element.
    start->previous = NULL;
    start->data = arr[0];
    start->next = NULL;
    last = start;
    // Set subsequent elements.
    for(navigator = 1; navigator < length; navigator++) {
      element = (struct node_double*)malloc(sizeof(struct node_double));
      element->previous = last;
      element->data = arr[navigator];
      element->next = NULL;
      last->next = element;
      last = element;
    }
    return start;
  }
}

void display(struct node *element) {
  /*
  The method displays the elements of a linked list.
  */
  printf("The linked list is as follows:\n");
  // Null is encountered at the end of a linked list.
  while(element) {
    printf("%d\n", element->data);
    element = element->next;
  }
}

void display_circular(struct node *element) {
  /*
  The method displays the elements of a linked list.
  */
  struct node *start = element;
  if(element) {
    printf("The circular linked list is as follows:\n");
    // Null is encountered at the end of a linked list.
    do {
      printf("%d\n", element->data);
      element = element->next;
    }while(element != start);
  }
  else
    printf("The linked list is empty\n");
}

void display_double(struct node_double *element) {
  /*
  The method displays the elements of a linked list.
  */
  printf("The linked list is as follows:\n");
  // Null is encountered at the end of a linked list.
  while(element) {
    printf("%d\n", element->data);
    element = element->next;
  }
}


void recursive_display(struct node *element) {
  /*
  The method displays the elements of a linked list.
  */

  // Keep printing till null is encountered.
  if(element != NULL) {
    printf("%d\n", element->data);
    recursive_display(element->next);
  }
}

int count(struct node *element) {
  /*
  The method returns the number of elements in a linekd list.
  */
  // Counter of length.
  int length = 0;
  // Till element is not null.
  while(element) {
    length++;
    element = element->next;
  }
  return length;
}

int sum(struct node *element) {
  /*
  The method returns the sum of all elements of a linekd list.
  */
  // The tracker of sum.
  int sum = 0;
  while(element) {
    sum += element->data;
    element = element->next;
  }
  return sum;
}

int recursive_sum(struct node * element) {
  /*
  The method returns the sum of elements of a linked list using recursion.
  */
  if(element)
    // Return the data + sum of elements in the rest of liked list.
    return (element->data + recursive_sum(element->next));
  else
    return 0;
}

int max(struct node* element) {
  /*
  The method returns the maximum element of a linked list.
  */
  // A variable to keep track of maximum.
  int max = element->data;
  while(element) {
    if(element->data > max)
      max = element->data;
    element = element->next;
  }
  return max;
}

int recursive_max(struct node * element) {
  /*
  The method returns the maximum eleemtn in a linked list using recursion.
  */
  // If this is not the last element.
  if(element->next) {
    // Get the maximum of the element in the rest of the array.
    int sub_max = recursive_max(element->next);
    return (element->data > sub_max ? element->data : sub_max);
  }
  else
    // If this is the last element.
    return element->data;
}

int is_loop(struct node *element) {
  /*
  The method checks if ther are loops in the linked list.
  */
  // Nvigator varibales.
  struct node *element1, *element2;
  element1 = element;
  element2 = element;
  do {
    element1 = element1->next;
    element2 = element2->next;
    // The second navigator always moves one step more than the first one ...
    // till either end encountered or both navigators point to the same ...
    // element.
    element2 = element2 ? element2->next : element;
  } while(element1 && element2 && element1 != element2);

  // If both the navigators point to the same eleemtns, a loop is found.
  if(element1 == element2)
    return 1;
  else
    return 0;
}

int is_sorted(struct node *element) {
  /*
  The method returns 1 if the linked list is sorted, else -1, It uses recurion.
  */
  // Till the second last element is encountered.
  if(element->next->next)
    // If the first two elements are sorted, check the other elemnts.
    if(element->data < element->next->data)
      return is_sorted(element->next);
    else return 0;
  // Base case, if the second last element if encountered, check if ...
  // they are sorted.
  else
    return element->data < element->next->data ? 1 : 0;
}

struct node *merged(struct node *element1, struct node *element2) {
  /*
  The method merges two linekd lists inplace and creates a new linked list without ...
  altering the two other lists.
  */
  // Navigator varibales.
  struct node *start, *last;
  // Create new elemetnt for the merged list.
  start = (struct node *)malloc(sizeof(struct node));
  // Inset the elment that is smaller.
  if(element1->data < element2->data) {
    start->data = element1->data;
    element1 = element1->next;
  }
  else {
    start->data = element2->data;
    element2 = element2->next;
  }
  // Set the last elemet of the new list to null.
  start->next = NULL;
  // Make start and last point to the merged list.
  last = start;
  // Navigate the linked lists.
  while(element1 && element2) {
    if(element1->data < element2->data) {
      start->next = (struct node *)malloc(sizeof(struct node));
      start->next->data = element1->data;
      start->next->next = NULL;
      start = start->next;
      element1 = element1->next;
    }
    else {
      start->next = (struct node *)malloc(sizeof(struct node));
      start->next->data = element2->data;

      start = start->next;
      element2 = element2->next;
    }
    start->next = NULL;
  }
  // Append the remaininng elements.
  while(element1) {
    start->next = (struct node *)malloc(sizeof(struct node));
    start->next->data = element1->data;
    start->next->next = NULL;
    start = start->next;
    element1 = element1->next;
  }
  while(element2) {
    start->next = (struct node *)malloc(sizeof(struct node));
    start->next->data = element2->data;
    start->next->next = NULL;
    start = start->next;
    element2 = element2->next;
  }
  return last;
}

struct node *merge(struct node *element1, struct node *element2) {
  /*
  The method returns a merged linked list, it doesnot keep the individual ...
  linekd lists intact.
  */
  // Navigator varibales.
  struct node *start, *last;
  // Set the smaller element as first.
  if(element1->data < element2->data) {
    start = element1;
    last = element1;
    element1 = element1->next;
  }
  else {
    start = element2;
    last = element2;
    element2 = element2->next;
  }
  // Set the poiter of the last element to null.
  last->next = NULL;
  // Navigate the lists and add elements to the merged list.
  while (element1 && element2) {
    if(element1->data < element2->data) {
      // This changes the lists.
      last->next = element1;
      last = element1;
      element1 = element1->next;
    }
    else {
      last->next = element2;
      last = element2;
      element2 = element2->next;
    }
    last->next = NULL;
  }
  // Insert the remaining elements.
  while(element1) {
    last->next = element1;
    last = element1;
    element1 = element1->next;
    last->next = NULL;
  }
  while(element2) {
    last->next = element2;
    last = element2;
    element2 = element2->next;
    last->next = NULL;
  }
  // Return the merged linked list.
  return start;
}

void remove_duplicates(struct node *element) {
  /*
  The method removes duplicate entries form a linked list.
  */
  int i;
  struct node *next_node = element->next;
  while(next_node){
    if(element->data == next_node->data) {
      element->next = next_node->next;
      element = next_node;
      next_node = element->next;
    }
    else {
      element = next_node;
      next_node = next_node->next;
    }
  }
}

void recursive_reverse(struct node **element) {

  struct node *element1 = NULL, *element2 = NULL;

  while (*element) {
    element1 = element2;
    element2 = *element;
    *element = (*element)->next;
    element2->next = element1;
  }
  *element = element2;
}

void insert(struct node **element, int index, int value) {
  /*
  The method inserts an element at a specified postion in linked list.
  */
  //struct node * start = element;

  // Check if the indices are valid.
  if(index > count(*element) || index < 0)
    printf("Please enter a valid index\n");
  else{
    // A pointer to create a new element.
    struct node * new_element = (struct node *)malloc(sizeof(struct node));
    int navigator;
    new_element->data = value;
    // If the elemet has to be inserted to the begning of the linked list.
    if(index == 0) {
      new_element->next = *element;
      *element = new_element;
    }
    else {
      struct node *traverser = *element;
      for(navigator = 0; navigator < index - 1 ; navigator++)
        traverser = traverser->next;
      new_element->next = traverser->next;
      traverser->next = new_element;
    }
  }
}

void sorted_insert(struct node **element, int value) {
  struct node *element1 = (struct node *)malloc(sizeof(struct node));
  struct node *navigator = *element;
  element1->data = value;
  if(value < (*element)->data) {
    printf("first element %d\n", (*element)->data);
    element1->next = *element;
    *element = element1;
  }
  else {
    while(navigator->next) {
      if(navigator->next->data > value) {
        printf("Inside the list %d\n", navigator->data);
        element1->next = navigator->next;
        navigator->next = element1;
        break;
      }
    navigator= navigator->next;
    }

    if(!navigator->next) {
      printf("Last element %d\n", navigator->data);
      element1->next = NULL;
      navigator->next = element1;
    }
  }
}

int main(int argc, char const *argv[]) {
  int a[] = {1, 2, 3, 4, 5, 6};
  int b[] = {2, 4, 8, 12, 57, 90};
  first_double = create_double(a, 6);
  display_double(first_double);
return 0;
}

//second = create(b, 6);
//third = merged(first, second);
//display(third);
//insert(&third, 12, 77);
//recursive_reverse(&third);
//sorted_insert(&third, 100);
//display(third);

// void append(struct node **element, int value) {
  //   insert(element, count(element), value);
  // }

// struct node* insertt(struct node *element, int index, int value) {
//    /*
//     The method inserts an element at a specified postion in linked list.
//     */
//   struct node * start = element;
//     // Check if the indices are valid.
//   if(index > count(element) || index < 0)
//     printf("Please enter a valid index\n");
//   else{
//     // A pointer to create a new element.
//     struct node * new_element = (struct node *)malloc(sizeof(struct node));
//     int navigator;
//     new_element->data = value;
//     // If the elemet has to be inserted to the begning of the linked list.
//     if(index == 0) {
//         new_element->next = start;
//         start = new_element;
//     }
//     else {
//       for(navigator = 0; navigator < index - 1 ; navigator++)
//         element = element->next;
//       new_element->next = element->next;
//       element->next = new_element;
//     }
//   }
//   return start;
// }
