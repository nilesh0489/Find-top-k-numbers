/*
-------------------------------------------------------------
 * The Time Complexity is: O(n) 
-------------------------------------------------------------
 */


#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define heap_size 5		/* top k elements */

int heap_array[heap_size];	/* Array to store top k elements */

/*
----------------------------------------------------
 * The function finds the position of the left child
 * @param: the position of the parent
----------------------------------------------------
 */
int left(int i)
{
	return 2*i + 1;
}


/*
-----------------------------------------------------
 * The function finds the position of the right child
 * @param: the position of the parent
-----------------------------------------------------
 */

int right(int i)
{
	return 2*i + 2;
}


/*
----------------------------------------------
 * The function swaps two numbers
 * @param1: the parent value
 * @param2: the child value
----------------------------------------------
 */
 
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/*
---------------------------------------------------------------
 * The function maintains a min heap
 * @param1: the position at which min heap property is violated
---------------------------------------------------------------
 */

void min_heapify(int i)
{
	int l = left(i);
	int r = right(i);
	int minimum = 0;
	
	if(l < heap_size && heap_array[l] < heap_array[i])		/* check the parent and the left child */
		minimum = l;						
	else 								/* store the position of the minimum element */
		minimum = i;
		
	if(r < heap_size && heap_array[r] < heap_array[minimum])	/* compare the minimum with the right child */
		minimum = r;
	
	if(minimum != i)						/* the min heap property is violated, so call min_heapify again */
		{
			swap(&heap_array[i],&heap_array[minimum]);
			min_heapify(minimum);
		}
}


/*
--------------------------------------------------------
 * The function changes the root value
 * @param1: next value from the array
--------------------------------------------------------
 */

int manipulate_root(int x)
{
	int root = heap_array[0];
	if (root < x)				/* if the new number is greater than the root of the heap, then change it with new value and call min_heapify */
	{
	 	heap_array[0] = x;
	}
	   
	min_heapify(0);
}

/*
--------------------------------------------------
 * The function maintains the min heap property
 * @param1: the position in the heap_array
--------------------------------------------------
 */
void bubble_up(int position)
{
	int i = position;
	
	while(i >= 0 && (heap_array[i] < heap_array[i/2]))
	{
		swap(&heap_array[i], &heap_array[i/2]);
		i = i / 2;
	}
}

/*
--------------------------------------------------
 * The function initializes the heap
 * @param1: input array
 --------------------------------------------------
 */
void init_heap(int *arr)
{
	int i = 0;
	
	while(i < heap_size)
	{
		heap_array[i] = arr[i];
		bubble_up(i);
		i++;
	}	
}


/*
--------------------------------------------------
 * The function finds the top k elements in a list
 * @param1: input array
 * @param2: size of the array
 * @param3: top k elements
--------------------------------------------------
 */

void top_k_elements(int *arr, int n, int k)
{
	int i = 0;
	
	init_heap(arr);
		
	for(i = k; i < n; i++)
	{
	    	manipulate_root(arr[i]);
	}
   
}

int main()
{
	int array[9] = {35, 875, 23, 75, 8743, 353, 76, 83, 934};
	
	int arr_length = sizeof(array) / sizeof(int);
	
	if(arr_length < heap_size)
	{
		printf("ERROR: Not enough elements in the list\n");
		return;
	}
	
	int k = 0;
	
	top_k_elements(array, arr_length, heap_size);
	
	printf("The top %d elements are:\n", heap_size);
	
	for(k = 0; k < heap_size; k++)
		printf("%d ", heap_array[k]);
		
	printf("\n");
	
	return 0;
}

