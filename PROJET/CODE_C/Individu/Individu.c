/**
 * @name NANMEGNI_NGASSAM
 * @date 07/11/2022
 * @file Individu.c
 * @brief Method's implementation of the abstract data type Individual
 */
#include"Individu.h"

//IMPLEMENTATION DES CONSTRUCTEURS





//IMPLEMENTATION OF GETTERS AND ACCESS FUNCTIONS

//emptytest to know if an individual is null or not
Bool isEmpty(Individu i)
{
  if(i == NULL)
    return true;
  else
    return false;
}

//Returns from an Individual, the decimal value associated to its binary sequence
int RtoDecimal(Individu i)
{
  if(isEmpty(i))
  {
    return 0;
  }
  else
  {
    return ((i->bitValue) + 2*(RtoDecimal(i->nextBit)));
  }
}