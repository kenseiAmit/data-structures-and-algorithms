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

void shell_sort(int values[], int length) {
  /*
  The method sorts a givne array in increasing order.
  */
  // Navigator and temporary variables.
  int gap, navigator1, navigator2, temporary;
  // Navigate through the array.
  for(gap = length/2; gap >= 1; gap /= 2) {
    // Navigate through the sub-array.
    for(navigator1 = gap; navigator1 < length; navigator1++) {
      // Set the temporary variale.
      temporary = values[navigator1];
      //
      navigator2 = navigator1 - gap;
      while(navigator2 >= 0 && values[navigator2] > temporary) {
        values[navigator2 + gap] = values[navigator2];
        navigator2 = navigator2 - gap;
      }
      values[navigator2 + gap] = temporary;
    }
  }
}

int main(int argc, char const *argv[]) {
    int values[] = {11, 13, 7, 12, 16, 9, 24, 5, 10, 3};
    int navigator, length = 10;
    shell_sort(values, 10);
    for(navigator = 0; navigator < length; navigator++)
      printf("%d\n", values[navigator]);
  return 0;
}
