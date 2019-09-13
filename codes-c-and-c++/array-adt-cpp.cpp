/*
This is the coding practice file for Udemy course "Mastering Data ...
Structure and Algorithms using C and C++. This file is for the Section 7 of ...
the course "Arrays as Abstract Data Types".
*/

# include <stdio.h>
# include <iostream>
# include <stdlib.h>
using namespace std;

class array {
  /* Class containing array data, attributes, and methods.*/
  // Private members of the class.
private:
  // Array data element.
  int *a;
  // Number of elements present in array.
  int length;
  // Array size, which is an upper limit.
  int size;
  // A method that swaps integers.
  void swap(int *x, int *y);

// Public memebrs of the class.
public:
   // Default constructor for the class.
   array() {
     // Set default values.
     size = 10;
     length = 0;
     // Create new array using dynamic allocation and the pointer.
     a = new int[size];
   }

   // Secondary constructor.
   array(int size) {
     // Set passed values.
     this->size = size;
     length = 0;
     // Create new array using dynamic allocation and the pointer.
     a = new int [size];
   }

   // Initializing constructor.
   array(int a[], int size, int length) {
    this->size = size;
    this->length = length;
    this->a = new int[size];
    this->a = a;
   }

   // Destructor.
   ~array() {
     delete [] a;
   }

   // Methods.
   int delete_array(int index);
   int linear_search(int key);
   int binary_search(int key);
   int get(int index);
   int max();
   int min();
   int sum();
   int is_sorted();
   int recursive_binary_search(int key, int start, int end);
   void display();
   void append(int x);
   void insert(int index, int value);
   void set(int index, int value);
   void reverse();
   void swap_reverse();
   void rearrange();
   void swap_reverse(struct array *arr);
   float average();
   array* merge(array *arr);
   array* union_array(array *arr);
   array* difference(array *arr);
   array* intersection(array *arr);

};

void array::display() {
  /* The method displays all the elements in an array.*/

  // A tracke variable to navigate the array.
  int i;
  printf("The array is as folows: \n");
  for( i = 0; i < length; i++)
    printf("%d\n", a[i]);
}

void array::append(int element) {
  /* The method appends an element to an array. */

  // If array is full, an elemen cannot be appended.
  if(length >= size)
    printf("The arrray is full. Cannot append the elemet\n");
  else
  // Element is inserted at the end of array.
    a[length++] = element;
}

void array::insert(int index, int element) {
  /* The method inserts an element at a specified position of array. */

  // A tracker variable to navigate an array.
  int i = length;
  // If the array is full, an element cannot be inserted without removing ...
  // another element.
  if(length >= size)
    printf("The array is full. Cannot insert the element without replacing\n");
  // An element can be inseted only inside an array.
  else if(-1 < index && index < length ) {
    // Shift elements to the right to make space for insetion.
    while(i-- >= index)
      a[i+1] = a[i];
    a[i+1] = element;
    length++;
  }
  else
      printf("Please enter a valid location\n");
  // Insert the element at the specified locaiton.
}

int array::delete_array(int index) {
  /* The method delets an elemet at specified position and returs the ...
  element. */

  // Array is empty.
  if(length == 0) {
    printf("The array is empty.\n");
    return 0;
  }
  // Only an element from a position inside array.
  else if(index < 0 || index > (length - 1)) {
    printf("Enter a valid index.\n");
    return 0;
  }
  else {
    // A tracker variable to traverse the array.
    int i, element;
    element = a[index];
    // Shift every element to the right to left.
    for(i = index; i < (length - 1);)
      a[i] = a[i++];
  // Decrease the array lenggth
  length--;
  // Return the element that was deleted
  return element;
 }
}

void array::swap(int *x, int *y) {
  /* The method swaps given integers. */

  int temp = *x;
  *x = *y;
  *y = temp;
}

int array::is_sorted() {
  int i;
  for(i = 0; i < (length -1); i++)
    if(a[i] > a[i + 1])
      return 0;
  return 1;
}

int array::linear_search(int key) {
  /* The method returns the location of the key if found. */

  // A tracker variable to navigate the array.
  int i;
  // Check if key is present in the array.
  for(i = 0; i < length; i++)
    if(key == a[i]) {
      // Move the key to the front.
      swap(&a[0], &a[i]);
      // Return the location of the key.
      return i;
    }
  return -1;
}

int array::binary_search(int key) {
  /* The method returns the locaiton of key  in a sorted array increasing ...
  order if found. */

  // Tracker variables to navigate the array during search.
  int start, mid, end;
  start = 0;
  end = length - 1;
  // Look into the array for the key till start is smaller than end.
  while(start <= end) {
    // Setting the mid varibale to half of the array.
    mid = (start + end)/2;
    // If the middle element is bigger than the key, set end to mid + 1.
    if(a[mid] > key)
      end = mid - 1;
    // If the middle elemen is smaller than the key, set start to mid - 1.
    else if(a[mid] < key)
      start = mid + 1;
    // Return the locaiotn of key if found.
    else
      return mid;
  }
  // Return -1 if key not found.
  return -1;
}

int array::recursive_binary_search(int key, int start, int end) {
  /* The method returns the index of key in an sorted array in increasing ...
  order if found. */

  // Check if start is smaller than end.
  if(start <= end)
    // If the midde elemnt is bigger than the key, set end to mid-1.
    if(a[(start + end)/2] > key)
      return recursive_binary_search(key, start, ((start + end)/2 -1));
    // If the middle element is smaler than the key, set the start to mid+1.
    else if(a[(start + end)/2] < key)
      return recursive_binary_search(key, ((start + end)/2 + 1), end);
    // The key is found.
    else
      return (start + end)/2;
  // Key is not found, return -1.
  else
    return -1;
}

