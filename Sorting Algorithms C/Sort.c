/*
    Breandan Kerin
    Student - Trinity College Dublin
    Date Created - 7/8/16
*/

#pragma once
#include "Sort.h"

void MergeSort(int* array, int SIZE, int firstIndex, int lastIndex)
{

	int midIndex = (lastIndex + firstIndex) / 2;

	if (firstIndex >= lastIndex)
		return;

	MergeSort(array, SIZE, firstIndex, midIndex);
	MergeSort(array, SIZE, midIndex + 1, lastIndex);

	if (Sorted(array, SIZE))
		return;

	Merge(array, firstIndex, lastIndex);
}

void selection_sort(int* array, int SIZE)
{
    int min ;
    //traverse array
    for(int i =0; i< SIZE-1; i++)
    {
        // used to find min val in index
        min = i;
        for (int x = i+1; x < SIZE; x++)
        {
            //new min index val
            if(array[min] > array[x])
                min = x;
        }

        //swapping
        if (min != i)
        {
            int temp = array[i];
            array[i] = array[min];
            array[min] = temp;
        }
    }

    printf("\n Selection Sort:");
    printA(array, SIZE);
}

void bubble_sort(int* array, int SIZE)
{
    int i, temp;

    for( i = 0; i< (SIZE-1); i++)

        for(int x = 0; x < (SIZE-i-1); x++)
        {
            if(array[x] > array[x+1])
            {
                temp = array[x];
                array[x] = array[x+1];
                array[x+1] = temp;
            }
        }

    printf("\n Bubble Sort:");
    printA(array, SIZE);
}

void insertion_sort(int* array, int SIZE)
{
    int j, temp;
    for(int x = 0; x < SIZE ; x++)
    {
        j = x;
        while(j < 0 && array[j] < array[j-1])
        {
            temp = array[j];
            array[j] = array[j-1];
            array[j-1] = temp;
            j--;
        }
    }

    printf("\n Insertion Sort:");
    printA(array, SIZE);
}

void shell_sort(int* array, int SIZE)
{
    int gap = SIZE/2;

    while(gap > 0)
    {
        for(int i = 0; i < SIZE; i++)
        {
            int temp = array[i];
            int j = i;

            while(j >= gap && array[j - gap] > temp)
            {
                array[j] = array[j- gap];
                j -= gap;
            }

            array[j] = temp;
        }

        gap = gap/2;
    }

    printf("\n Shell Sort:");
    printA(array, SIZE);
}

/*
        HELPER FUNCTIONS:
*/

void printA(int* array, int SIZE )
{
    for(int i = 0; i < SIZE; i++)
    {
        printf("\n %d", array[i]);
    }
    printf("\n");
}


bool Sorted(int* array, int SIZE)
{
	for (int i = 0; i < SIZE; i++)
	{
		if (array[i] > array[i + 1])
			return false;
	}
}

void Merge(int* array, int first, int last)
{
	int mid = (last + first) / 2;
	int size = last - first + 1;
	int outputIndex = 0;
	int leftIndex = first;
	int rightIndex = mid + 1;

	int* output = (int*)calloc(size, sizeof(int));

	while (leftIndex <= mid && rightIndex <= last)
	{
		if (array[leftIndex] < array[rightIndex])
		{
			output[outputIndex++] = array[leftIndex++];
		}

		else if (array[leftIndex] >= array[rightIndex])
		{
			output[outputIndex++] = array[rightIndex++];
		}

		else
			printf("something went wrong\n");
	}

	while (leftIndex <= mid)
	{
		output[outputIndex++] = array[leftIndex++];
	}

	while (rightIndex <= last)
	{
		output[outputIndex++] = array[rightIndex++];
	}

	for (int i = 0; i < outputIndex; i++)
	{
		array[i + first] = output[i];
	}
}
