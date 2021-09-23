#include "monty.h"

/**
 * get_op_code - tydt
 * @token: operation code
 * @line: line readed
 * Return: void
 */
void (*get_op_code(char *token, unsigned int line))(stack_t **, unsigned int)
{
	int i = 0, j = 0;
	char **tokens = NULL;

	tokens = tokenizer(token, "\n\t\r ");

	if (tokens[1])
		glb_number = atoi(tokens[1]);

	for (i = 0; list[i].opcode != NULL; i++)
	{
		if (strcmp(token, list[i].opcode) == 0)
		{
			free(tokens);
			return (list[i].f);
		}
	}

	return (NULL);
}

/**
 * tokenizer - Function that split a string.
 * @s: string to split.
 * @delim: words delimiter.
 * Return: a char double pointer that contains splited words.
 */

char **tokenizer(char *s, char *delim)
{
	int i = 0, cword = 0;
	char **splited_words = NULL;

	cword = count_words(s);

	splited_words = malloc(sizeof(char *) * (cword + 1));
	if (splited_words == NULL)
	{
		malloc_error();
		return (NULL);
	}

	splited_words[0] = strtok(s, delim);

	if (splited_words[0] == NULL)
	{
		malloc_error();
		free(splited_words[0]);
		free(splited_words);
		return (NULL);
	}

	for (i = 1; i < cword; i++)
	{
		splited_words[i] = strtok(NULL, delim);
	}
	return (splited_words);
}

#define OUT 0
#define IN 1

/**
 * count_words - function that counts words depending on delimiters
 * @str: string to be evaluated.
 * Return: number of words in the string.
 */

int count_words(char *str)
{
	int state = OUT;
	unsigned int wc = 0;

	while (*str)
	{
		if (*str == ' ' || *str == '\n' || *str == '\t' ||
			*str == ':' || *str == '=')
			state = OUT;

		else if (state == OUT)
		{
			state = IN;
			++wc;
		}
		++str;
	}
	return (wc);
}
/**
 * frees -  frees a dlistint_t list.
 * @stack: pointer to a pointer to the head of a list.
 * Return: void
 */
void frees(stack_t **stack)
{
	stack_t *fre;

	while (*stack)
	{
		fre = (*stack);
		(*stack) = fre->prev;
		free(fre);
	}
}

/**
 * int_error - print message if parameter receivedis not integer
 * @line: line
 * Return: void
 */
void int_error(int line)
{
	fprintf(stderr, "L%u: usage: push integer\n", line);
	exit(EXIT_FAILURE);
}
