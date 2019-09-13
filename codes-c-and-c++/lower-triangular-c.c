/*
This is the coding practice file for Udemy course "Mastering Data ...
Structure and Algorithms using C and C++. This file is for the Section 9 of ...
the course "Matrices".
*/

// Get required libraries.
# include <stdio.h>
# include <stdlib.h>
# include <math.h>

struct lower_triangular_matrix {
  /*
  The structure stores data and properties of a lower triangular matrix.
  */

  // Array element to store data of a lower triangular matrix.
  int *a;
  // Interger to store the dinemsion of the matrix.
  int dimension;
};

void set_lower_triangle(struct lower_triangular_matrix * mat_lower, int row,
  int column, int value) {
  /*
  The method sets the element at a specifed positoin of a lower ...
  tirangual matrix to a specifed value.
  */

  // Check if valid indices are beign set.
  if(row < 0 || row >= mat_lower->dimension ||
     column < 0 || column >= mat_lower->dimension)
     printf("Please enter valid dimenisons\n");
  // Check if lower triangular elemetts are being set.
  else if(column > row)
    printf("Please set only lower triangular elements.\n");
  else
    mat_lower->a[row*(row+1)/2 + column] = value;
}

int get_lower_triangle( struct lower_triangular_matrix *mat_lower,
  int row, int column) {
  /*
  The method returns the element at the specified positon of a lower ...
  tiranlgular matrix.
  */

  // Check if valid indices are beign accessed.
  if(row < 0 || row >= mat_lower->dimension ||
     column < 0 || column >= mat_lower->dimension)
     printf("Please enter valid dimenisons\n");
  // Return 0 for upper tirangular elements in a lower triangular matrix.
   else if(column > row)
     return 0;
  // Return the specifed element.
   else
    return mat_lower->a[row*(row+1)/2 + column];
  // Return negative infinity for invalid indices.
  return (int)-INFINITY;
}
void display_lower_triangle(struct lower_triangular_matrix *mat_lower) {
  /*
  The method dispalys the lower tirangualr matrix.
  */
  // Variables to navigate the matrix.
  int row, column;
  for(row = 0; row < mat_lower->dimension; row++) {
    for(column = 0; column <= row; column++)
      printf("%d ", mat_lower->a[row*(row+1)/2 + column]);
    // Print 0 for upper triangular elements.
    for(; column < mat_lower->dimension; column++)
      printf("%d ", 0);
    printf("\n");
  }
}

int main(int argc, char const *argv[]) {
  int a[] = {1, 2, 3, 4, 5, 6};
  struct lower_triangular_matrix mat_lower = {a, 3};
  printf("%d\n", get_lower_triangle(&mat_lower, 1, 0));
  display_lower_triangle(&mat_lower);
  return 0;
}
