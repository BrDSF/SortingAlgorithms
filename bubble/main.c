#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void bubbleSort(int *, int);

int main(void)
{
  int size;

  printf("Type the size of the array: ");
  scanf("%d", &size);

  int *p = (int *)malloc(size * sizeof(int));
  srand(time(NULL));
  for (int i = 0; i < size; i++)
  {
    p[i] = rand() % 100;
  }

  bubbleSort(p, size);
  for (int i = 0; i < size; i++)
  {
    printf("Ordenated : %d\n", p[i]);
  }

  return 0;
}

void bubbleSort(int *vet, int vetSize)
{
  char aux;
  for (int i = 1; i < vetSize - 1; i++)
  {
    for (int j = vetSize - 1; j >= i; j--)
    {
      if (vet[j - 1] > vet[j])
      {
        aux = vet[j - 1];
        vet[j - 1] = vet[j];
        vet[j] = aux;
      }
    }
  }
}