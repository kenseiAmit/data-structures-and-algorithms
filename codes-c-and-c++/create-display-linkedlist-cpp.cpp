/*
This is the coding practice file for Udemy course "Mastering Data ...
Structure and Algorithms using C and C++. This file is for the Section 11 of ...
the course "Linked List".
*/

// Get the required libraries.
# include <stdio.h>
# include <stdlib.h>
# include <iostream>

class node {
  /*
  Node structure that stores elements of linked list.
  */
private:
  // Date element.
  int data;
  // Pointer element that points to the last element.
  struct node *next;
public:
  friend istream & operator>>(istream &input_stream, node &element);
  friend ostream & operator<<(ostream &output_stream, node &element);

}*first = NULL;

istream & operator>>(istream &input_stream, node &element, arr[]) {
  /*
  The method creates a linked list of specified length from data provided ...
  in form of an arrya.
  */
  // A varibale to navigate the linked list.
  int navigator;
  // A new structure to hold the temporary and last element.
  node *element, *last;
  // Create a new node.
  first = new node;
  // Set the first element.
  first.data = arr[0];
  first.next = NULL;
  last = first;
  // Set subsequent elements.
  for(navigator = 1; navigator < length; navigator++) {
    element = new node;
    element.data = arr[navigator];
    element.next = NULL;
    last.next = element;
    last = element;
  }
  return input_stream;
}

ostream & operator<<(node &element) {
  /*
  The method displays the elements of a linked list.
  */
  cout<<"The linked list is as follows:\n";
  // Null is encountered at the end of a linked list.
  while(element != NULL) {
    cout<<element.data<<" ";
    element = element.next;
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

int main(int argc, char const *argv[]) {
  int a[] = {1, 2, 3, 4, 5};
  create(a, 5);
  //display(first);
  //recursive_display(first);
return 0;
}
