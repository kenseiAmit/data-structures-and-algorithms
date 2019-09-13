# include <stdio.h>

struct node {
  struct node *left_child;
  int value;
  int height;
  struct node *right_child;
};
//
// int node_height(struct node *root) {
//   int left_height, right_height;
//   left_height  = root && root->left_child  ? root->left_height  : 0;
//   right_height = root && root->right_child ? root->right_height : 0;
//   return left_height >= right_height ? left_height + 1 : right_height + 1;
// }
//
// int balance_factor(struct node *root) {
//   int left_height, right_height;
//   left_height  = root && root->left_child  ? root->left_height  : 0;
//   right_height = root && root->right_child ? root->right_height : 0;
//   return left_height - right_height;
// }
//
// struct node *ll_rotation(struct node *root) {
//   struct node *left_child = root->left_child, right_child = root->right_child;
//   left_child->right_child = root;
//   root->left_child;
// }

int main(int argc, char const *argv[]) {
  printf("Maining!\n");
  return 0;
}
