/*
    Breandan Kerin
    Student - Trinity College Dublin
    Date Created - 7/8/16
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "Sort.h"

int SIZE = 5;

int main()
{
    int array_[SIZE], array1_[SIZE], array2_[SIZE], array3_[SIZE], array4_[SIZE];

    printf("unsorted list");
    for(int x = 0; x<SIZE; x++)
    {
        array_[x] = rand()%1000;
        array1_[x] = rand()%1000;
        array2_[x] = rand()%1000;
        array3_[x] = rand()%1000;
        array4_[x] = rand()%1000;

        printf("\n %d   %d    %d    %d  %d  ", array_[x], array1_[x], array2_[x], array3_[x], array4_[x]);
    }

    printf("\n");

    selection_sort(array_, SIZE);
    insertion_sort(array1_, SIZE);
    bubble_sort(array2_, SIZE);
    shell_sort(array3_, SIZE);
    MergeSort(array4_, SIZE, 0, SIZE-1);

    printf("\n Merge Sort:");
    printA(array4_, SIZE);
    return 0;
}
