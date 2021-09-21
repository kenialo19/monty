#include "monty.h"
/**
 * get_op_code - tydt
 * @token: operation code
 * @line: line readed
 * Return: void
 */
void (*get_op_code(char *token, unsigned int line))(stack_t **, unsigned int)
{
	int i;
	instruction_t op[] = {
	{"push",},
	{"pall", },
	{NULL, NULL}
	};
	for (i = 0; op[i].opcode != NULL; i++)
	{
		if (strcmp(token, op[i].opcode) == 0)
		{
			return (op[i].f);
		}
	}
	return (NULL);
}
