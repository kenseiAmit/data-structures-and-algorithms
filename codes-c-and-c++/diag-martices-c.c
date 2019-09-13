/*
This is the coding practice file for Udemy course "Mastering Data ...
Structure and Algorithms using C and C++. This file is for the Section 9 of ...
the course "Matrices".
*/

// Get the required libraries.
# include <stdio.h>
# include <math.h>


struct diagonal_matrix {
  /*
  This structure contains data and properties of a diagonal matrix.
  */

  // Array element for storing data.
  int a[10];
  // Integer element for the property of a diagonal matrix.
  int dimension;
};

void diag_set(struct diagonal_matrix *mat_diag, int row,
  int column, int value) {
  /*
  The method sets a diagonal element of a diagonal matrix toa specifeid value.
  */

  // Check if a valid index is provided.
  if(row < 0 || row >= mat_diag->dimension
    || column < 0 || column >= mat_diag->dimension)
    printf("Please enter a valid index.\n");
  // Check if only diagonal elements are being set.
  else if(row == column)
        mat_diag->a[row] = value;
  else
    printf("Please set only diagonal indices.\n");
}


int diag_get(struct diagonal_matrix *mat_diag, int row, int column) {
  /*
  The method returs a sepcifed diagonal element of a diagonal matrix.
  */

  // Check if valid indices are provided.
  if(row < 0 || row >= mat_diag->dimension
    || column < 0 || column >= mat_diag->dimension)
    printf("Please enter a valid index\n");
  // Check if diagonal elements are being fetched.
  else if( row == column)
      return mat_diag->a[row];
  // All non-diagonal elements are zero.
  else
    return 0;
  // Return negative infnity if an invalid index is being accessed.
  return (int)-INFINITY;
}

void diag_display(struct diagonal_matrix *mat_diag) {
  /*
  The method displays a diagonal matrix.
  */

  // Variables to navigate through the martic.
  int row, column;
  for (row = 0; row < mat_diag->dimension; row++) {
    // Print 0 for non-diagonal elements.
    for(column = 0; column < row; column++)
      printf("%d ", 0);
    // Print the diagonal elements.
    printf("%d ", mat_diag->a[column++]);
    // Print 0 for non-diagonal elements.
    for(;column < mat_diag->dimension; column++)
      printf("%d ", 0);
    printf("\n");
  }
}

int main(int argc, char const *argv[]) {
  struct diagonal_matrix mat_diag = {{1, 2, 3}, 3};
  printf("Under progress.\n");
  diag_set(&mat_diag, 0, 0, 5);
  diag_display(&mat_diag);
  return 0;
}
