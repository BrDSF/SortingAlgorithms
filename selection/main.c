#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

void selectionSort();

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

  selectionSort(p, size);

  for (int i = 0; i < size; i++)
  {
    printf("Ordenated : index(%d),  %d\n", i, p[i]);
  }

  return 0;
}

void selectionSort(int *vet, int vetSize)
{
  int index;
  int aux;
  bool flag;
  for (int i = 0; i < vetSize - 1; i++)
  {
    flag = 0;
    index = i;
    aux = vet[i];
    for (int j = i + 1; j < vetSize; j++)
    {
      if (vet[j] < aux)
      {
        index = j;
        aux = vet[j];
        flag = true;
      }
    }
    if (flag)
    {
      vet[index] = vet[i];
      vet[i] = aux;
    }
  }
}
