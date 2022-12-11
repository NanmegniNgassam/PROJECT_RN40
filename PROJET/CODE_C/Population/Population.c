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

//returns the concatenation of two sequences of individual
Population concat(Population pop1, Population pop2)
{
  if (isNull(pop1))
  {
    return pop2;
  }
  else if (isNull(pop2))
  {
    return pop1;
  }
  else
  {
    Population current = pop1;
    while ((current->nextIndiv) != NULL)
    {
      current = current->nextIndiv;
    }
    current->nextIndiv = pop2;

    return pop1;
  }
}

//return a population made up of the individuals of less quality than the head of the population
//(Even those with the same quality will be added to the list)
Population lessQuality(Population pop)
{
  if (isNull(pop))
  {
    return pop;
  }
  else
  {
    Population res = NULL;
    Population current = pop ->nextIndiv; // Le programme commencera au deuxième Individu de la population
    while (current != NULL)
    {
      if (quality(current->indiv) <= quality(pop->indiv))
      {
        res = insertHead(res, current->indiv);
      }
      current = current->nextIndiv;
    }
    return res;
  }
}

//return a population made up of the individuals of more quality than the head of the population
Population moreQuality(Population pop)
{
  if (isNull(pop))
  {
    return pop;
  }
  else
  {
    Population res = NULL;
    Population current = pop ->nextIndiv; // Le programme commencera au deuxième Individu de la population
    while (current != NULL)
    {
      if (quality(current->indiv) > quality(pop->indiv))
      {
        res = insertHead(res, current->indiv);
      }
      current = current->nextIndiv;
    }
    return res;
  }
}

//returns an Individual located at a specific position of a population
Individu position(Population pop, int index)
{
  if(index > lONG_POP) // GESTION DES EXCEPTIONS
  {
    printf("Veuillez renseigner une position comprise entre 0 et %d\n", lONG_POP);
    return NULL;
  }
  else if(isNull(pop))
  {
    printf("Veuillez entrez un tableau non vide\n");
    return NULL;
  }
  else
  {
    int i = 1;
    Population current = pop;
    /*Parcours  du premier bit jusqu'a l'indice visé*/
    while (i < index) 
    {
      current = current->nextIndiv;
      i++;
    }
    return (current->indiv);
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

//return a sorted population according to the quality of each individual
Population RquickSort(Population pop)
{
  if (isNull(pop) || isNull(pop->nextIndiv))
  {
    return pop; // An empty population or with only one individual is considered to be sorted
  }
  else
  {
    return concat(insertTail(RquickSort(moreQuality(pop)), pop->indiv), RquickSort(lessQuality(pop)));
  } 
}

//return a population made up of the T_SELECT best individuals
Population popSelection(Population pop)
{
  int i = 0;
  int last = T_SELECT*lONG_POP; // Les tselect% meilleurs individus
  Population popSorted = RquickSort(pop);
  Population popSelected = NULL;


  while (i < lONG_POP)
  {
    // On selectionne un individu à la position voulu dans la population trié et on la place dans la nouvelle population
    Individu selectedIndividual = position(popSorted, (i%last + 1));
    popSelected = insertTail(popSelected, selectedIndividual);
    i++;
  }
  
  return popSelected;
}

//return a population from the random crossing of an other population
Population popCrossing(Population pop)
{
  Population newPop = NULL;
  for (int i = 0; i < lONG_POP; i++)
  {
    //Tirage de deux individus choisi de manière purement aléatoire dans la population donné
    Individu indiv1 = position(pop, rand()%lONG_POP + 1);
    Individu indiv2 = position(pop, rand()%lONG_POP + 1);
    Individu child = RIndivCrossing(indiv1, indiv2);

    newPop = insertTail(newPop, child);
  }
  
  return newPop;
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

//display all the individual of a population
void displayPop(Population pop)
{
  int d = 1;
  Population current = pop;
  printf("Population :\n");
  while (current != NULL)
  {
    printf("%d_", d);
    displayIndiv(current->indiv);
    current = current->nextIndiv;
    d++;
  }
}