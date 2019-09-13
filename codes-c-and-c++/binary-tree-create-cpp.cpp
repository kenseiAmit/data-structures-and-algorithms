/*
This is the coding practice file for Udemy course "Mastering Data ...
Structure and Algorithms using C and C++. This file is for the Section 11 of ...
the course "Linked List".
*/
# include <iostream>
# include <stdio.h>

using namespace std;

<template class kind>
class node {
  /*
  A class to store data in a node and its left and right childre.
  */
private:
  // Left child pointer.
  struct node *lchild;
  // Data element.
  kind value;
  // Right child pointer.
  node *rchild;
public:
  node () { value = 0; lchild = rchild = NULL; }
  node (kind value) { this->value = value; lchild = rchild = NULL; }
  node (node *lchild, kind value, node *rchild) {
    this->lchild = lchild;
    this->value = value;
    this->rchild = rchild;
  }
  void set_lchild(node *lchild) { this->lchild = lchild; }
  void set_lchild(kind value) { lchild = new node(value); }
  void set_rchild(node *rchild) { this->rchild = rchild; }
  void set_rchild(kind value) { rchild = new node(value); }
  void set_value(kind value) { this->value = value;}
  int get_value() { return value; }
  node *get_lchild() { return lchild;}
  node *get_rchild() { return rchild;}
};

<template class type>
class stack {
  /*
  The class stack stores the size, lenght and pointers to the nodes ...
  in the stack.
  */
private:
  // The maximum size of the stack.
  int size;
  // The present length of the stack.
  int length;
  // A pointer to create an arry to hold stack elements.
  type *elements;
public:
  // The method intializes an empty stack of size 10;
  stack() { size = 10; length = -1; elements = new type[size]; }
  // The method initializes an empty stack of specified size.
  stack(int size) { size = 10; length = -1; elements = new type[size]; }
  stack(int size, int length, type values[]) {
    /* The method initializes a stack of given size and data in array.
    */
    // Length should be less than the size.
    if(length >= size)
      cout<<"Stack overflow!\n";
    this->size = size;
    // Set length of the stack to -1.
    this->length = -1;
    // Set length to be the smaller of lenght and size.
    length = length < size ? length : size - 1;
    // Allocate memeory for elements.
    elements = new type[size];
    // Push elements into the stack.
    for(int navigator = 0; navigator <= length; navigator++)
      push(values[navigator]);
  }
  stack(int length, type values[]) {
    /* The method initializes a stack of given length and data in an array.
    */
    // Set the size.
    size = length  + 1;
    // Set the lenght to -1.
    this->length = -1;
    // Allocate memory using the pointer.
    elements = new type[size];
    // Push elements into the stack.
    for(int navigator = 0; navigator <= length; navigator++)
      push(values[navigator]);
  }
  // The method returns if the stack is empty.
  int is_empty_stack() { return length == -1 ? 1 : 0; }
  // The method returns if the stack is full.
  int is_full_stack() { return length == size -1 ? 1 : 0; }
  // The method pushes an elment into the stack.
  void push(type nodule) {
    if(is_full_stack())
      cout<<"Stack overflow!\n";
    else
      elements[++length] = nodule;
  }
  // The method peeks into the stack.
  kind *peek(int index) {
    if(is_empty_stack) {
      cout<<"Cannot peek into an empty stack\n";
      return NULL;
    }
    else if(index < 0  || index > length) {
      cout<<"Invalid index\n";
      return NULL;
    }
    else
      return elements[length - index];
  }
  type *pop() {
    if(is_empty_stack) {
      cout<<"Stack underflow!\n"
      return NULL;
    }
    else
      return elements[length--];
  }
};

