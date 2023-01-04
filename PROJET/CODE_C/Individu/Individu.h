/**
 * @name NANMEGNI_NGASSAM
 * @date 15/12/2022
 * @file Individu.h
 * @brief Definition du type abstrait Individu
 */

#ifndef INDIVIDU_H
#define INDIVIDU_H
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include "../Others/Autres.h"
#define LONG_INDIV 8
#define A -1
#define B 1
#define P_CROSSING 0.6

// DEFINTION DU TYPE BIT
typedef unsigned char Bit;

typedef struct bit_individu
{
  Bit bitValue;
  struct bit_individu* nextBit;
}BitIndividu;

/**
 * @brief Définition du type Individu en tant qu'une liste chainée de bits
*/
typedef BitIndividu *Individu;


//DECLARATION DES FONCTIONS DE CONSTRUCTION (Primitives)

//ajouter un bit en début d'un individu
Individu addHead(Individu i, Bit b);

//ajouter un bit en queue d'un individu
Individu addTail(Individu i, Bit b);

//supprimer un bit en tête d'un individu
Individu deleteHead(Individu i);

//supprimer un bit à la fin d'un individu
Individu deleteTail(Individu i);

//retourne l'individu passé en paramètre privé de son premier element
Individu remain(Individu i);


//DECLARATION DES OBSERVATEURS ET DES FONCTIONS D'ACCES

//vérifie si un individu i est vide
Bool isEmpty(Individu i);

//affiche les bits dont sont formés l'infividu indiv
void displayIndiv(Individu indiv);


//DECLARATION DES FONCTIONS SPECIFIQUES AU PROBLEME

//retourne un individu formé d'une séquence aléatoire de bits
Individu randomInit( int nbOfBits);

//retourne un individu formé d'une séquence aléatoire de nbOfBits bits -- récursive 
Individu RrandomInit( int nbOfBits);

//returns la valeur décimale associé à un individu i -- lecture de la droite vers la gauche
int RtoDecimal(Individu i);

//retourne un individu formé du croissement entre deux individus (i et j)
Individu RIndivCrossing(Individu i, Individu j);

//reourne le facteur de qualité d'un individu i
float qualityFactor(Individu i);

//retourne pour un individu i sa qualité
float quality(Individu i);


#endif // INDIVIDU_H

