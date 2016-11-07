/*
    Breandan Kerin
    Student - Trinity College Dublin
    Date Created - 7/8/16
*/

#pragma once
#pragma once
#include <stdbool.h>

//Heler Functions
void Merge(int* array_, int first, int last);
bool Sorted(int* array_, int SIZE);

// Sorting Functions
void selection_sort(int* array_, int SIZE);
void bubble_sort(int* array_,int SIZE);
void insertion_sort(int* array_, int SIZE);
void shell_sort(int* array_, int SIZE);
void printA(int* array_, int SIZE);
