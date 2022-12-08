/**
 * @name NANMEGNI_NGASSAM
 * @date 07/11/2022
 * @file main.c
 * @brief Use of abstract data type Individual and Population for some optimization's problems 
 */
#include<stdio.h>
#include<stdlib.h>
#include"Individu/Individu.h"
#include"Population/Population.h"

void display(Individu indiv)
{
  
  Individu current = indiv;
  printf("Bit : ");
  while (current != NULL)
  {
    printf("%d ", (current->bitValue));
    current = current->nextBit;
  }
  printf(" (%d) ", RtoDecimal(indiv));
  printf(" | (%f)\n", quality(indiv));
}

void show(Population pop)
{
  int d = 1;
  Population current = pop;
  printf("Population :\n");
  while (current != NULL)
  {
    printf("%d ", d);
    d++;
    display(current->indiv);
    current = current->nextIndiv;
  }
}

int main()
{
  srand(time(NULL));

  Population nanmegni = popRandomInit(lONG_POP);
  Population nanmegnisort = RquickSort(nanmegni);

  Population pavel = crossing(nanmegnisort);
  show(pavel);
  printf("\n");

  return (0);
}

