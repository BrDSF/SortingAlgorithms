
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

void quickSort(int *, int);
void sort(int *, int, int);

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

  quickSort(p, size);
  for (int i = 0; i < size; i++)
  {
    printf("Ordenated, position(%d) : %d\n", i + 1, p[i]);
  }
  free(p);

  return 0;
}

void quickSort(int *v, int vetSize)
{
  sort(v, 0, vetSize - 1);
}
void sort(int *item, int left, int right)
{
  int i, j;
  int x, y;
  i = left;
  j = right;
  x = item[(left + right) / 2];
  do
  {
    while (item[i] < x && i < right)
      i++;
    while (x < item[j] && j > left)
      j--;
    if (i <= j)
    {
      y = item[i];
      item[i] = item[j];
      item[j] = y;
      i++;
      j--;
    }
  } while (i <= j);
  if (left < j)
    sort(item, left, j);
  if (i < right)
    sort(item, i, right);
}