#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
  int i, *vetor = (int*) malloc(8 * sizeof(int));
  for (i = 0; i < 10; i++)
    scanf("%d", &vetor[i]);
  for (i = 9; i >= 0; i--)
    printf("%d\n", vetor[i]);
  free(vetor);
  return 0;
}