<template class kind, class ilk>
class queue {
  /*
  A queue to create a tree. The queue stores the nodes that have been ...
  created but whose children have not been set.
  */
private:
  // Size of the queue to store the nodes.
  int size;
  // Front of the queue.
  int front;
  // Rear of the queeue.
  int rear;
  // Double pointer elemetn to cretae an array of pointers that will store ...
  // the pointer to the nodes of a tree.
  <ilk>kind *elements;
public:
  // The method  initializes an empty queue of size 10.
  queue() { size = 10; front = rear = 0; elements = new <ilk>kind[elements]; }
  // The method intializes an empty queue of specifeid size.
  queue(int size) {
    this->size = size;
    front = rear = 0;
    elements = new <ilk>kind[size];
  }
  // The method initializes queue of given size and data in array.
  queue(int size, int length; <ilk>kind values[]) {
    if(size < length - 1)
      cout<<"Queue overflow!\n";
    this->size = size;
    length = length < size ? length : size -1;
    front = rear = 0;
    elements = new <ilk>kind[elements];
    for(navigator = 0; navigator < length; navigator++)
      enqueue(values[rear]);
  }
  // The method inializes a queue of give length.
  queue (int length, <ilk>kind values[]) {
    this->size = length + 1;
    front = rear = 0;
    elements = new <ilk>kind[size];
    for(navigator = 0; navigator < length; navigator++)
      enqueue(values[rear])
  }
  void enqueue(<ilk>kind nodule) {
    /*
    The method insers an element at the back of a queue.
    */
    // The queue is circualr in nature.
    // Queue is full only if rear and fornt differ by one.
    if((rear + 1) % size == front)
      cout<<"Queue is full.\n";
    else {
      // Increase the rear by one, and insert the element.
      rear = (rear + 1) % size;
      elements[rear] = nodule;
    }
  }
  <ilk>kind *dequeue() {
    /*
    The method removes an element from front and returns it.
    */
    // The queue is empty if rear and front are the same.
    if(front == rear) {
      cout<<"Queue is empty.\n";
      return NULL;
    }
    else {
      front = (front + 1) % size;
      //nodule = line->elements[line->front];
      return elements[front];
    }
  }
  //The method checks if a queue is empty.
  int is_empty_queue(queue line) { return front == rear; }
};

<template class genus, class breed>
class tree {
private:
  <breed>genus *root;
public:
  //tree() {root = NULL;}
  tree() {
    <breed>genus *element, *navigator;
    breed value;
    <node*, breed> queue list(100);
    cout<<"Enter the value of the root node:\n";
    cin>>value;
    root = new <breed>genus(value);
    list.enqueue(root);
    while (!list.is_empty()) {
      navigator = list.dequeue();
      cout<<"Enter the value of the left child of %d:\n";
      cin>>value;
      if(value!= -1) {
        navigator.set_lchild(value);
        list.enqueue(navigator->lchild);
      }
      cout<<"Enter the value of the right child of %d:\n";
      cin>>value;
      if(value!= -1) {
        navigator.set_rchild(value);
        list.enqueue(navigator->rchild);
      }
    }
  }
  // void preorder() {preorder();}
  // void preorder();
  // void postorder() {postorder();}
  // void postorder();
  // void inorder() {inorder();}
  // void inorder();
  // void levelorder() {levelorder();}
  // void levelorder();
  // int height() {return height(root);}
  // int height();
};

int main(int argc, char const *argv[]) {
  graph = <node, int>tree();
  return 0;
}

// void tree::create_tree() {
// }
//
// void tree::preorder() {
//   if(root) {
//     printf("%s\n", root->data);
//     preorder(root->lchild);
//     preorder(root->rchild);
//   }
// }
//
// void tree::inorder() {
//   if(root) {
//     inorder(root->lchild);
//     printf("%s\n", root->data);
//     inorder(root->rchild);
//   }
// }
//
// void tree::postorder() {
//   if(root) {
//     postorder(root->lchild);
//     postorder(root->rchild);
//     printf("%s\n", root->data);
//   }
// }
//
// void tree::levelorder(node *root) {
//   queue line(100);
// }
