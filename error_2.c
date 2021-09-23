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

/**
 * swap_error - print error message if the stack is empty.
 * @line: line.
 * Return: void.
 */
void swap_error(unsigned int line)
{
	fprintf(stderr, "L%u: can't swap, stack too short\n", line);
	exit(EXIT_FAILURE);
}

/**
 * add_error - print error message if the stack is empty.
 * @line: line.
 * Return: void.
 */
void add_error(unsigned int line)
{
	fprintf(stderr, "L%u: can't add, stack too short,\n", line);
	exit(EXIT_FAILURE);
}
