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
 * @file Header File For the statistas analysis
 * @brief <Add Brief Description Here >
 *
 * <Add Extended Description Here>
 *
 * @author <Add FirsName LastName>
 * @date <Add date >
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

/* Add Your Declarations and Function Comments here */
void print_statistics(unsigned char* Arr,int Lenght);
void print_array(unsigned char* Arr,int Lenght);
int find_median(unsigned char* Arr,int Lenght);
int find_mean(unsigned char* Arr,int Lenght);
int find_maximum(unsigned char* Arr,int Lenght);
int find_minimum(unsigned char* Arr,int Lenght);
void sort_array(unsigned char* Arr,int Lenght);


#endif /* __STATS_H__ */