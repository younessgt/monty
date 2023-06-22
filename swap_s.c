#include "monty.h"
/**
 * swap_s - function that swaps the top two element of the stack
 * @stack: pointer to pointer to structure
 * @line_number: lines number of the file
 * Return: nothing
 */
void swap_s(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	temp = *stack;
	if (*stack != NULL && (*stack)->next != NULL)
	{
		*stack = temp->next;
		(*stack)->prev = NULL;
		temp->next = (*stack)->next;
		(*stack)->next = temp;
		temp->prev = *stack;
	}
	else
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		fclose(global_var.fd);
		free(global_var.buffer);
		free_list(stack);
		exit(EXIT_FAILURE);
	}
}
