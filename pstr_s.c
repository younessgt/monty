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
		while (temp != NULL && temp->n != 0)
		{
			if (temp->n > 0 && (temp->n) <= 127)
			{
				printf("%c", temp->n);
				temp = temp->next;
			}
			else
				break;
		}
	}
	printf("\n");
}
