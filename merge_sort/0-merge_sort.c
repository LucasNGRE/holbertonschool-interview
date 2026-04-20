#include <stdlib.h>
#include <stdio.h>
#include "sort.h"

/**
 * merge - Merges two sub-arrays back into the original array
 *
 * @array: The original array
 * @buf: Temporary buffer
 * @left: Start index of left sub-array
 * @mid: End index (exclusive) of left sub-array
 * @right: End index (exclusive) of right sub-array
 */
static void merge(int *array, int *buf, size_t left, size_t mid, size_t right)
{
	size_t i, j, k;

	printf("Merging...\n[left]: ");
	print_array(array + left, mid - left);
	printf("[right]: ");
	print_array(array + mid, right - mid);

	i = left;
	j = mid;
	k = left;
	while (i < mid && j < right)
	{
		if (array[i] <= array[j])
			buf[k++] = array[i++];
		else
			buf[k++] = array[j++];
	}
	while (i < mid)
		buf[k++] = array[i++];
	while (j < right)
		buf[k++] = array[j++];

	for (i = left; i < right; i++)
		array[i] = buf[i];

	printf("[Done]: ");
	print_array(array + left, right - left);
}

/**
 * merge_recurse - Recursively splits and merges sub-arrays
 *
 * @array: The original array
 * @buf: Temporary buffer
 * @left: Start index
 * @right: End index (exclusive)
 */
static void merge_recurse(int *array, int *buf, size_t left, size_t right)
{
	size_t mid;

	if (right - left < 2)
		return;

	mid = left + (right - left) / 2;
	merge_recurse(array, buf, left, mid);
	merge_recurse(array, buf, mid, right);
	merge(array, buf, left, mid, right);
}

/**
 * merge_sort - Sorts an array using top-down merge sort
 *
 * @array: The array to sort
 * @size: Number of elements in @array
 */
void merge_sort(int *array, size_t size)
{
	int *buf;

	if (!array || size < 2)
		return;

	buf = malloc(sizeof(int) * size);
	if (!buf)
		return;

	merge_recurse(array, buf, 0, size);
	free(buf);
}
