/**
 * @name NANMEGNI_NGASSAM
 * @date 07/11/2022
 * @file Population.c
 * @brief Method's implementation of the abstract data type Population
 */
#include "Population.h"

//IMPLEMENTATION OF CONSTRUCTORS

//add a bit to the start of a sequence of bits (Individual)
Population insertHead(Population p, Individu i)
{
  Member *temp;
  temp = (Member*)malloc(sizeof(Member));

  temp ->indiv = i;
  temp ->nextIndiv = p;
  return temp;
}

//add an Individual to the end of a sequence of Individuals (Population)
Population insertTail(Population p, Individu i)
{
  Member *temp;
  temp = (Member*)malloc(sizeof(Member));
  temp ->indiv = i;
  temp ->nextIndiv = NULL;

  if( isNull(p))
  {
    return temp;
  }
  else
  {
    Population current = p;
    while ((current ->nextIndiv) != NULL)
    {
      current = current ->nextIndiv;
    }

    current ->nextIndiv = temp;
    return p;
  }
}

//remove an Individual to the start of a sequence of Individuals (Population)
Population removeHead(Population p)
{
  if(isNull(p))
  {
    return p;
  }
  else
  {
    Member *temp;
    temp = p;
    p = p->nextIndiv;
    free(temp);
    temp = NULL;
    return p;
  }
}

//remove an Individual to the end of a sequence of Individuals (Population)
Population removeTail(Population p)
{
  if (isNull(p) || isNull(p->nextIndiv))
  {
    if(isNull(p->nextIndiv))
    {
      free(p);
      p = NULL;
    }
    return NULL;
  }
  else
  {
    Member *current;
    current = p;
    while (((current->nextIndiv)->nextIndiv) != NULL)
    {
      current = current ->nextIndiv;
    }
  
    free(current->nextIndiv);
    current ->nextIndiv = NULL;
    return p;
  } 
}

//return a sequence of Individuals private from its first individual
Population left(Population p)
{
  if(isNull(p))
  {
    return NULL;
  }
  else
  {
    return (p->nextIndiv);
  }
}


//SPECIFIC FUNCTIONS TO THE PROBLEM

//returns a population randomly made up of Individuals
Population popRandomInit(int nbIndiv)
{
  if (nbIndiv == 0)
  {
    return NULL;
  }
  else
  {
    return insertHead(popRandomInit(nbIndiv - 1), RrandomInit(lONG_INDIV));
  }
}


//IMPLEMENTATION OF GETTERS AND ACCESS FUNCTIONS

//emptytest to know if an individual is null or not
Bool isNull(Population p)
{
  if(p == NULL)
    return true;
  else
    return false;
}