int array::get(int index) {
  /* The method returns the value at the index. */

  // The index should be in the array.
  if((index > -1) && (index < length))
    return a[index];
  // Return -1 if the index doesnot exit in the array.
  return -1;
}

void array::set(int index, int value) {
  /* The method changes the value at the index to key. */

  // Check if the index exists in the array.
  if((index > -1) && (index < length))
    a[index] = value;
  else
    printf("Invalid index.");
}

int array::max() {
  /* The method returns the maximum value in the array. */

  // A tracekr variable to navigate the array.
  int i;
  // A tracker variable to track the maximum.
  int max = a[0];
  for(i = 1; i < length; i++)
    if(a[i] > max)
      max = a[i];
  // Return the maximum.
  return max;
}

int array::min() {
  /* The method returns the minmum value in the array. */

  // A tarcker variable to navigate the arary.
  int i;
  // A tracker variable to keep track of the minimum value.
  int min = a[0];
  for(i = 1; i < length; i++)
    if(a[i] < min)
      min = a[i];

  // Return the minimum value.
  return min;
}

int array::sum() {
  /* The method returns the sum of values in an array. */

  // Tracker variable to navigate the array and sum.
  int i, sum;
  sum = 0;
  for(i = 0; i < length; i++)
    sum += a[i];
  // Return the sum.
  return sum;
}

float array::average() {
  /* The method returns the average value of the element in array. */

  return (float)sum()/length;
}

void array::reverse() {
  /* The method reverses a given array. */

  // A tracker variable to navigate the array and a pointer to create new array.
  int i, *b;

  // Create a new array to store the reverse array.
  b = (int *)malloc(length*sizeof(int));

  // Get reverse of the array a into reverse b.
  for(i = 0; i < length; i++)
    b[i] = a[length - 1 - i];

  // Copy the reverse array to original array.
  for(i = 0; i < length; i++)
    a[i] = b[i];
  free (b);
}

void array::swap_reverse(array *arr) {
  /* The method swaps a given array. */

  // A tracker variabel to navigate the aray.
  int i;
  for(i = 0; i < length/2; i++)
    swap(&a[i], &a[length - 1 - i]);
}

array* array::merge(array *arr) {
  /* The method returns a array that is formed by merging two arrays ...
  soretd in increasing order. */

  // Tracker varibales to navigate the arary and pointer varibale to create ...
  //new arrays.
  int i, j;
  // Pointer to create a new array which will have merged vaues.
  array *b;
  i = 0;
  j = 0;

  // Create a new array element to store the mearged arrays.
  b = new array(length + arr->length);

  // Merge arrays till one of them is exhausted.
  while((i < length) && (j < arr->length))
  // Append the smaller element to the merged array.
      if(a[i] > arr->a[j])
        b->append(arr->a[j++]);
      else
          b->append(a[i++]);
  // Make sure all emements of both the arrays are inserted in the merged array.
  while(i < length)
    b->append(a[i++]);
  while(j < arr->length)
    b->append(arr->a[j++]);
  // Return merged array.
  return b;
}


array* array::union_array(array *arr) {
  /* The metod returns the union of two arrays sorted in increasing order. ...
  Although, it assumes that there are no duplicates in any array. */

  // Tracker varinables to navigate the arrays.
  int i, j;
  i = 0;
  j = 0;
  // Create a new array to hold the merged array.
  array *b = new array(length + arr->length);

  // Merge the two arrays.
  while (i < length && j < arr->length)
    if(a[i] < arr->a[j])
      b->append(a[i++]);
    else if(a[i] > arr->a[j])
      b->append(arr->a[j++]);
    else
      b->append(a[i++ -j + j++]);

  // Append the remaining element of the arrays inot merged array.
  while(i < length )
    b->append(a[i++]);
  while (j < arr->length)
    b->append(arr->a[j++]);
  // Return a pointe to the merged array.
  return b;
}

array* array::intersection(struct array * arr) {
  // The method returns the intersectio of two arrays.
  int i, j;
  i = 0;
  j = 0;

  // Create a new array to hod the intersection.
  array *b = new array(length + arr->length);

  // Find the intersection of two arrays.
  while (i < length && j < arr->length)
    if(a[i] < arr->a[j])
      i++;
    else if(a[i] > arr->a[j])
      j++;
    else
      b->append(a[i++ -j + j++]);

  // Return a pointer to the intersection of two arrays.
  return b;
}

array* array::difference(array *arr) {
  /* This method returns the difference of two arrays sorted in increasing ...
  order. Although, it doesnot take care of an element repeting in any of ...
  the array. Note that dufference is a unsymetic operation.*/

  // Variables to navigate the arrays.
  int i, j;
  i = 0;
  j = 0;

  // Create a new array for holding the intersection
  // The size of the new array is sum of the length of the two arrays.
  array *b = new array(length + arr->length);

  // Take union of the two arrys.
  while(i < length && j < arr->length) {
    printf("%d, %d\n", a[i], arr->a[i]);
    if(a[i] < arr->a[j])
      b->append(a[i++]);
    else if(a[i] > arr->a[j])
      j++;
    else{
      j++;
      i++;
    }
  }

  while(i < length)
    b->append(a[i++]);

  return b;
}

int main(int argc, char const *argv[]) {
  int a[] = {-2, 1, 17, 20};
  int b[] = {1, 5, 12, 17, 33};

  struct array arr(a, 10, 4);
  struct array arry(b, 10, 5);


  arr.difference(&arry)->display();
  return 0;
}
