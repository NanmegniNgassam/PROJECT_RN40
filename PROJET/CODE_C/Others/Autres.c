/**
 * @name NANMEGNI_NGASSAM
 * @date 07/11/2022
 * @file Autres.c
 * @brief Implementation of usuals functions that will be helpful for the project
 */
#include"Autres.h"
//IMPLEMENTATION OF SOME USEFUL FUNCTIONS

//IMPLEMENTATION OF THE MATH POWER FUNCTION
float power(float X, int a)
{
  float res = 1;
  while(a>0)
  {
    res = res*X;
    --a;
  }
  return res;
}



//IMPLEMENTATION OF RANDOM BINARY MATH FUNCTION
int aleaBinVal()
{
  int value = 0;
  value = rand()%2; // Integer return value chosen among 0 and 1
  return value;
}