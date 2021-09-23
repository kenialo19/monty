#include "monty.h"

/**
 * pint_error - print error message if the stack is empty.
 * @line: line.
 * Return: void.
 */
void pint_error(unsigned int line)
{
	fprintf(stderr, "L%u: can't pint, stack empty\n", line);
	exit(EXIT_FAILURE);
}
