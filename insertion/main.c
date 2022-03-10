#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void insertionSort(int *vet, int vetSize);

int main(void)
{

  int size;

  printf("Type the size of the array: ");
  scanf("%d", &size);

  int *p = (int *)malloc(size * sizeof(int));
  srand(time(NULL));
  for (int i = 0; i < size; i++)
  {
    p[i] = rand() % 1000;
  }

  insertionSort(p, size);
  for (int i = 0; i < size; i++)
  {
    printf("Ordenated : %d\n", p[i]);
  }

  free(p);

  return 0;
}

void insertionSort(int *vet, int vetSize)
{
  int aux;
  int j;
  for (int i = 1; i < vetSize; i++)
  {
    aux = vet[i];
    for (j = i - 1; j >= 0 && aux < vet[j]; j--)
      vet[j + 1] = vet[j];
    vet[j + 1] = aux;
  }
};
