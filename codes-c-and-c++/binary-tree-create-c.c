/*
This is the coding practice file for Udemy course "Mastering Data ...
Structure and Algorithms using C and C++. This file is for the Section 11 of ...
the course "Linked List".
*/
# include <stdio.h>
# include <stdlib.h>

struct node {
  /*
  A structure to store data in a node and its left and right childre.
  */
  // Left child pointer.
  struct node *lchild;
  // Data element.
  int data;
  // Right child pointer.
  struct node *rchild;
};

struct stack {
  // The maximum size of the stack.
  int size;
  // The present length of the stack.
  int length;
  // A pointer to create an arry to hold stack elements.
  struct node **elements;
};

void  create_stack(struct stack *pile, int size) {
  /*
  The method returns a stack of specified size.
  */
  // The maximum number of elements the stak can hold.
  pile->size = size;
  // The present length of stack is set to -1.
  pile->length = -1;
  // Allocate memeory to store node elements.
  pile->elements = (struct node **)malloc(sizeof(struct node*));
}

int is_empty_stack(struct stack pile) {
  if(pile.length == -1)
    return 1;
  else
    return 0;
}

void push(struct stack *pile, struct node *nodule) {
  if(pile->length == (pile->size - 1))
    printf("Stack overflow!\n");
  else
    pile->elements[++pile->length] == nodule;
}

struct node *pop(struct stack *pile) {
  if(pile->length == -1) {
    printf("Stack underflow!\n");
    return NULL;
  }
  else
  return pile->elements[pile->length--];
}

struct queue {
  /*
  A queue to create a tree. The queue stores the nodes that have been ...
  created but whose children have not been set.
  */
  // Size of the queue to store the nodes.
  int size;
  // Front of the queue.
  int front;
  // Rear of the queeue.
  int rear;
  // Double pointer elemetn to cretae an array of pointers that will store ...
  // the pointer to the nodes of a tree.
  struct node **elements;
};

void create_queue(struct queue *line, int size) {
  /*
  The method creats a queue.
  */
  line->size = size;
  // The front and end of the queue are assigned 0.
  line->front = line->rear = 0;
  // Allocate memory to store pointers to nodes in a tree.
  line->elements = (struct node **)malloc(size*sizeof(struct node *));
}

void enqueue(struct queue *line, struct node *nodule) {
  /*
  The method insers an element at the back of a queue.
  */
  // The queue is circualr in nature.
  // Queue is full only if rear and fornt differ by one.
  if((line->rear + 1) % line->size == line->front)
    printf("Queue is full.\n");
  else {
    // Increase the rear by one, and insert the element.
    line->rear = (line->rear + 1) % line->size;
    line->elements[line->rear] = nodule;
  }
}

struct node *dequeue(struct queue *line) {
  /*
  The method removes an element from front and returns it.
  */
  //struct node *nodule = NULL;
  // The queue is empty if rear and front are the same.
  if(line->front == line->rear) {
    printf("Queue is empty.\n");
    return NULL;
  }
  else {
    line->front = (line->front + 1) % line->size;
    //nodule = line->elements[line->front];
    return line->elements[line->front];
  }
  //return nodule;
}

int is_empty_queue(struct queue line) {
  /*
  The method checks if a queue is empty.
  */
  return line.front == line.rear;
}

void tree_create( struct node **root) {
  /*
  A function that creates a tree of given size.
  I takes size of the tree as input, and node values too.
  */
  // A variable to navigate the queue that contains the tree and an element ...
  // add nodes to the tree.
  struct node *navigator, *element;
  // A varibel to get the node values and the size of the tree.
  int value, size;
  // The queue that contains the tree.
  // Here tree is implemented using queue.
  // This must be one of the ways of implementing tree.
  // Although the queue created by this funciton will be lost after the ...
  // funciton expires, we will still have access to the queue through the ...
  // root node declared globally.
  // We will insert into the queue each node whose left and right children ...
  // nodes are to be assgined. Once they are assigned, the node will be ...
  // removed from the queue.
  struct queue line;
  printf("Enter the number of elements in the tree:\n");
  scanf("%d", &size);
  // Call the create function to create a queue of specified size.
  // Notice that the size of the queue is the maxixmum number of nodes ...
  // that exist and whose children we have not yet inserted. So this does ...
  // not have much to do with the number of elements in the tree.
  // We would want to keep it large enough to make a large tree.
  create_queue(&line, size);
  // Get input for root node
  printf("Enter the root value:\n");
  scanf("%d", &value);
  // Allocate memeory to store the root.
  *root = (struct node *)malloc(sizeof(struct node));
  // Set the root data.
  (*root)->data = value;
  // Set the left and right child to null.
  (*root)->lchild = (*root)->rchild = NULL;
  // Insert the root to the tree.
  // This signifies that left and rigt children of root are to be set.
  // Rememeber that the root can be accessed from outside this funciton.
  // This means that the tree will be accessible after the expiration of ...
  // this funciton.
  enqueue(&line, *root);
  // Start iserting subsequent nodes in the tree.
  // Each node in the queue must either be a leave or have either  a left ...
  // or right child, or both. Also all nodes shoud have a value.
  // Further, nodes in a tree are stored in increasing order of there level, ...
  // that is to say that root comes first, then its children, then their ...
  // children.
  while(!is_empty_queue(line)) {
    // The navigator variable plucks an element from the queue. We wil set ...
    // the left and the right elements of the node and insert them into the ...
    // queue to set their left and right elements latter.
    navigator = dequeue(&line);
    // Get the value of the left child.
    printf("Enter left child of %d:\n", navigator->data);
    scanf("%d", &value);
    // If the value is -1, the left child doesnot exist.
    if(value != -1) {
      // Alloacat memory for left child node.
      //element = (struct node *)malloc(sizeof(struct node));
      navigator->lchild = (struct node *)malloc(sizeof(struct node));
      // Set data for the left child note.
      //element->data = value;
      navigator->lchild->data = value;
      // Set the left and right child of the node to null.
      //element->lchild = element->rchild = NULL;
      navigator->lchild->lchild = navigator->lchild->rchild = NULL;
      // Assign the element to  left child.
      //navigator->lchild = element;
      // Inser the left child in the queue.
      //enqueue(&line, element);
      enqueue(&line, navigator->lchild);
    }
    // Get the value of the right child.
    printf("Enter the right child of %d:\n", navigator->data);
    scanf("%d", &value);
    // If the value is -1, the child does not exist.
    if(value != -1) {
      // Allocate memory for the right child.
      //element = (struct node *)malloc(sizeof(struct node));
      navigator->rchild = (struct node *)malloc(sizeof(struct node));
      // Set the value of the node.
      //elemen->data =  value;
      navigator->rchild->data =  value;
      // Set its children to null.
      //element->lchild = element->rchild = NULL;
      navigator->rchild->lchild = navigator->rchild->rchild = NULL;
      // Assign the node to right child of the node.
      //navigator->rchild = element;
      // Inset the node to queue to set its children later.
      //enqueue(&line, element);
      enqueue(&line, navigator->rchild);
    }
  }
}

