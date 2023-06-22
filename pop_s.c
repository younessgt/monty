#include "monty.h"
/**
 * pop_s - function that removes the top of element of the stack
 * @stack: pointer to pointer to structure
 * @line_number: lines number of the file
 * Return: nothing
 */
void pop_s(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	temp = *stack;
	if (*stack != NULL)
	{
		if ((*stack)->next != NULL)
		{
			*stack = temp->next;
			(*stack)->prev = NULL;
			free(temp);
		}
		else
		{
			*stack = NULL;
			free(temp);
		}
	}
	else
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		fclose(global_var.fd);
		free(global_var.buffer);
		free_list(stack);
		exit(EXIT_FAILURE);
	}
}
