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
#define lONG_INDIV 8
#define A -1
#define B 1
#define P_CROSSING 0.6

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

//add a bit to the start of a sequence of bits (Individual)
Individu addHead(Individu i, Bit b);

//add a bit to the end of a sequence of bits (Individual)
Individu addTail(Individu i, Bit b);

//delete a bit to the start of a sequence of bits (Individual)
Individu deleteHead(Individu i);

//delete a bit to the end of a sequence of bits (Individual)
Individu deleteTail(Individu i);

//return a sequence of bits private from its first bit
Individu remain(Individu i);


//return an Individual with random bits in its sequence
Individu randomInit( int nbOfBits);

//return recursively an Individual with random bits in its sequence
Individu RrandomInit( int nbOfBits);

//return an individual issued from a random mixing of two individuals
Individu Rcrossing(Individu i, Individu j);

//DECLARATION OF GETTERS AND ACCESS FUNCTION

//emptytest to know if an individual is null or not
Bool isEmpty(Individu i);

//returns from an Individual, the decimal value associated to its binary sequence
int RtoDecimal(Individu i);

//returns from an individual its quality_factor
float qualityFactor(Individu i);

//returns from an indivdual, its quality
float quality(Individu i);



#endif // INDIVIDU_H

