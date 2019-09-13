/*
This is the coding practice file for Udemy course "Mastering Data ...
Structure and Algorithms using C and C++. This file is for the Section 11 of ...
the course "Linked List".
*/

// Get the required libraries.
# include <stdio.h>
# include <stdlib.h>
# include <iostream>

using namespace std;

class node {
  /*
  Node class that stores data and reference elements of linked list.
  */
  // Date element.
public:
  int data;
  // Pointer element that points to the last element.
  node *next;
}*first = NULL, *second = NULL, *third = NULL;

class node_double {
  /*
  Node class that stores elements of linked list.
  */
public:
  // Date element.
  int data;
  // Pointer element that points to the last element.
  node_double *next;
  node_double *previous;
}*first_double = NULL, *second_double = NULL, *third_double = NULL;

class linked_list {
private:
  node *first;
public:
  linked_list() {first = NULL;}
  linked_list(int values[], int length);
  ~linked_list();

  void display();
  void insert(int index, int value);
  int delete_link(int index);
  int length();
};

linked_list::linked_list(int values[], int length) {
  if(length == 0)
    first = NULL;
  else {
    node * last;
    first = new node;
    first->data = values[0];
    last = first;
    first->next = NULL;
    int navigator;
    for(navigator = 1; navigator < length; navigator++) {
      last->next = new node;
      last = last->next;
      last->data = values[navigator];
      last->next = NULL;
    }
  }
}

linked_list::~linked_list() {
  node *p = first;
  while (first) {
    first = first->next;
    delete p;
    p = first;
  }
}

void linked_list::display() {
  node *element = first;
  while(element) {
    cout<<element->data<<"\n";
    element = element->next;
  }
  cout<<endl;
}

int linked_list::length() {
  node *element;
  int length;
  for(int length = 0; element; length++, element = element->next)
    length++;
  return length;
}

void linked_list::insert(int index, int value) {
  if(index < 0 || index > length())
    printf("Please enter a valid index.\n");
  else {
    node *element = first, *last;
    if(index == 0) {
      printf("index is 0\n" );
      element = new node;
      element->data = value;
      element->next = first;
      first = element;
    }
    else {
      for(int navigator = 0; navigator < index-1;
        navigator++, element = element->next);
      printf("Index is%d\n", index);
      last = element->next;
      element->next = new node;
      element->next->data = value;
      element->next->next = last;
    }
  }
}

int linked_list::delete_link(int index) {
  if(index < - 1 || index >= length())
  return 0;
  else {
    int value;
    node * element = first, *last;
    if(index == 0) {
      first = first->next;
      value = last->data;
      delete last;
    }
    else {
      for(int navigator = 0; navigator < index-1;
        navigator++, element = element->next)
        last = element->next;
        element->next = element->next->next;
        last->data = value;
        delete last;
      }
      return value;
    }
  }

int main(int argc, char const *argv[]) {
  int a[] = {1, 2, 3, 4, 5};
  //int b[] = {2, 4, 8, 12, 57, 90};
  //first_double = create_double(a, 6);
  //display_double(first_double);
  linked_list l(a, 5);
  l.display();
  l.insert(3, -1);
  l.display();
return 0;
}
