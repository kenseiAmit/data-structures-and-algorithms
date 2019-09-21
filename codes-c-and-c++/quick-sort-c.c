
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

int partition(int values[], int begning, int end) {
  /*
  This fucntion partitions an array.
  */
  // The pivot element to pration the array by.
  int pivot = values[begning];
  // Navigator variables.
  int navigator1 = begning, navigator2 = end;
  do {
    //
    do { navigator1++; }while(values[navigator1] <= pivot);
    do { navigator2++; }while(values[navigator2] >  pivot);

    if(navigator1 < navigator2)
      swap(&values[navigator1], &values[navigator2]);
  }while(navigator1 < navigator2);

  swap(&values[begning], &values[navigator2]);

  return navigator2;
}

void quick_sort(int values[], int begning, int end) {
  int navigator;
  if(begning < end) {
    navigator = partition(values, begning, end);
    quick_sort(values, begning, end);
    quick_sort(values, navigator + 1, end);
  }
}

int main(int argc, char const *argv[]) {
  int values[] = {11, 13, 7, 12, 16, 9, 24, 5, 10, 3};
  int length = 10, navigator;
  quick_sort(values, length, 0);
  for(navigator =0; navigator < length; navigator++)
    printf("%d\n", values[navigator]);
  return 0;
}
