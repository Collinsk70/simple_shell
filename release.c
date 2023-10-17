#include "memory.h"

/**
 * free_memory_p - Print a pointer variable and free the memory.
 *
 * @ptr: Pointer to be freed.
 *
 * Return: No explicit return value (void).
 **/

void free_memory_p(void *ptr)
{
	if (ptr != NULL)
	{
		free(ptr);
		ptr = NULL;
	}

	ptr = NULL;
}

/**
 * free_memory_pp - Free a double pointer by freeing the pointer pointing to the address of another.
 *
 * @ptr: Double pointer to be freed.
 *
 * Return: No explicit return value (void).
 **/

void free_memory_pp(void **ptr)
{
	void **tmp;

	for (tmp = ptr; *tmp != NULL; tmp++)
		free_memory_p(*tmp);
	free_memory_p(ptr);
}
