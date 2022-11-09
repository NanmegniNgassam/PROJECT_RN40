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
#define longIndiv 8
#define A -1
#define B 1

typedef unsigned char Bit;

typedef struct bit_individu
{
  Bit bitValue;
  struct bit_individu* next;
}BitIndividu;

/**
 * @brief Definition of Individual as a sequence of bits
*/
typedef BitIndividu *Individu;



#endif // INDIVIDU_H

