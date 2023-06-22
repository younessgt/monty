#define _GNU_SOURCE
#include "monty.h"
#include <stdio.h>
#include <string.h>
global global_var;
int main(int argc, char **argv)
{
	size_t len;
	ssize_t read;
	stack_t *stack;
	unsigned int track = 1;
	global_var.buffer = NULL;
	len = 0;
	stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr,"USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	global_var.fd = fopen(argv[1],"r");
	if (global_var.fd == NULL)
	{
		fprintf(stderr,"Error: Can't open file %s\n",argv[1]);
		exit(EXIT_FAILURE);
	}
	while((read = getline(&(global_var.buffer),&len,global_var.fd)) != EOF)
	{

		if (read != -1)
		{
			tok(&stack, track, global_var.buffer);
			track++;
		}
		else
		{
			free(global_var.buffer);
			fclose(global_var.fd);
			exit(EXIT_FAILURE);
		}
	}
	free(global_var.buffer);
	fclose(global_var.fd);
	free_list(&stack);
	return (0);
}
