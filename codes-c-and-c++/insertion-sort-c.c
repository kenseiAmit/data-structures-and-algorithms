/*
This is the coding practice file for Udemy course "Mastering Data ...
Structure and Algorithms using C and C++. This file is for the Section  of ...
the course, "".
*/

# include <stdio.h>
# include <stdlib.h>

void swap(int *first, int *second) {
  /*
  The method swaps two numbers in-place.
  */
  // Store the first number in a temporary variable.
  int temporary = *first;
  // Assign the second number to the first.
  *first = *second;
  // Assgin the second number to temporary varibale.
  *second = temporary;
}

void insertion(int values[], int length) {
  printf("Insetion sort in progress\n");
  /*
  The metod returns an arary sorted in increasing order.
  */
  // Navigators and temporary varibales.
  int navigator1, navigator2, temporary;
  // Navigate through the arraay.
  for(navigator1 = 1; navigator1 < length; navigator1++) {
    // Set the navigator 2 to navigator1 - 1.
    navigator2 = navigator1 - 1;
    // Set temporary variable.
    temporary = values[navigator1];
    // Push the element to front till it is at an appropriate position.
    while (navigator2 > -1 && temporary < values[navigator2]) {
      values[1 + navigator2] = values[navigator2];
      navigator2--;
    }
    values[navigator2 + 1] = temporary;
  }
}

int main(int argc, char const *argv[]) {
  int values[] = {11, 13, 7, 16, 9, 24, 5, 10, 3};
  int length = 9, navigator;
  insertion(values, length);
  for(navigator = 0; navigator < length; navigator++)
    printf("%d\n", values[navigator]);
  return 0;
}
