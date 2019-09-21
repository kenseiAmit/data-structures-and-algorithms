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
  /*
  The method sorts an array in increasing order.
  */
  // Navigator and flag variales to access the array and mark the
  int navigator1, navigator2, flag = 0;
  // Traverse through the array.
  for(navigator1 = 0; navigator1 < length - 1; navigator1++) {
    // Set flag to 0 at the begning of each traversal.
    flag = 0;
    // Traverse thorugh a sub-array.
    for(navigator2 = 0; navigator2 < length - navigator1 - 1; navigator2++) {
      // If values are not in the right oreder, swap them, and set flag to 1.
      if( values[navigator2] > values[navigator2 + 1]) {
        swap(&values[navigator2], &values[navigator2 + 1]);
        flag = 1;
      }
    }
    // If flag is not set to 0, the array is already sorted from here onwards.
    if(flag == 0)
    break;
  }
}

int main(int argc, char const *argv[]) {
  // An array of integers.
  int values[] = {11, 13, 7, 12, 16, 9, 24, 5, 10, 3};
  // The length of arary and a navigator.
  int length = 10, navigator;
  // Bubble sort the array.
  bubble(values, length);
  // Display the array.
  for(navigator = 0; navigator < length; navigator++) {
    printf("%d\n", values[navigator]);
  }
  return 0;
}
