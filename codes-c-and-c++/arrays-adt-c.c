/* This is the coding practice file for Udemy course "Mastering Data ...
Structure and Algorithms using C and C++. This file is for the Section 7 of ...
the course "Arrays as Abstract Data Types". */

# include <stdio.h>
// Remember that iostream is not available in C.
//# include <iostream.h>
# include <stdlib.h>

struct array {
  /* Structure containing array data and properties. */

  // Array data element.
  int a[10];
  // Number of elements present in array.
  int length;
  // Array size, which is an upper limit.
  int size;
};

void display(struct array arr) {
  /* The method displays all the elements in an array.*/

  // A tracke variable to navigate the array.
  int i;
  printf("The array is as folows: \n");
  for( i = 0; i < arr.length; i++)
    printf("%d\n", arr.a[i]);
}

void append(struct array *arr, int element) {
  /* The method appends an element to an array. */

  // If array is full, an elemen cannot be appended.
  if(arr->length == arr->size)
    printf("The arrray is full. Cannot append the elemet\n");
  else
  // Element is inserted at the end of array.
    arr->a[arr->length++] = element;
}

void insert(struct array *arr, int index, int element) {
  /* The method inserts an element at a specified position of array. */

  // A tracker variable to navigate an array.
  int i = arr->length;
  // If the array is full, an element cannot be inserted without removing ...
  // another element.
  if(arr->length == arr->size)
    printf("The array is full. Cannot insert the element without replacing\n");
  // An element can be inseted only inside an array.
  else if(-1 < index && index < arr->length ) {
    // Shift elements to the right to make space for insetion.
    while(i-- >= index)
      arr->a[i+1] = arr->a[i];
    arr->a[i+1] = element;
    arr->length++;
  }
  else
      printf("Please enter a valid location\n");
  // Insert the element at the specified locaiton.
}

int delele_array(struct array *arr, int index) {
  /* The method delets an elemet at specified position and returs the ...
  element. */

  // Array is empty.
  if(arr->length == 0) {
    printf("The array is empty.\n");
    return 0;
  }
  // Only an element from a position inside array.
  else if(index < 0 || index > (arr->length - 1)) {
    printf("Enter a valid index.\n");
    return 0;
  }
  else {
    // A tracker variable to traverse the array.
    int i, element;
    element = arr->a[index];
    // Shift every element to the right to left.
    for(i = index; (i < arr->length - 1);)
      arr->a[i] = arr->a[i++];
  // Decrease the array lenggth
  arr->length--;
  // Return the element that was deleted
  return element;
 }
  return 0;
}

void swap(int *x, int *y) {
  /* The method swaps given integers. */

  int temp = *x;
  *x = *y;
  *y = temp;
}

int is_sorted(struct array *arr) {
  int i;
  for(i = 0; i < (arr->length -1); i++)
    if(arr->a[i] > arr->a[i + 1])
      return 0;
  return 1;
}


int linear_search(struct array *arr, int key) {
  /* The method returns the location of the key if found. */

  // A tracker variable to navigate the array.
  int i;
  // Check if key is present in the array.
  for(i = 0; i < arr->length; i++)
    if(key == arr->a[i]) {
      // Move the key to the front.
      swap(&arr->a[0], &arr->a[i]);
      // Return the location of the key.
      return i;
    }
  return -1;
}

int binary_search(struct array *arr, int key) {
  /* The method returns the locaiton of key  in a sorted array increasing ...
  order if found. */

  printf("Binary search in progress\n");

  // Tracker variables to navigate the array during search.
  int start, mid, end;
  start = 0;
  end = arr->length - 1;
  // Look into the array for the key till start is smaller than end.
  while(start <= end) {
    // Setting the mid varibale to half of the array.
    mid = (start + end)/2;
    // If the middle element is bigger than the key, set end to mid + 1.
    if(arr->a[mid] > key)
      end = mid - 1;
    // If the middle elemen is smaller than the key, set start to mid - 1.
    else if(arr->a[mid] < key)
      start = mid + 1;
    // Return the locaiotn of key if found.
    else
      return mid;
  }
  // Return -1 if key not found.
  return -1;
}

int recursive_binary_search(struct array *arr, int key, int start, int end) {
  /* The method returns the index of key in an sorted array in increasing ...
  order if found. */

  // Check if start is smaller than end.
  if(start <= end)
    // If the midde elemnt is bigger than the key, set end to mid-1.
    if(arr->a[(start + end)/2] > key)
      return recursive_binary_search(arr, key, start, ((start + end)/2 -1));
    // If the middle element is smaler than the key, set the start to mid+1.
    else if(arr->a[(start + end)/2] < key)
      return recursive_binary_search(arr, key, ((start + end)/2 + 1), end);
    // The key is found.
    else
      return (start + end)/2;
  // Key is not found, return -1.
  else
    return -1;
}

int get(struct array *arr, int index) {
  /* The method returns the value at the index. */

  // The index should be in the array.
  if((index > -1) && (index < arr->length))
    return arr->a[index];
  // Return -1 if the index doesnot exit in the array.
  return -1;
}

void set(struct array *arr, int index, int value) {
  /* The method changes the value at the index to key. */

  // Check if the index exists in the array.
  if((index > -1) && (index <= arr->length)) {
    arr->a[index] = value;
    // Increase the length of the array if an element is inserted at the end.
    if (index == arr->length)
      arr->length++;
  }
  else
    printf("Invalid index.");
}

