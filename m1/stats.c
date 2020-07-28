/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material.
 *
 *****************************************************************************/
/**
 * @file  C file for analyze an array
 * @brief Report Analytics
 *Ahmed Ehab
 * couple of functions that can analyze an array of unsigned char data items and report analytics on the maximum, minimum, mean, and median of the data set. In addition,
 * reorder this data set from large to small. All statistics should be rounded down to the nearest integer, print that data to the screen in nicely formatted presentation.
 *
 * @author Ahmed Ehab
 * @date 25/06/2020
 *
 */



#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

void main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  /* Other Variable Declarations Go Here */

  /* Statistics and Printing Functions Go Here */
  print_statistics(test,SIZE);
  print_array(test,SIZE);

}

/* Add other Implementation File Code Here */
                                                                                                                                                                            void SWAP(unsigned char* X,unsigned char* Y)
{
  unsigned char Temp = 0;
  Temp = *X; 
  *Y = Temp;
}


void sort_array(unsigned char* arr,int Length)
{
  int i = 0 , y = 0 ;                                                                  for(y = 0 ; y < Length ; y++)                                                          {
      for(i = 0 ; i < Length ; i++)
       {
        if(arr[i] < arr[i+1])                                                                 {
           SWAP (&arr[i],&arr[i+1]);                                                          }                                                                                    else
         {
          /*Do Nothing*/
         }
        }
     }
}



int find_maximum (unsigned char* Arr,int Length)
{
  sort_array(Arr,Length);
  return Arr[0] ;
}



int find_minimum(unsigned char* Arr,int Length)
{
  sort_array(Arr,Length);                                                              return Arr[Length-1];
}

int find_mean(unsigned char* Arr,int Length)
{
  int Sum = 0,i = 0, Mean = 0;
  for(i = 0; i < Length ;i++)
    {
      Sum += Arr[i];
    }
  Mean = Sum/Length;  
    return Mean;
}

int find_median (unsigned char* Arr,int Length)
{
  unsigned char Arr1[SIZE] = {0};
  sort_array(Arr,Length);
  char Y = Length;
  int HalfWay = 0;
  for(int i = 0 ; i < Length;i++)
    {
      Arr1[i] = Arr[Y];
      Y--;
    }
  if(Length%2 == 0)                                                                      {
      /*This Mean That the Length is Even*/
      HalfWay = Length/2 ;
      return (Arr1[HalfWay] + Arr1[HalfWay+1])/2 ;
    }
  else
    {
      HalfWay = Length/2;
      return Arr1[HalfWay+1];
    }
}

void print_array(unsigned char* Arr, int Length)
{
  int i = 0;
  for(i = 0; i < Length ; i++)
    {
      printf("%d ",Arr[i]);
    }
  printf("\n");
}

void print_statistics(unsigned char* Arr,int Lenght)
{
  int Statistics = 0 ;
  printf("\n");                                                                        Statistics = find_minimum(Arr,Lenght);
  printf("%d",Statistics);                                                             printf("\n");                                                                        Statistics = find_maximum(Arr,Lenght);                                               printf("%d",Statistics);
  printf("\n");
  Statistics = find_mean(Arr,Lenght);
  printf("%d",Statistics);                                                             printf("\n");                                                                        Statistics = find_median(Arr,Lenght);                                                printf("%d",Statistics);
  printf("\n");
}