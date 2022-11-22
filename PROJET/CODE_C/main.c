/**
 * @name NANMEGNI_NGASSAM
 * @date 07/11/2022
 * @file main.c
 * @brief Use of abstract data type Individual and Population for some optimization's problems 
 */
#include<stdio.h>
#include<stdlib.h>
#include"Individu/Individu.h"
#include"Population/Population.h"

int main()
{
  Individu g1;
  g1 = (BitIndividu*)malloc(sizeof(BitIndividu));

  Individu g2;
  g2 = (BitIndividu*)malloc(sizeof(BitIndividu));
   
  g1 ->bitValue = 0;
  g1 ->nextBit = g2; 
  g2 ->bitValue = 1;
  g2 ->nextBit = NULL;

  Individu gilles = g1;
  printf("La valeur decimale de gilles est %d \n" , RtoDecimal(gilles));


  for (int i = 0; i < 1000; i++)
  {
    Bit received = aleaBinVal();
    printf("The random value received is : %d \n", received);
  }
  
  return (0);
}