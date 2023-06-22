#include "monty.h"
void (*compare(char *token))(stack_t **stack, unsigned int line_number)
{
	int i = 0;
	instruction_t func[] = {
		{"push", push_s},
		{"pall", pall_s},
		{"pint", pint_s},
		{"pop", pop_s},
		{"swap", swap_s},
		{"add", add_s},
		{"sub", sub_s},
		{"nop", nop_s},
		{"div", div_s},
		{"mul", mul_s},
		{"mod", mod_s},
		{"msgerror", msg_error}
	};
	while (i < 11)
	{
		if (strcmp(func[i].opcode, token) == 0)
			return (func[i].f);
		i++;
	}
	return (func[11].f);
}
void msg_error(stack_t **stack, unsigned int line_number)
{
	(void)(stack);
	fprintf(stderr, "L%u: unknown instruction %s\n", line_number,
			global_var.tok1);
	fclose(global_var.fd);
	free(global_var.buffer);
	exit(EXIT_FAILURE);
}
void tok(stack_t **stack, unsigned int line_number, char *buffer)
{
	char *token;

	token = strtok(buffer, " \t\n");
	global_var.tok1 = token;
	if (token == NULL)
	{
		return;
	}
	global_var.tok3 = strtok(NULL, " \t\n");
	if (global_var.tok3 != NULL && (isnumber(global_var.tok3) == 1))
		global_var.tok2 = atoi(global_var.tok3);
	compare(token)(stack, line_number);
}
void push_s(stack_t **stack, unsigned int line_number)
{
	stack_t *new_n;

	if ((global_var.tok3 != NULL) && (isnumber(global_var.tok3) == 1))
	{
		new_n = malloc(sizeof(stack_t));
		if (new_n == NULL)
		{
			fprintf(stderr, "Error: malloc failed\n");
			fclose(global_var.fd);
			free(global_var.buffer);
			exit(EXIT_FAILURE);
		}
		new_n->n = global_var.tok2;
		new_n->next = *stack;
		if (*stack != NULL)
			(*stack)->prev = new_n;
		new_n->prev = NULL;
		*stack = new_n;
	}
	else
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		fclose(global_var.fd);
		free(global_var.buffer);
		free_list(stack);
		exit(EXIT_FAILURE);
	}
}
