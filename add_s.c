#include "monty.h"
/**
 * add_s - function that adds the top two element of the stack in the second
 * and remove the first one.
 * @stack: pointer to pointer to structure
 * @line_number: lines number of the file
 * Return: nothing
 */
void add_s(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int i, j;

	temp = *stack;
	if (*stack != NULL && (*stack)->next != NULL)
	{
		*stack = temp->next;
		(*stack)->prev = NULL;
		i = temp->n;
		j = (*stack)->n;
		(*stack)->n = i + j;
		free(temp);
	}
	else
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		fclose(global_var.fd);
		free(global_var.buffer);
		free_list(stack);
		exit(EXIT_FAILURE);
	}
}