void preorder(struct node *nodule) {
  /*
  The method prints the tree in preorder. Preorder is node data, folowed by ...
  all left node data, followed by right data and its left data.
  */
  if(nodule) {
    printf("%d\n", nodule->data);
    preorder(nodule->lchild);
    preorder(nodule->rchild);
  }
}

void inorder(struct node *nodule) {
  /*
  The method prints the tree in inorder.
  */
  if(nodule) {
    inorder(nodule->lchild);
    printf("%d\n", nodule->data);
    inorder(nodule->rchild);
  }
}

void postorder(struct node *nodule) {
  /*
  The method prints a tree in postorder.
  */
  if(nodule) {
    postorder(nodule->lchild);
    postorder(nodule->rchild);
    printf("%d\n", nodule->data);
  }
}

int count(struct node *root) {
  /*
  The method returs the number of nodes in a tree.
  */
  // Numeber of nodes in a tree is the number of nodes in the left sub tree ...
  // plus number of nodes in the right sub tree plus one.
  if(root)
    return 1 + count(root->lchild) + count(root->rchild);
  else
    return 0;
}

int height(struct node *root) {
  /*
  The method returns the height of the tree.
  */
  // If leaves are encountered.
  if(!root)
    return 0;
  // The height of a tree is the one plus the greater of the height of left sub ...
  // tree or the height of the right sub tree.
  else {
    // Varibles to store height of  left and right trees.
    int left_height = 0, right_height = 0;
    // Get height of left tree.
    left_height = height(root->lchild);
    // Get height of right tree.
    right_height = height(root->rchild);
    // Check which height is greater.
    if(left_height > right_height)
      return left_height + 1;
    else
      return right_height + 1;
  }
}

void levelorder(struct node *root) {
  /*
  The method prints the tree in level order. That is to say, elements at ...
  a given level are printed first. The method uses iteration and not ...
  recursion to it.
  */
  // A queue to store the nodes whose elements have not been printed.
  struct queue list;
  create_queue(&list, 100);
  // Print data at the root, and push it to the queue.
  printf("%d\n", root->data);
  enqueue(&list, root);
  // Till the queue is empty, keep printing elements, pushing and popping ...
  // nodes into the queue.
  while (!is_empty_queue(list)) {
    // Pop an element from queue.
    root = dequeue(&list);
    // If left child of the node exists, pritn it and push it to the queue.
    if(root->lchild) {
      printf("%d\n", root->lchild->data);
      enqueue(&list, root->lchild);
    }
    // Now do the same to the right child.
    if(root->rchild) {
      printf("%d\n", root->rchild->data);
      enqueue(&list, root->rchild);
    }
  }
}

void  iterative_preorder(struct node *nodule) {
  /*
  The method uses iterative method to print the tree in preorder.
  */
  // Create a stack to push nodes into it.
  struct stack pile;
  create_stack(&pile, 100);
  // While node is not empty and the stack is not empty.
  while(nodule || is_empty_stack(pile)) {
    // If node is not empty, print the node data and push it to the stack.
    // AAssign node to its left child.
    if(nodule) {
      printf("%d\n", nodule->data);
      push(&pile, nodule);
      nodule = nodule->lchild;
    }
    // Pop an element from the stack and go to its right child.
    else {
      nodule = pop(&pile)->rchild;
    }
  }
}

void iterative_inorder(struct node *nodule) {
  /*
  The method prints a tree in-order. It usese itreativ method to do that.
  */
  // Create stack of nodes.
  struct stack pile;
  create_stack(&pile, 100);
  // Till node is empty or the stack is empty.
  while (nodule || is_empty_stack(pile)) {
    // If node is not empty, push it into the stack and set node to its left ...
    // child.
    if(nodule){
      push(&pile, nodule);
      nodule = nodule->lchild;
    }
    // If the node is empty, pop and node from the stakck and print its ...
    // data, then set the node to its right child.
    else {
      nodule = pop(&pile);
      printf("%d\n", nodule->data);
      nodule = nodule->rchild;
    }
  }
}

int main(int argc, char const *argv[]) {

  struct node *root = NULL;
  tree_create(&root);
  printf("Preorder\n");
  preorder(root);
  printf("Postorder\n");
  postorder(root);
  printf("inorder\n");
  postorder(root);
  return 0;
}
