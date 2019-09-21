# include <stdio.h>
# include <stdlib.h>

void swap(int *first, int *second) {
  /*
  The fucntion swaps two integers in-palce.
  */
  // Store the first varibale in a temporary varibale.
  int temporary = *first;
  // Assing the value of first to second.
  *first = *second;
  // Assing the value of temporary to second.
  *second = temporary;
}

void merge(int values[], int length, int mid, int end) {
  /*
  The method returs an array sorted in increasing order.
  */
  //
}
