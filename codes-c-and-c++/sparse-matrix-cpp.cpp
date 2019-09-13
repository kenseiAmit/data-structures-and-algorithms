/*
This is the coding practice file for Udemy course "Mastering Data ...
Structure and Algorithms using C and C++. This file is for the Section 10 of ...
the course "Sparse Matrices".
*/

// Get the required libraries.
# include <stdio.h>
# include <stdlib.h>
#include <iostream>

using namespace std;

class element {
  /*
  The class contrains the row numebr, column numer and value of an ...
  element in a matrix.
  */

  public:
    int row;
    int column;
    int data;
};

class sparse_matrix {
  /*
  The class contains data elements and properties of sparse matrix.
  */

// Private members of the class.
private:
  int number_of_rows;
  int number_of_columns;
  int non_zero_elements;
  // A pointer to cerate the required number of elements.
  struct element *sparse_element;

// Public members of the class.
public:
  sparse_matrix(int number_of_rows, int number_of_columns,
    int non_zero_elements) {
    this->number_of_rows = number_of_rows;
    this->number_of_columns = number_of_columns;
    this->non_zero_elements = non_zero_elements;
    sparse_element = new element[non_zero_elements];
  }
  sparse_matrix(int number_of_rows, int number_of_columns,
    int non_zero_elements, element *sparse_element) {
    this->number_of_rows = number_of_rows;
    this->number_of_columns = number_of_columns;
    this->non_zero_elements = non_zero_elements;
    this->sparse_element = new element[non_zero_elements];
    this->sparse_element = sparse_element;
  }
  ~sparse_matrix() {
    delete [] sparse_element;
  }
  sparse_matrix operator+(sparse_matrix &mat_sparse);
  friend istream & operator>>(istream &is, sparse_matrix &mat_sparse);
  friend ostream & operator<<(ostream &os, sparse_matrix &mat_sparse);
};

istream & operator>>(istream &input_stream,
  sparse_matrix &mat_sparse) {
  /*
  The method takes input from user and puts them in a sparse matrix.
  */

  // Prompt to enter the elemetns.
  cout<<"Enter the "<<mat_sparse.non_zero_elements<<" non-zero elements:";
  for(int k = 0; k < mat_sparse.non_zero_elements; k++) {
    cout<<"\nEnter the row: ";
    cin>>mat_sparse.sparse_element[k].row;
    cout<<"Enter the column: ";
    cin>>mat_sparse.sparse_element[k].column;
    cout<<"Enter the data: ";
    cin>>mat_sparse.sparse_element[k].data;
  }
  // Return an input stream objec.
  return input_stream;
}

ostream & operator<<(ostream & output_stream,
  sparse_matrix &mat_sparse) {
  /*
  The method displays a sparse matrix.
  */
  cout<<"The matrix is as folows:\n";
  for(int row = 0; row < mat_sparse.number_of_rows; row++) {
    for(int column = 0; column < mat_sparse.number_of_columns; column++) {
      // Defaut value to be prited if no element is present in the ...
      //sparse matrix.
      int value = 0;
      // Check if an elem exists for the row column pair in the sparse matrix.
      for(int element = 0; element < mat_sparse.non_zero_elements; element++)
        if(mat_sparse.sparse_element[element].row == row &&
          mat_sparse.sparse_element[element].column == column)
          // Add the data element to default value.
          value = mat_sparse.sparse_element[element].data;
      cout<<value<<" ";
    }
    cout<<"\n";
  }
  return output_stream;
}

sparse_matrix sparse_matrix::operator+(sparse_matrix &mat_sparse) {
  /*
  The method returns the sum of two sparse matrix.
  */

  // Matrices can be added only if have same dimensions.
  if(number_of_rows == mat_sparse.number_of_rows
    && number_of_columns == mat_sparse.number_of_columns) {
    // Create an array of elemets to store sum of elements.
    struct element *e = new element [non_zero_elements
      + mat_sparse.non_zero_elements];
    // Variables to navigate the matrices.
    int navigate1 = 0, navigate2 = 0, counter = 0;
    // Scan thorugh the first matrix.
    while(navigate1 < non_zero_elements &&
      navigate2 < mat_sparse.non_zero_elements) {
      if(sparse_element[navigate1].row <
        mat_sparse.sparse_element[navigate2].row) {
        e[counter].row = sparse_element[navigate1].row;
        e[counter].column = sparse_element[navigate1].column;
        e[counter++].data = sparse_element[navigate1++].data;
      }
      else if(sparse_element[navigate1].row >
        mat_sparse.sparse_element[navigate2].row) {
        e[counter].row = mat_sparse.sparse_element[navigate2].row;
        e[counter].column = mat_sparse.sparse_element[navigate2].column;
        e[counter++].data = mat_sparse.sparse_element[navigate2++].data;
      }
      else if(sparse_element[navigate1].column <
        mat_sparse.sparse_element[navigate2].column) {
        e[counter].row = sparse_element[navigate1].row;
        e[counter].column = sparse_element[navigate1].column;
        e[counter++].data = sparse_element[navigate1++].data;
      }
      else if(sparse_element[navigate1].column >
        mat_sparse.sparse_element[navigate2].column) {
        e[counter].row = mat_sparse.sparse_element[navigate2].row;
        e[counter].column = mat_sparse.sparse_element[navigate2].column;
        e[counter++].data = mat_sparse.sparse_element[navigate2++].data;
      }
      else {
        e[counter].row = sparse_element[navigate1].row;
        e[counter].column = mat_sparse.sparse_element[navigate2].column;
        e[counter++].data = sparse_element[navigate1++].data +
          mat_sparse.sparse_element[navigate2++].data;
      }
    }
    while(navigate1 < non_zero_elements) {
      e[counter].row = sparse_element[navigate1].row;
      e[counter].column = sparse_element[navigate1].column;
      e[counter++].data = sparse_element[navigate1++].data;
    }
    while(navigate2 < mat_sparse.non_zero_elements) {
      e[counter].row = mat_sparse.sparse_element[navigate2].row;
      e[counter].column = mat_sparse.sparse_element[navigate2].column;
      e[counter++].data = mat_sparse.sparse_element[navigate2++].data;
    }
    // Create a new sparse matri to hold the sum.
    sparse_matrix *b = new sparse_matrix(number_of_rows,
      number_of_columns, counter, e);
    return *b;
  }
  else {
    sparse_matrix b(0, 0, 0);
    return b;
  }
}

int main(int argc, char const *argv[]) {
  cout<<"Inside main, enter a number\n";
  struct sparse_matrix s1(5, 5, 5);
  struct sparse_matrix s2(5, 5, 5);
  cin>>s1;
  cout<<s1;
  return 0;
}
