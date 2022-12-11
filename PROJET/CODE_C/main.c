/**
 * @name NANMEGNI_NGASSAM
 * @date 07/11/2022
 * @file main.c
 * @brief Use of abstract data type Individual and Population for some optimization's problems 
 */
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"Individu/Individu.h"
#include"Population/Population.h"
#define N_GEN 200

int main()
{
  srand(time(NULL));

  Population p1 = popRandomInit(lONG_POP);
  for (int i = 0; i < N_GEN; i++)
  {
    p1 = popCrossing(p1);
    p1 = RquickSort(p1);
    p1 = popSelection(p1);
  }
  displayIndiv(p1->indiv);

  return (0);
}

