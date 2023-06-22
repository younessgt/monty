#include "monty.h"
/**
 * pstr_s - function that prints the string starting
 * at the top of the stack
 * @stack: pointer to pointer to structure
 * @line_number: lines number of the file
 * Return: nothing
 */
void pstr_s(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	temp = *stack;
	if (*stack != NULL)
	{
		while (temp != NULL)
		{
			if (temp->n > 0 && (temp->n) <= 127)
				printf("%c\n", temp->n);
			else
			{
				fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
				fclose(global_var.fd);
				free(global_var.buffer);
				free_list(stack);
				exit(EXIT_FAILURE);
			}
			temp = temp->next;
		}
	}
	else
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		fclose(global_var.fd);
		free(global_var.buffer);
		free_list(stack);
		exit(EXIT_FAILURE);
	}
}
