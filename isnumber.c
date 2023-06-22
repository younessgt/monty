#include "monty.h"
/**
 * isnumber - function that
 *
 */
int isnumber(char *token)
{
	if (token[0] == '\0')
		return (-1);
	if (token[0] == '+' || token[0] == '-')
		token++;
	while (*token != '\0')
	{
		if (!isdigit(*token))
			return (-1);
		token++;
	}
	return (1);
}
