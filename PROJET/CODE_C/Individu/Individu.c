/**
 * @name NANMEGNI_NGASSAM
 * @date 07/11/2022
 * @file Individu.c
 * @brief Method's implementation of the abstract data type Individual
 */
#include"Individu.h"

//IMPLEMENTATION DES CONSTRUCTEURS

//add a bit to the start of a sequence of bits (Individual)
Individu addHead(Individu i, Bit b)
{
  BitIndividu *temp;
  temp = (BitIndividu*)malloc(sizeof(BitIndividu));

  temp ->bitValue = b;
  temp ->nextBit = i;
  return temp;
}

//add a bit to the end of a sequence of bits (Individual)
Individu addTail(Individu i, Bit b)
{
  BitIndividu *temp;
  temp = (BitIndividu*)malloc(sizeof(BitIndividu));
  temp ->bitValue = b;
  temp ->nextBit = NULL;

  if( isEmpty(i))
  {
    return temp;
  }
  else
  {
    Individu current = i;
    while ((current ->nextBit) != NULL)
    {
      current = current ->nextBit;
    }

    current ->nextBit = temp;
    return i;
  }
  
}

//delete a bit to the start of a sequence of bits (Individual)
Individu deleteHead(Individu i)
{
  if(isEmpty(i))
  {
    return i;
  }
  else
  {
    BitIndividu *temp;
    temp = i;
    i = i->nextBit;
    free(temp);
    temp = NULL;
    return i;
  }
}

//delete a bit to the end of a sequence of bits (Individual)
Individu deleteTail(Individu i)
{
  if (isEmpty(i) || isEmpty(i->nextBit))
  {
    return NULL;
  }
  else
  {
    BitIndividu *current;
    current = i;
    while (((current->nextBit)->nextBit) != NULL)
    {
      current = current ->nextBit;
    }
  
    free(current->nextBit);
    current ->nextBit = NULL;
    return i;
  } 
}

//return a sequence of bits private from its first bit
Individu remain(Individu i)
{
  if (isEmpty(i))
  {
    return i;
  }
  else
  {
    return i->nextBit;
  }
}

//return recursively an Individual with random bits in its sequence
Individu RrandomInit( int nbOfBits)
{
  if(nbOfBits == 1)
  {
    return addHead(NULL, aleaBinVal());
  }
  else
  {
    return addHead(RrandomInit(nbOfBits - 1), aleaBinVal());
  }
}

//return an Individual with random bits in its sequence
Individu randomInit( int nbOfBits)
{
  int turn = nbOfBits;
  Individu indiv;
  while (turn >= 1)
  {
    indiv = addHead(indiv, aleaBinVal());
    turn--;
  }
  return indiv;
}


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

//Returns from an indivdual, its quality -- f(x) = -X^2 // X = (value / 2^LONG_INDIV)*(B-A) + A
float quality(Individu i)
{
  int value = RtoDecimal(i);
  float temp = value/(power(2,lONG_INDIV));
  temp = temp*(B-A);
  temp = temp + A; //(value / 2^LONG_INDIV)*(B-A) + A

  return -power(temp,2); //f(x) = -X^2
}