#include "monty.h"
/**
 * pall_s - prints all the values on the stack, starting from
 * the top of the stack.
 * @stack: pointer to pointer to the structure
 * @line_number: the number of the line executed in the file
 *
 */
void pall_s(stack_t **stack, unsigned int line_number)
{
	stack_t *track;

	track = *stack;
	(void)(line_number);

	if (*stack != NULL)
	{
		while (track !=  NULL)
		{
			printf("%d\n", track->n);
			track = track->next;
		}
	}
}
