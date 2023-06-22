#include "monty.h"

void pall_s(stack_t **stack, unsigned int line_number)
{
	stack_t *track;
	track = *stack;
	(void)(line_number);
	if (global_var.tok3 == NULL && *stack != NULL)
	{
		while (track !=  NULL)
		{
			printf("%d\n", track->n);
			track = track->next;
		}
	}
}
