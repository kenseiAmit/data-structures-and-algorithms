
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

void selection_sort(int values [], int length) {
  /*
  The function sorts an array in increasing order.
  */
  // Navigator and index variable.
  int navigator1, navigator2, index;
  // Navigate through the array.
  for( navigator1 = 0; navigator1 < length - 1; navigator1++) {
    // Navigate through the sub-array.
    for(navigator2 = index = navigator1; navigator2 < length; navigator2++) {
      // If values are not in right order, store the index.
      if(values[navigator2] < values[index])
            index = navigator2;
    }
    // Swap the variables.
    swap(&values[navigator1], &values[index]);
  }
}

int main(int argc, char const *argv[]) {
  int values[] = {11, 13, 7, 12, 16, 9, 24, 5, 10, 3};
  int length = 10, navigator;

  selection_sort(values, length);

  for(navigator = 0; navigator < length; navigator++)
    printf("%d\n", values[navigator]);
  return 0;
}
