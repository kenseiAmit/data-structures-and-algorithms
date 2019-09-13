/*
This is the coding practice file for Udemy course "Mastering Data ...
Structure and Algorithms using C and C++. This file is for the Section 11 of ...
the course "Linked List".
*/

# include <stdio.h>
# include <stdlib.h>

void swap(int *first, int *second) {
  /*
  The method swaps two integers accessing them through pointers.
  */
  // Temporary variable.
  int temporary = *first;
  // Assign the value of the second integer to the first.
  *first = * second;
  // Assign the value of the first integer now stored in the temporary ...
  // variable to the second.
  *second = temporary;
}

void bubble(int values[], int length) {
  // Navigator and flag variales to access the array and mark the
  int navigator1, navigator2, flag = 0;

  for(navigator1 = 0; navigator1 < length - 1; navigator1++) {
    flag = 0;
    for(navigator2 = 0; navigator2 < length - navigator1 - 1; navigator2++) {
      if( values[navigator2] < values[navigator2 + 1]) {
        swap(&values[navigator2], &values[navigator2 + 1]);
        flag = 1;
      }
      if(flag == 0)
        break;
    }
  }
}

int main(int argc, char const *argv[]) {
  int values[] = {11, 13, 7, 12, 16, 9, 24, 5, 10, 3};
  int length = 10, navigator;

  bubble(values, length);

  for(navigator = 0; navigator < length; navigator++) {
    printf("%d\n", values[navigator]);
  }
  return 0;
}
