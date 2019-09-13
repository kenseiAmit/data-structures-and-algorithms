/*
This is the coding practice file for Udemy course "Mastering Data ...
Structure and Algorithms using C and C++. This file is for the Section 11 of ...
the course "Linked List".
*/

// Getting required librries.
# include <stdio.h>
# include <stdlib.h>

struct node {
  /*
  The structure contains the data element, and children pointers.
  */
  // Pointer to the left child.
  struct node *lchild;
  // The data.
  int value;
  // Pointer to right child.
  struct node *rchild;
};

void insert(struct node **root, int key) {
  /*
  The method inserts a node in a "ordered" binary tree.
  */
  // If the tree is empty, assign the key to the root.
  if(*root == NULL) {
    *root = (struct node *)malloc(sizeof(struct node));
    (*root)->value = key;
    (*root)->lchild = (*root)->rchild = NULL;
  }
  // For a non-empty binary tree.
  else {
    // Navigator and parent nodes.
    struct node *parent, *navigator = *root;
    // While the node is no-null.
    while(navigator) {
      // Keep track of the parent.
      parent = navigator;
      // The smaller value is stored in left node.
      if(key < navigator->value)
        navigator = navigator->lchild;
      // Larger value is stored in right node.
      else if(key> navigator->value)
        navigator = navigator->rchild;
      else
        break;
    }
    // If the key is smaller than parent value.
    if(key < parent->value) {
      parent->lchild = (struct node *)malloc(sizeof(struct node));
      parent->lchild->value = key;
      parent->lchild->lchild = parent->lchild->rchild = NULL;
    }
    // If the key is greater than parent value.
    else{
      parent->rchild = (struct node *)malloc(sizeof(struct node));
      parent->rchild->value = key;
      parent->rchild->lchild = parent->rchild->rchild = NULL;
    }
  }
}

void recursive_insert(struct node **root, int value) {
  /*
  The method insets a node in an "ordered" binary tree, usig recursion.
  */
  // If root is not NULL.
  if(*root == NULL) {
    *root = (struct node *)malloc(sizeof(struct node));
    (*root)->value = value;
    (*root)->lchild = (*root)->rchild = NULL;
  }
  // If the value of the root is smaller, insert into the left sub-tree.
  else if(value < (*root)->value)
      recursive_insert(&(*root)->lchild, value);
  // If the value of root is bigger, insert into the right sub-tree.
  else if(value < (*root)->value)
    recursive_insert(&(*root)->lchild, value);
  // Else the value already exist.
  else return;
}

// This delete funciton is useless. It acts wierd and dessembles the ...
// entire tree. The problem is that the method uses recursion to get to the ...
// node to be deleted, and then tries to access the parent of the that node, ...
// when it has already lost track of the parent node in resorting to ...
// recursion for searching for the node. Further, weather the node to be ...
// deleted is present in the left or the right subtree of the parent node is ...
// not taken inot account. This leads to spurious menouvers of the nodes of ...
// the tree.
struct node *delete_tree(struct node **root, int value) {
  /*
  The method delets a node from the tree if it is found.
  */
  // If the root is not NULL>
  if(*root) {
    // If the node is found.
    if(value == (*root)->value) {
      // Variable to navigate the tree, store the node to be returned, ...
      // and the node to be cut.
      struct node *navigator = *root, *first = *root, *last;
      // Find the parent of the greatest node in the left sub-tree.
      while(navigator->rchild->rchild)
        navigator = navigator->rchild;
      // The gretest node in the left sub-tree.
      last = navigator->rchild;
      // The left sub-tree of the parent to the gretest node in the left ...
      // sub-tree is set to the rigth sub-tree of the gretest node in the ...
      // left-sub tree.
      navigator->rchild = last->lchild;
      // Set the right sub-tree of the last node is set to right sub-tree ...
      // of the root.
      last->rchild = (*root)->rchild;
      // Set the left sub-tree of the last node is set to left sub-tree ...
      // of the root.
      last->lchild = (*root)->lchild;
      // Make the last node the root.
      *root = last;
      // Return the first element.
      return first;
    }
    // If the value of the node is smaller than the value, look into the ...
    // left sub-tree.
    else if(value < (*root)->value)
      delete_tree(&((*root)->lchild), value);
    // Else look into the right sub-tree.
    else
      delete_tree(&((*root)->rchild), value);
  }
  // NULL is reached without finding the node.
  else {
    printf("Cannot remove from the tree!\n");
    return NULL;
  }
}

struct node *search(struct node *root, int key) {
  /*
  The method searchs and returns a froma a "ordered" binary tree.
  */
  // If root is not NULL.
  if(root) {
    // Till root is not NULL.
    while(root)
      // If key is smaller look into the left sub-tree.
      if(key < root->value)
        root = root->lchild;
      // Else look in the right sub-tree.
      else if(key > root->value)
        root = root->rchild;
      // Else the key is found.
      else return root;
    // If key is not found.
    printf("Key not found!\n");
    return NULL;
  }
  else {
  printf("Cannot search in an empty tree!\n");
  return NULL;
  }
}

struct node *recursive_search(struct node *root, int key) {
  /*
  The mehtod finds and returns a key if found in a tree, using recursion.
  */
  // If root is not NULL.
  if(root)
    // If key is found.
    if(root->value == key)
      return root;
    // If the key is smaller than root value, look into the left sub-tree.
    else if(key < root->value)
      return recursive_search(root->lchild, key);
    // If key is bigger, look into the right sub-tree.
    else if(key > root->value)
      return recursive_search(root->rchild, key);
  // NULL is found and key is not.
  else {
    printf("Key not found!\n");
    return NULL;
  }
}

int height(struct node *root) {
  /*
  The method returns the height of the tree.
  */
  // If root is not NULL.
  if(root) {
    // Get the height of left sub-tree.
    int left_height = height(root->lchild);
    // Get the height of right sub-tree.
    int right_height = height(root->rchild);
    // Return the maximum of left and right sub-tree height plus 1.
    return left_height >= right_height ? left_height + 1 : right_height + 1;
  }
  // Else return 0.
  else
    return 0;
}

int main(int argc, char const *argv[]) {
  printf("Inside main\n");
  return 0;
}
