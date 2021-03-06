// cppSortingAlgorithms.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <ctime>
#include <chrono>


void printArray(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

void swap(int *xp, int *yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void selectionSort(int arr[], int n)
{
	int i, j, min_idx;

	// One by one move boundary of unsorted subarray 
	for (i = 0; i < n - 1; i++)
	{
		// Find the minimum element in unsorted array 
		min_idx = i;
		for (j = i + 1; j < n; j++)
			if (arr[j] < arr[min_idx])
				min_idx = j;

		// Swap the found minimum element with the first element 
		swap(&arr[min_idx], &arr[i]);
	}
}

//////////////////////////////BUBBLE

// A function to implement bubble sort 
void bubbleSort(int arr[], int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++)

		// Last i elements are already in place    
		for (j = 0; j < n - i - 1; j++)
			if (arr[j] > arr[j + 1])
				swap(&arr[j], &arr[j + 1]);
}


//////////////////////////////////////// INSERTION

void insertionSort(int arr[], int n)
{
	int i, key, j;
	for (i = 1; i < n; i++)
	{
		key = arr[i];
		j = i - 1;

		/* Move elements of arr[0..i-1], that are
		   greater than key, to one position ahead
		   of their current position */
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}


//////////////////////////////////////////// MERGE


void merge(int arr[], int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;
	
	/* create temp arrays */
	int* L = new int[n1];
	int* R = new int[n2];
		

	/* Copy data to temp arrays L[] and R[] */
	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];

	/* Merge the temp arrays back into arr[l..r]*/
	i = 0; // Initial index of first subarray 
	j = 0; // Initial index of second subarray 
	k = l; // Initial index of merged subarray 
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	/* Copy the remaining elements of L[], if there
	   are any */
	while (i < n1)
	{
		arr[k] = L[i];
		i++;
		k++;
	}

	/* Copy the remaining elements of R[], if there
	   are any */
	while (j < n2)
	{
		arr[k] = R[j];
		j++;
		k++;
	}
}

/* l is for left index and r is right index of the
   sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r)
{
	if (l < r)
	{
		// Same as (l+r)/2, but avoids overflow for 
		// large l and h 
		int m = l + (r - l) / 2;

		// Sort first and second halves 
		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);

		merge(arr, l, m, r);
	}
}

////////////////////////////////////// QUICK


int partition(int arr[], int low, int high)
{
	int pivot = arr[high];    // pivot 
	int i = (low - 1);  // Index of smaller element 

	for (int j = low; j <= high - 1; j++)
	{
		// If current element is smaller than or 
		// equal to pivot 
		if (arr[j] <= pivot)
		{
			i++;    // increment index of smaller element 
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

/* The main function that implements QuickSort
  arr[] --> Array to be sorted,
  low  --> Starting index,
  high  --> Ending index */
void quickSort(int arr[], int low, int high)
{
	if (low < high)
	{
		/* pi is partitioning index, arr[p] is now
		   at right place */
		int pi = partition(arr, low, high);

		// Separately sort elements before 
		// partition and after partition 
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}


/////////////////////////////////////// HEAP


void heapify(int arr[], int n, int i)
{
	int largest = i; // Initialize largest as root 
	int l = 2 * i + 1; // left = 2*i + 1 
	int r = 2 * i + 2; // right = 2*i + 2 

	// If left child is larger than root 
	if (l < n && arr[l] > arr[largest])
		largest = l;

	// If right child is larger than largest so far 
	if (r < n && arr[r] > arr[largest])
		largest = r;

	// If largest is not root 
	if (largest != i)
	{
		swap(&arr[i], &arr[largest]);

		// Recursively heapify the affected sub-tree 
		heapify(arr, n, largest);
	}
}

// main function to do heap sort 
void heapSort(int arr[], int n)
{
	// Build heap (rearrange array) 
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i);

	// One by one extract an element from heap 
	for (int i = n - 1; i >= 0; i--)
	{
		// Move current root to end 
		swap(&arr[0], &arr[i]);

		// call max heapify on the reduced heap 
		heapify(arr, i, 0);
	}
}

/////////////////////////////////  COUNT 

void countSort(int arr[], int n)
{
	int counter[10001];

	for (int i = 0; i < 10001; i++)
	{
		counter[i] = 0;
	}

	for (int i = 0; i < n; i++)
	{
		counter[arr[i]]++;
	}


	int k = 0;
	for (int i = 0; i < 10001; i++)
	{
		if (counter[i] != 0) {
			for (int j = 0; j < counter[i]; j++) {
				arr[k] = i;
				k++;
			}
		}
	}
	
}

using namespace std;
using namespace std::chrono;


int main()
{

	const int size = 20000;
	const int range = 10000;

	int arr[size];
	int arr2[size];
	int arr3[size];
	int arr4[size];
	int arr5[size];
	int arr6[size];
	int arr7[size];

	srand((unsigned)time(0));

	for (int i = 0; i < size; i++) {
		arr[i] = (rand() % range) + 1;
		arr2[i] = (rand() % range) + 1;
		arr3[i] = (rand() % range) + 1;
		arr4[i] = (rand() % range) + 1;
		arr5[i] = (rand() % range) + 1;
		arr6[i] = (rand() % range) + 1;
		arr7[i] = (rand() % range) + 1;
	}



	//int arr[] = { 64, 25, 12, 22, 11 };
	int n = sizeof(arr) / sizeof(arr[0]);
	high_resolution_clock::time_point t1 = high_resolution_clock::now();
	selectionSort(arr, n);
	high_resolution_clock::time_point t2 = high_resolution_clock::now();
	std::cout << "Selection took:  ";
	std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count();
	printf("\n");

	int n2 = sizeof(arr2) / sizeof(arr2[0]);
	t1 = high_resolution_clock::now();
	bubbleSort(arr2, n2);
	t2 = high_resolution_clock::now();
	std::cout << "Bubble took:  ";
	std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count();
	printf("\n");

	int n3 = sizeof(arr3) / sizeof(arr3[0]);
	t1 = high_resolution_clock::now();
	insertionSort(arr3, n3);
	t2 = high_resolution_clock::now();
	std::cout << "Insertion took:  ";
	std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count();
	printf("\n");

	int n4 = sizeof(arr4) / sizeof(arr4[0]);
	t1 = high_resolution_clock::now();
	mergeSort(arr4, 0, n4 - 1);
	t2 = high_resolution_clock::now();
	std::cout << "Merge took:  ";
	std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count();
	printf("\n");

	int n5 = sizeof(arr5) / sizeof(arr5[0]);
	t1 = high_resolution_clock::now();
	quickSort(arr5, 0, n5 - 1);
	t2 = high_resolution_clock::now();
	std::cout << "Quick took:  ";
	std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count();
	printf("\n");

	int n6 = sizeof(arr6) / sizeof(arr6[0]);
	t1 = high_resolution_clock::now();
	heapSort(arr6, n6);
	t2 = high_resolution_clock::now();
	std::cout << "Heap took:  ";
	std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count();
	printf("\n");

	int n7 = sizeof(arr7) / sizeof(arr7[0]);
	t1 = high_resolution_clock::now();
	countSort(arr7, n7);
	t2 = high_resolution_clock::now();
	std::cout << "Count took:  ";
	std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count();
	printf("\n");

}

