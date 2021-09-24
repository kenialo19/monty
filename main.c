#include "monty.h"
/**
 * main -Monty bytecodes files interpreter
 * @argc: total of arguments
 * @argv: The arguments, monty files
 * Return: int
 */
int main(int argc, char **argv)
{
	if (argc > 2)
		error_argv();

	op_re_file(argv);
	return (0);
}