int max(struct array *arr) {
  /* The method returns the maximum value in the array. */

  // A tracekr variable to navigate the array.
  int i;
  // A tracker variable to track the maximum.
  int max = arr->a[0];
  for(i = 1; i < arr->length; i++)
    if(arr->a[i] > max)
      max = arr->a[i];
  // Return the maximum.
  return max;
}

int min(struct array *arr) {
  /* The method returns the minmum value in the array. */

  // A tarcker variable to navigate the arary.
  int i;
  // A tracker variable to keep track of the minimum value.
  int min = arr->a[0];
  for(i = 1; i < arr->length; i++) {
    if(arr->a[i] < min)
      min = arr->a[i];
  }
  // Return the minimum value.
  return min;
}

int sum(struct array *arr) {
  /* The method returns the sum of values in an array. */

  // Tracker variable to navigate the array and sum.
  int i, sum;
  sum = 0;
  for(i = 0; i < arr->length; i++)
    sum += arr->a[i];
  // Return the sum.
  return sum;
}

float average(struct array *arr) {
  /* The method returns the average value of the element in array. */

  return (float)sum(arr)/arr->length;
}

void reverse(struct array *arr) {
  /* The method reverses a given array. */

  // A tracker variable to navigate the array and a pointer to create new array.
  int i, *b;

  // Create a new array to store the reverse array.
  b = (int *)malloc(arr->length*sizeof(int));

  // Get reverse of the array a into reverse b.
  for(i = 0; i < arr->length; i++)
    b[i] = arr->a[arr->length - 1 - i];

  // Copy the reverse array to original array.
  for(i = 0; i < arr->length; i++)
    arr->a[i] = b[i];
  free (b);
}

void swap_reverse(struct array *arr) {
  /* The method swaps a given array. */

  // A tracker variabel to navigate the aray.
  int i;
  for(i = 0; i < arr->length/2; i++)
    swap(&arr->a[i], &arr->a[arr->length - 1 - i]);
}

struct array* merge(struct array *arr, struct array *arry) {
  /* The method returns a array that is formed by merging two arrays ...
  soretd in increasing order. */

  // Check if the arrays are not to large to be merged.
  if((arr->length + arry->length) < 10) {
  // Tracker varibales to navigate the arary and pointer varibale to create ...
  //new arrays.
  int i, j;
  // Pointer to create a new array which will have merged vaues.
  struct array *b;
  i = 0;
  j = 0;

  // Create a new array element to store the mearged arrays.
  b = (struct array *)malloc(sizeof(struct array));
  // Set the size of arary to 10.
  b->size = 10;
  // Merge arrays till one of them is exhausted.
  while((i < arr->length) && (j < arry->length))
  // Append the smaller element to the merged array.
      if(arr->a[i] > arry->a[j])
        append(b, arry->a[j++]);
      else
          append(b, arr->a[i++]);
  // Make sure all emements of both the arrays are inserted in the merged array.
  while(i < arr->length)
    append(b, arr->a[i++]);
  while(j < arry->length)
    append(b, arry->a[j++]);
  // Return merged array.
  return b;
  }
  else
    return NULL;
}

struct array* union_array(struct array *arr, struct array *arry) {
  /* The metod returns the union of two arrays sorted in increasing order. ...
  Although, it assumes that there are no duplicates in any array. */
  // Tracker varinables to navigate the arrays.
  int i, j;
  i = 0;
  j = 0;
  // Create a new array to hold the merged array.
  struct array *b = (struct array*)malloc(sizeof(struct array));
  // Set the size and length of the new array.
  b->size = 10;
  b->length = 0;

  // Merge the two arrays.
  while (i < arr->length && j < arry->length)
    if(arr->a[i] < arry->a[j])
      append(b, arr->a[i++]);
    else if(arr->a[i] > arry->a[j])
      append(b, arry->a[j++]);
    else
      append(b, arr->a[i++ -j + j++]);

  // Append the remaining element of the arrays inot merged array.
  while(i < arr->length )
    append(b, arr->a[i++]);
  while (j < arry->length)
    append(b, arry->a[j++]);
  // Return a pointe to the merged array.
  return b;
}
struct array* intersection(struct array * arr, struct array* arry) {
  // The method returns the intersectio of two arrays.
  int i, j;
  i = 0;
  j = 0;

  // Create a new array to hod the intersection.
  struct array *b = (struct array *)malloc(sizeof(struct array));
  b->size = 10;
  b->length = 0;

  // Find the intersection of two arrays.
  while (i < arr->length && j < arry->length)
    if(arr->a[i] < arry->a[j])
      i++;
    else if(arr->a[i] > arry->a[j])
      j++;
    else
      append(b, arr->a[i++ -j + j++]);

  // Return a pointer to the intersection of two arrays.
  return b;
}

struct array* difference(struct array *arr, struct array *arry) {
  int i, j;
  i = 0;
  j = 0;

  struct array *b = (struct array *)malloc(sizeof(struct array));
  b->size = 10;
  b->length = 0;

  while(i < arr->length && j < arry->length) {
    printf("%d, %d\n", arr->a[i], arry->a[j]);
    if(arr->a[i] < arry->a[j])
      append(b, arr->a[i++]);
    else if(arr->a[i] > arry->a[j])
      j++;
    else {
      i++;
      j++;
    }
  }
  while(i < arr->length )
    append(b, arr->a[i++]);

  return b;
}

int main(int argc, char const *argv[]) {
  struct array arr  = {{5, 16, 22, 35}, 4, 10};
  struct array arry = {{2, 5, 28, 32, 35}, 5, 10};
  display(*difference(&arry, &arr));
  return 0;
}
