/*
This is the coding practice file for Udemy course "Mastering Data ...
Structure and Algorithms using C and C++. This file is for the Section 10 of ...
the course "Sparse Matrices".
*/

// Get the required libraries.
# include <stdio.h>
# include <stdlib.h>

struct element {
  /*
  The structure contrains the row numebr, column numer and value of an ...
  element in a matrix.
  */

  int row;
  int column;
  int data;
};

struct sparse_matrix {
  /*
  The struct contains data elements and properties of sparse matrix.
  */

  int number_of_rows;
  int number_of_columns;
  int non_zero_elements;
  // A pointer to cerate the required number of elements.
  struct element *sparse_element;
};

void create(struct sparse_matrix *mat_sparse) {
  /*
  The method takes input from user and puts them in a sparse matrix.
  */

  // A varibael to navigate a sparese matrix.
  int k;
  // Scan input from user.
  printf("Enter the number of rows:");
  scanf("%d", &mat_sparse->number_of_rows);
  printf("Enter the number of columns:");
  scanf("%d", &mat_sparse->number_of_columns);
  printf("Enter the numebr of non-zero elements:");
  scanf("%d", &mat_sparse->non_zero_elements);
  // Create the required number of elements of a matrix.
  mat_sparse->sparse_element = (struct element *)malloc
    (mat_sparse->non_zero_elements*sizeof(struct element));
  // Scan the elements.
  for(k = 0; k < mat_sparse->non_zero_elements; k++) {
    printf("Enter the row:");
    scanf("%d", &mat_sparse->sparse_element[k].row);
    printf("Enter the column:");
    scanf("%d", &mat_sparse->sparse_element[k].column);
    printf("Enter the data:");
    scanf("%d", &mat_sparse->sparse_element[k].data);
  }
}

void display(struct sparse_matrix *mat_sparse) {
  /*
  The method displays a sparse matrix.
  */

  // Variables to navigate the sparese matrix.
  int row, column, element;
  for(row = 0; row < mat_sparse->number_of_rows; row++) {
    for(column = 0; column < mat_sparse->number_of_columns; column++) {
      // Defaut value to be prited if no element is present in the ...
      //sparse matrix.
      int value = 0;
      // Check if an elem exists for the row column pair in the sparse matrix.
      for(element = 0; element < mat_sparse->non_zero_elements; element++)
        if(mat_sparse->sparse_element[element].row == row &&
          mat_sparse->sparse_element[element].column == column)
          // Add the data element to default value.
          value = mat_sparse->sparse_element[element].data;
      printf("%d ", value);
    }
    printf("\n");
  }
}

struct sparse_matrix* add(struct sparse_matrix *mat_sparse1,
  struct sparse_matrix *mat_sparse2) {
  /*
  The method returns the sum of two sparse matrix.
  */

  // Matrices can be added only if have same dimensions.
  if(mat_sparse1->number_of_rows == mat_sparse2->number_of_rows
    && mat_sparse1->number_of_columns == mat_sparse2->number_of_columns) {
    // Create a new sparse matri to hold the sum.
    struct sparse_matrix *b = (struct sparse_matrix *)malloc
      (sizeof(struct sparse_matrix));
    // Set the numer of rows and columns in the sum matrix.
    b->number_of_rows = mat_sparse1->number_of_rows;
    b->number_of_columns = mat_sparse1->number_of_columns;
    // Create an array of elemets to store sum of elements.
    struct element *e = (struct element *)malloc
      ((mat_sparse1->non_zero_elements
        + mat_sparse2->non_zero_elements)*sizeof(struct element));
    // Variables to navigate the matrices.
    int navigate1, navigate2, counter;
    navigate1 = 0;
    navigate2 = 0;
    counter = 0;
    // Scan thorugh the first matrix.
    while(navigate1 < mat_sparse1->non_zero_elements &&
      navigate2 < mat_sparse2->non_zero_elements) {
      if(mat_sparse1->sparse_element[navigate1].row <
        mat_sparse2->sparse_element[navigate2].row) {
        e[counter].row = mat_sparse1->sparse_element[navigate1].row;
        e[counter].column = mat_sparse1->sparse_element[navigate1].column;
        e[counter++].data = mat_sparse1->sparse_element[navigate1++].data;
      }

      else if(mat_sparse1->sparse_element[navigate1].row >
        mat_sparse2->sparse_element[navigate2].row) {
        e[counter].row = mat_sparse2->sparse_element[navigate2].row;
        e[counter].column = mat_sparse2->sparse_element[navigate2].column;
        e[counter++].data = mat_sparse2->sparse_element[navigate2++].data;
      }
      else if(mat_sparse1->sparse_element[navigate1].column <
        mat_sparse2->sparse_element[navigate2].column) {
        e[counter].row = mat_sparse1->sparse_element[navigate1].row;
        e[counter].column = mat_sparse1->sparse_element[navigate1].column;
        e[counter++].data = mat_sparse1->sparse_element[navigate1++].data;
      }
      else if(mat_sparse1->sparse_element[navigate1].column >
        mat_sparse2->sparse_element[navigate2].column) {
        e[counter].row = mat_sparse2->sparse_element[navigate2].row;
        e[counter].column = mat_sparse2->sparse_element[navigate2].column;
        e[counter++].data = mat_sparse2->sparse_element[navigate2++].data;
      }
      else {
        e[counter].row = mat_sparse1->sparse_element[navigate1].row;
        e[counter].column = mat_sparse2->sparse_element[navigate2].column;
        e[counter++].data = mat_sparse1->sparse_element[navigate1++].data +
          mat_sparse2->sparse_element[navigate2++].data;
      }
    }
    while(navigate1 < mat_sparse1->non_zero_elements) {
      e[counter].row = mat_sparse1->sparse_element[navigate1].row;
      e[counter].column = mat_sparse1->sparse_element[navigate1].column;
      e[counter++].data = mat_sparse1->sparse_element[navigate1++].data;
    }
    while(navigate2 < mat_sparse2->non_zero_elements) {
      e[counter].row = mat_sparse2->sparse_element[navigate2].row;
      e[counter].column = mat_sparse2->sparse_element[navigate2].column;
      e[counter++].data = mat_sparse2->sparse_element[navigate2++].data;
    }
    b->sparse_element = (struct element *)
      malloc(counter*sizeof(struct element));
    b->non_zero_elements = counter;
    b->sparse_element = e;
    return b;
  }
}

int main(int argc, char const *argv[]) {
  printf("%Inside main, enter a number\n");
  struct sparse_matrix s1, *s3;
  create(&s1);
  display(&s1);
  display(add(&s1, &s1));

  //s3 = add(&s1, &s1);
  return 0;
}
