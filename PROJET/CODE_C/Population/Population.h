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
#define LONG_POP 50
#define T_SELECT 0.1

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

//return a population made up of the individuals of less quality than the head of the population
Population lessQuality(Population pop);

//return a population made up of the individuals of more quality than the head of the population
Population moreQuality(Population pop);

//returns the concatenation of two sequences of individual
Population concat(Population pop1, Population pop2);

//returns an Individual located at a specific position of a population
Individu position(Population pop, int index);


//SPECIFIC FUNCTIONS OF THE PROBLEM

//returns a population randomly made up of Individuals
Population popRandomInit(int nbIndiv);

//return a sorted population according to the quality of each individual
Population RquickSort(Population pop);

//return a population made up of the T_SELECT best individuals
Population popSelection(Population pop);

//return a population from the random crossing of an other population
Population popCrossing(Population pop);



//DEFINITION OF GETTERS AND ACCESS FUNCTIONS

//empty test to know if a population is null or not
Bool isNull(Population p);

//display all the individual of a population
void displayPop(Population pop);


#endif //POPULATION_H