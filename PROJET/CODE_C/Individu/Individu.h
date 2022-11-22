/**
 * @name NANMEGNI_NGASSAM
 * @date 07/11/2022
 * @file Individu.h
 * @brief Definition and use of abstract data type Individual
 */

#ifndef INDIVIDU_H
#define INDIVIDU_H
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include "../Others/Autres.h"
#define longIndiv 8
#define A -1
#define B 1

typedef unsigned char Bit;

typedef struct bit_individu
{
  Bit bitValue;
  struct bit_individu* nextBit;
}BitIndividu;

/**
 * @brief Definition of Individual as a sequence of bits
*/
typedef BitIndividu *Individu;


//DECLARATION OF CONSTRUCTORS




//DECLARATION OF GETTERS AND ACCESS FUNCTION

//emptytest to know if an individual is null or not
Bool isEmpty(Individu i);

//Returns from an Individual, the decimal value associated to its binary sequence
int RtoDecimal(Individu i);




#endif // INDIVIDU_H

