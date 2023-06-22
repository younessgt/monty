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

	(void)(line_number);
	temp = *stack;
	if (*stack != NULL)
	{
		while (temp != NULL)
		{
			if (temp->n > 0 && (temp->n) <= 127)
				printf("%c", temp->n);
			else
			{
				printf("\n");
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
		fclose(global_var.fd);
		free(global_var.buffer);
		free_list(stack);
		exit(EXIT_FAILURE);
	}
}
