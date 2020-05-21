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
}

void print_array (int *arr, int start, int stop) {
  int i;
  for (i=start; i<stop; i++) {
    printf("%d\n", arr[i]);
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
    merge_sort(set, p, q);
    merge_sort(set, q+1, r);
    merge(set, p, q, r);
  }
}

int* read_set (char* filename, int *size) {
  
  FILE *fptr = fopen(filename, "r"); // pointer to file
  int* set = malloc(*size * sizeof(int)); // array containing values to be sorted
  int n=0; // amount of values
  char line[10]; // line buffer
  while(fgets(line, sizeof line, fptr) != NULL) {
    if (n == *size) {
      *size *= 2;
      set = realloc(set, 2 * n * sizeof(int));
    }
    set[n] = atoi(line);
    n++;
  }
  *size = n;
  //realloc(set, n * sizeof(int));
  return set;
}
int main (int argc, char* argv[]) {
  if (argc < 2) {
    printf("Usage: ./sort <filename>");
    return -1;
  }
  char *filename = argv[1];
  int set_size = 2;
  int* set = read_set(filename, &set_size);
  merge_sort(set, 0, set_size-1);
  print_array(set, 0, set_size);
}