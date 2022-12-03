/**
 * @name NANMEGNI_NGASSAM
 * @date 07/11/2022
 * @file Population.h
 * @brief Definition and use of abstract data type Population
 */

#ifndef POPULATION_H
#define POPULATION_H
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include "../Individu/Individu.h"
#include "../Others/Autres.h"
#define lONG_POP 20

/*
  Definition of an individual part of a population
*/
typedef struct member
{
  Individu indiv;
  struct member* nextIndiv;
}Member;

/*
  Definition of a population as a sequence of individuals
*/
typedef Member *Population;


//DECLARATION OF CONSTRUCTORS

//insert an Individual to the start of a sequence of Individuals (Population)
Population insertHead(Population p, Individu i);

//insert an Individual to the end of a sequence of Individuals (Population)
Population insertTail(Population p, Individu i);

//remove an Individual to the start of a sequence of Individuals (Population)
Population removeHead(Population p);

//remove an Individual to the end of a sequence of Individuals (Population)
Population removeTail(Population p);

//return a sequence of Individuals private from its first individual
Population left(Population p);

//SPECIFIC FUNCTIONS TO THE PROBLEM

//returns a population randomly made up of Individuals
Population popRandomInit(int nbIndiv);


//DEFINITION OF GETTERS AND ACCESS FUNCTIONS

//emptytest to know if an individual is null or not
Bool isNull(Population p);


#endif //POPULATION_H