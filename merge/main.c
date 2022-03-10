#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

void merge(int, int, int, int *);
void mergesort(int, int, int *);

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

  mergesort(0, size, p);
  for (int i = 0; i < size; i++)
  {
    printf("Ordenated : index(%d),  %d\n", i, p[i]);
  }

  free(p);

  return 0;
}

void merge(int first, int meio, int last, int *v)
{
  int i, j, k, *w;
  w = malloc((last - first) * sizeof(int));
  i = first;
  j = meio;
  k = 0;
  while (i < meio && j < last)
  {
    if (v[i] <= v[j])
      w[k++] = v[i++];
    else
      w[k++] = v[j++];
  }
  while (i < meio)
    w[k++] = v[i++];
  while (j < last)
    w[k++] = v[j++];
  for (i = first; i < last; ++i)
    v[i] = w[i - first];
  free(w);
}

void mergesort(int first, int last, int *v)
{
  if (first < last - 1)
  {
    int meio = (first + last) / 2;
    mergesort(first, meio, v);
    mergesort(meio, last, v);
    merge(first, meio, last, v);
  }
}
