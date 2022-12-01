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

int main()
{
  srand(time(NULL));
  Individu gilles = RrandomInit(lONG_INDIV);
  Individu current = gilles;
  while (current != NULL)
  {
    printf("%d ", (current->bitValue));
    current = current->nextBit;
  }

  printf("\nLa valeur decimale de gilles est %d ", RtoDecimal(gilles));
  printf("\n la qualite associe à gilles est de %f.", quality(gilles));

  return (0);
}