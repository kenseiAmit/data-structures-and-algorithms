/*
This is the coding practice file for Udemy course "Mastering Data ...
Structure and Algorithms using C and C++. This file is for the Section 9 of ...
the course "Matrices".
*/

// Get required libraries.
# include <stdio.h>
# include <stdlib.h>
# include <math.h>

using namespace std;

class lower_triangular_matrix {
  /*
  The Class stores data and properties of a lower triangular matrix.
  */

  // Private maembers.
  private:
    // Array element to store data of a lower triangular matrix.
    int *a;
    // Interger to store the dinemsion of the matrix.
    int dimension;
  // Public members.
  public:
    // Default constructor.
    lower_triangular_matrix() {
      dimension = 2;
      a = new int[dimension*(dimension + 1)/2];
    }
    // Secondary constructor.
    lower_triangular_matrix(int dimension) {
      this->dimension = dimension;
      a = new int[dimension*(dimension + 1)/2];
    }
    // Full fledged initializing constructor.
    lower_triangular_matrix(int a[], int dimension) {
      this->dimension = dimension;
      this->a = new int[dimension*(dimension + 1)/2];
      this->a = a;
    }
    int get_lower_triangle(int row, int column);
    void display_lower_triangle();
    void set_lower_triangle(int row, int column, int value);
};

void lower_triangular_matrix::set_lower_triangle(int row, int column,
  int value) {
  /*
  The method sets the element at a specifed positoin of a lower ...
  tirangual matrix to a specifed value.
  */

  // Check if valid indices are beign set.
  if(row < 0 || row >= dimension ||
     column < 0 || column >= dimension)
     printf("Please enter valid dimenisons\n");
  // Check if lower triangular elemetts are being set.
  else if(column > row)
    printf("Please set only lower triangular elements.\n");
  else
    a[row*(row+1)/2 + column] = value;
}

int lower_triangular_matrix::get_lower_triangle(int row, int column) {
  /*
  The method returns the element at the specified positon of a lower ...
  tiranlgular matrix.
  */

  // Check if valid indices are beign accessed.
  if(row < 0 || row >= dimension ||
     column < 0 || column >= dimension)
     printf("Please enter valid dimenisons\n");
  // Return 0 for upper tirangular elements in a lower triangular matrix.
   else if(column > row)
     return 0;
  // Return the specifed element.
   else
    return a[row*(row+1)/2 + column];
  // Return negative infinity for invalid indices.
  return (int)-INFINITY;
}
void lower_triangular_matrix::display_lower_triangle() {
  /*
  The method dispalys the lower tirangualr matrix.
  */
  // Variables to navigate the matrix.
  int row, column;
  for(row = 0; row < dimension; row++) {
    for(column = 0; column <= row; column++)
      printf("%d ", a[row*(row+1)/2 + column]);
    // Print 0 for upper triangular elements.
    for(; column < dimension; column++)
      printf("%d ", 0);
    printf("\n");
  }
}

int main(int argc, char const *argv[]) {
  int a[] = {1, 2, 3, 4, 5, 6};
  lower_triangular_matrix mat_lower{a, 3};
  printf("%d\n", mat_lower.get_lower_triangle(1, 0));
  mat_lower.display_lower_triangle();
  return 0;
}
