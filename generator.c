#include <stdio.h>
#include <stdlib.h>

int* generate_random_values(int n, int from, int to) {
  int * random_values = malloc(n * sizeof(int));
  for(int i = 0; i < n; i++) {
    random_values[i] = rand() % (to - from + 1) + from;
  }
  return random_values;
}

void print_values(int* values, int n) {
  for (int i = 0; i < n; i++) {
    printf("%d\n", values[i]);
  }
}

int main(int argc, char *argv[]) {
  if (argc < 3) {
    printf("Usage: generator <number of values> <from> <to>");
    return -1;
  }

  int n = atoi(argv[1]);
  int from = atoi(argv[2]);
  int to = atoi(argv[3]);
  int *random_values = generate_random_values(n, from, to);
  print_values(random_values, n);
}