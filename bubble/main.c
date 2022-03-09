#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

void bubbleSort(int *, int);
void swap(int *, int *);

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
    printf("Ordenated, position(%d) : %d\n", i + 1, p[i]);
  }

  return 0;
}

void bubbleSort(int *vet, int vetSize)
{
  int last = vetSize;
  int position = vetSize;
  bool change = true;
  while (change)
  {
    change = false;
    for (int i = 0; i < last; i++)
    {
      if (vet[i] > vet[i + 1])
      {
        swap(&vet[i], &vet[i + 1]);
        change = true;
        position = i;
      }
    }
    last = position;
  }
}

void swap(int *p1, int *p2)
{
  int aux = *p1;
  *p1 = *p2;
  *p2 = aux;
}
// void bubbleSort(int *vet, int vetSize)
// {
//   char aux;
//   for (int i = 1; i < vetSize - 1; i++)
//   {
//     for (int j = vetSize - 1; j >= i; j--)
//     {
//       if (vet[j - 1] > vet[j])
//       {
//         aux = vet[j - 1];
//         vet[j - 1] = vet[j];
//         vet[j] = aux;
//       }
//     }
//   }
// }