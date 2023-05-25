#include "monty.h"

/**
 * _pchar - pchar instruction handler
 * @stack: double pointer to the stack
 * @nline: the line number in the file
 */
void _pchar(stack_t **stack, unsigned int nline)
{
	stack_t *current = *stack;

	if (!current)
	{
		fprintf(stderr, FAILURE_PCHAR, nline);
		free_handle(1);
		exit(EXIT_FAILURE);
	}

	if (current->n < 0 || current->n > 127)
	{
		fprintf(stderr, ERROR_PCHAR, nline);
		free_handle(1);
		exit(EXIT_FAILURE);
	}

	putchar(current->n);
	putchar('\n');
}

/**
 * _pstr - pstr instruction handler
 * @stack: double pointer to the stack
 * @nline: the line number in the file
 */
void _pstr(stack_t **stack, unsigned int nline)
{
	stack_t *cnode = *stack;

	(void)nline;

	if (!cnode)
	{
		putchar('\n');
		return;
	}

	while (cnode && cnode->n != 0 && cnode->n >= 0 && cnode->n <= 127)
	{
		putchar(cnode->n);
		cnode = cnode->next;
	}

	putchar('\n');
}
