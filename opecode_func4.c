#include "monty.h"

/**
 * _pchar - pchar instruction handler
 * @stack: double pointer to the stack
 * @nline: the line number in the file
 */
void _pchar(stack_t **stack, unsigned int nline)
{
	stack_t *node = *stack;

	if (!node)
	{
		fprintf(stderr, FAILURE_PCHAR, nline);
		free_handle(1);
		exit(EXIT_FAILURE);
	}

	if (node->n < 0 || node->n > 127)
	{
		fprintf(stderr, ERROR_PCHAR, nline);
		free_handle(1);
		exit(EXIT_FAILURE);
	}

	putchar(node->n);
	putchar('\n');
}

/**
 * _pstr - pstr instruction handler
 * @stack: double pointer to the stack
 * @nline: the line number in the file
 */
void _pstr(stack_t **stack, unsigned int nline)
{
	stack_t *node = *stack;

	(void)nline;

	if (!node)
	{
		putchar('\n');
		return;
	}

	while (node && node->n != 0 && node->n >= 0 && node->n <= 127)
	{
		putchar(node->n);
		node = node->next;
	}

	putchar('\n');
}
