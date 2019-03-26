#include "search_algos.h"

/**
 * binary_search - search algorithm
 * @array: array input
 * @size: size of array int type
 * @value: value to search for if exist in array
 *
 * Description: binary search algorithm to find value
 * Return: -1 if not found or if array is NULL or index of value location
 **/
int binary_search(int *array, size_t size, int value)
{
	size_t low = 0;
	size_t high = size - 1;
	size_t mid  = NULL;

	while (array && low <= high)
	{
		printer(array, low, high);
		mid = (low + high) / 2;
		if (value == array[mid])
			return (mid);
		else if (value < array[mid])
			high = mid;
		else
			low = mid + 1;
	}
	return (-1);
}

/**
 * printer - print array
 * @array: sub-array to print
 * @i: starting index
 * @size: length of sub-array
 *
 * Description: print sub array
 * Return: void
 */
void printer(int *array, size_t i, size_t size)
{
	printf("Searching in array: ");
	for (; i <= size; i++)
	{
		printf("%d", array[i]);
		if (i < size)
			printf(", ");
	}
	printf("\n");
}
