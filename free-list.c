#include "monty.h"
/**
 * free_list - function that frees a struct list
 * @stack: pointer to structure pointer
 * Return: nothing
 */
void free_list(stack_t **stack)
{
	stack_t *tracker;

	while (*stack != NULL)
	{
		tracker = *stack;
		(*stack) = (*stack)->next;
		free(tracker);
	}
}
