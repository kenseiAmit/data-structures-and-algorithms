/*
This is the coding practice file for Udemy course "Mastering Data ...
Structure and Algorithms using C and C++. This file is for the Section 9 of ...
the course "Matrices".
*/

// Get required libraries.
# include <stdio.h>
# include <math.h>

// Set the namespace;
using namespace std;

class diagonal_matrix {
  /*
  The class contians data, property instances and methods for diagonla marices.
  */

  // Private memeber description.
  private:
    // Pointer to create an array for storing diagonal matrix.
    int *a;
    // The dimension of the diagoanl matrix.
    int dimension;

  // Public member description.
  public:
    // Default constructor, in which the maritx is a 2X2 matrix.
    diagonal_matrix() {
      dimension = 2;
      a = new int[dimension];
    }
    // Secondary constructor.
    diagonal_matrix(int dimension) {
      this->dimension = dimension;
      a = new int[dimension];
    }
    // Full fledged constructor.
    diagonal_matrix(int diagonal_elements[], int dimension) {
      this->dimension = dimension;
      // Create a new array of the specified dimension.
      a = new int[dimension];
      a = diagonal_elements;
    }
    // Deafult destructor.
    ~diagonal_matrix(){
      delete []a;
    }
    int get(int row, int column);
    int get_dimension() {return dimension;}
    void set(int row, int column, int value);
    void display();
};

void diagonal_matrix::set(int row, int column, int value) {
  /*
  The method sets a specified diagonal matrix to a specifeid value.
  */

  // Check if valid indeices are provided.
  if(row < 0 || row >= dimension
    || column < 0 || column >= dimension)
    printf("Please enter a valid index.\n");
  // Set only diagonal matrix.
  else if(row == column)
        a[row] = value;
  else
    printf("Please set only diagonal indices.\n");
}

int diagonal_matrix::get(int row, int column) {
  /*
  The metond returns an elemnt at a specified indices in a diagonal matrix.
  */

  // Check if valid diemnsionsa are provided.
  if(row < 0 || row >= dimension
    || column < 0 || column >= dimension)
    printf("Please enter a valid index\n");
  // Return a diagonal elements.
  else if( row == column)
      return a[row];
  else
  // Return 0 for non-diagonal elements.
    return 0;
  // Return negative-infinitu for invalid indices.
  return (int)-INFINITY;
}

void diagonal_matrix::display() {
  /*
  The method dispalys a diagonal matrix.
  */

  // Variables to navigate a diagonal matrix.
  int row, column;
  // Check if valid indices are provided.
  for (row = 0; row < dimension; row++) {
    // Print 0 for non-diagonal elements.
    for(column = 0; column < row; column++)
      printf("%d ", 0);
    // Print diagonal elements.
    printf("%d ", a[column++]);
    // Print 0 for no-diagonal elemetns.
    for(;column < dimension; column++)
      printf("%d ", 0);
    printf("\n");
  }
}

int main(int argc, char const *argv[]) {
  int a[] = {1, 2, 3};
  diagonal_matrix mat_diag{a, 3};
  mat_diag.set(0, 0, 5);
  mat_diag.display();
  return 0;
}
