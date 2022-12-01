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

  Individu gilles = randomInit(lONG_INDIV);
  Individu current = gilles;
  printf("Parent : ");
  while (current != NULL)
  {
    printf("%d ", (current->bitValue));
    current = current->nextBit;
  }
  printf(" (%d) ", RtoDecimal(gilles));
  printf(" | (%f)\n", quality(gilles));
  

  Individu pavel = RrandomInit(lONG_INDIV);
  current = pavel;
  printf("Parent : ");
  while (current != NULL)
  {
    printf("%d ", (current->bitValue));
    current = current->nextBit;
  }
  printf(" (%d) ", RtoDecimal(pavel));
  printf(" | (%f)\n", quality(pavel));


  printf("The individual issued from the two with a probability of %f is:\n", P_CROSSING*100);
  Individu ngassam = Rcrossing(gilles, pavel);
  current = ngassam;
  printf("Child  : ");
  while (current != NULL)
  {
    printf("%d ", (current->bitValue));
    current = current->nextBit;
  }
  printf(" (%d) ", RtoDecimal(ngassam));
  printf(" | (%f)\n", quality(ngassam));


  printf("\n");

  return (0);
}

