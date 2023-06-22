#ifndef MONTY_H
#define MONTY_H
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <stddef.h>
#include <ctype.h>
#include <string.h>
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

typedef struct glob
{
	char *buffer;
	char *tok1;
	int tok2;
	char *tok3;
	FILE *fd;
} global;

extern global global_var;

void (*compare(char *token))(stack_t **stack, unsigned int line_number);
void tok(stack_t **stack, unsigned int line_number, char *buffer);
int isnumber(char *token);
void msg_error(stack_t **stack, unsigned int line_number);
void push_s(stack_t **stack, unsigned int line_number);
void pall_s(stack_t **stack, unsigned int line_number);
void free_list(stack_t **stack);
void pint_s(stack_t **stack, unsigned int line_number);
void pop_s(stack_t **stack, unsigned int line_number);
void swap_s(stack_t **stack, unsigned int line_number);
void add_s(stack_t **stack, unsigned int line_number);
void sub_s(stack_t **stack, unsigned int line_number);
void nop_s(stack_t **stack, unsigned int line_number);
void div_s(stack_t **stack, unsigned int line_number);
void mul_s(stack_t **stack, unsigned int line_number);
void mod_s(stack_t **stack, unsigned int line_number);
#endif
