#include "monty.h"

/**
 * open_and_read - 
 * @argv: arguments 
 * Return: void
 **/

void op_re_file(char **argv)
{
    FILE *fd = NULL;
    char *buf = NULL, *token = NULL;
    size_t len = 0, line_size;

    fd = fopen(argv[1], "r");
	if (fd == NULL)
		open_error(argv);
    
    while ((line_size = getline(&buf, &len, fd)) != EOF)
	{
		token = strtok(buf, "\n\t\r ");
        
}