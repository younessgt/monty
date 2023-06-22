#include "monty.h"
/**
 * sub_s - function that substract the top two element of the stack
 * in the second and remove the first one.
 * @stack: pointer to pointer to structure
 * @line_number: lines number of the file
 * Return: nothing
 */
void sub_s(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	temp = *stack;
	if (*stack != NULL && (*stack)->next != NULL)
	{
		*stack = temp->next;
		(*stack)->prev = NULL;
		(*stack)->n = (*stack)->n - temp->n;
		free(temp);
	}
	else
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		fclose(global_var.fd);
		free(global_var.buffer);
		free_list(stack);
		exit(EXIT_FAILURE);
	}
}
