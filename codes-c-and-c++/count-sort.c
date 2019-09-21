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

int find_max(int values[], int length) {
  /*
  The function returs the maximum element in an array.
  */
  // Setting a minimum value.
  int max = values[0];
  int navigator;
  for(navigator = 0; navigator < length; navigator++)
    if(values[navigator] > max)
      max = values[navigator];
  return max;
}

void count_sort(int values[], int length) {
  /*
  The function returns a array sorted in increasing order.
  */
  // Nvigator and maximum variables.
  int navigator1, navigator2, max, *this;
  // Find the maximum in the array.
  max = find_max(values, length);
  // Allocate memory using pointer.
  this = (int *)malloc(sizeof(int)*(max + 1));
  // Navigate through the newly created array and set all elements to 0.
  for(navigator1 = 0; navigator1 < max + 1; navigator1++)
    this[navigator1] = 0;
  // Navigate through the new array and set the value counts.
  for(navigator1 = 0; navigator1 < length; navigator1++)
    this[values[navigator1]]++;
  // Set anvigators to 0.
  navigator1 = navigator2 = 0;
  // Store the sorted array in the unsorted array.
  while (navigator2 < max + 1) {
    if(this[navigator2] > 0) {
      values[navigator1++] = navigator2;
      this[navigator2]--;
    }
    else
      navigator2++;
  }
}

int main(int argc, char const *argv[]) {
  int values[] = {11, 13, 7, 12, 16, 9, 24, 5, 10, 3};
  int length = 10, navigator;
  count_sort(values, length);
  for(navigator =0; navigator < length; navigator++)
    printf("%d\n", values[navigator]);
  return 0;
}
