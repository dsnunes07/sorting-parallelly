#include <stdio.h>
#include <stdlib.h>

void merge (int* set, int p, int q, int r) {
  int left_array_size = q - p + 2;
  int right_array_size = r - q + 1;
  int *left = malloc(left_array_size * sizeof(int));
  int *right = malloc(right_array_size * sizeof(int));
  int i = 0;
  for (i=0; i < left_array_size - 1; i++) {
    left[i] = set[p + i];
  }
  for (i=0; i < right_array_size - 1; i++) {
    right[i] = set[q + i + 1];
  }
  left[left_array_size - 1] = __INT_MAX__;
  right[right_array_size - 1] = __INT_MAX__;
  int left_index = 0;
  int right_index = 0;
  for (i = p; i <= r; i++) {
    if (left[left_index] <= right[right_index]) {
      set[i] = left[left_index];
      left_index++;
    } else {
      set[i] = right[right_index];
      right_index++;
    }
  }
  print_array(set, p, r+1);
}

void print_array (int *arr, int start, int stop) {
  int i;
  for (i=start; i<stop; i++) {
    printf("arr[%d]: %d\n", i, arr[i]);
  }
}

/*
* In: 
*   set: array of integers
*   p: start index
*   r: end index
*
*   Sorts array 'set' in ascending order
*/
void merge_sort(int* set, int p, int r) {
  if (p < r) {
    int q = (p + r)/2;
    printf("p: %d q: %d r: %d\n", p, q, r);
    merge_sort(set, p, q);
    merge_sort(set, q+1, r);
    merge(set, p, q, r);
  }
}
int main (int argc, char* argv[]) {
  int arr[18] = {7, 23, 1, 3, 9, 1, 21, 88, 32, 90, 34, 56, 1, 32, 11233, 332, 9, 2};
  merge_sort(arr, 0, 17);
  print_array(arr, 0, 18);
}