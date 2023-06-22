#include "monty.h"
/**
 * mod_s - function that compute the rest of the the second
 * top element by the top element of the stack
 * @stack: pointer to pointer to structure
 * @line_number: lines number of the file
 * Return: nothing
 */
void mod_s(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int i, j;

	temp = *stack;
	if (*stack != NULL && (*stack)->next != NULL)
	{
		i = temp->n;
		if (i == 0)
		{
			fprintf(stderr, "L%d: division by zero\n", line_number);
			fclose(global_var.fd);
			free(global_var.buffer);
			free_list(stack);
			exit(EXIT_FAILURE);
		}
		*stack = temp->next;
		(*stack)->prev = NULL;
		j = (*stack)->n;
		(*stack)->n = j % i;
		free(temp);
	}
	else
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		fclose(global_var.fd);
		free(global_var.buffer);
		free_list(stack);
		exit(EXIT_FAILURE);
	}
}

