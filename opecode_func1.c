#include "monty.h"

/**
 * _push - push instruction handler
 * @stack: double pointer to the stack
 * @nline: the line number in the file
 */
void _push(stack_t **stack, unsigned int nline)
{
	stack_t *node;
	int n = 0, i;

	if (info.words[1] == NULL)
	{
		fprintf(stderr, FAILURE_PUSH, nline);
		free_handle(1);
		exit(EXIT_FAILURE);
	}

	for (i = 0; info.words[1][i]; i++)
	{
		if (isalpha(info.words[1][i]) != 0)
		{
			fprintf(stderr, FAILURE_PUSH, nline);
			free_handle(1);
			exit(EXIT_FAILURE);
		}
	}
	n = atoi(info.words[1]);

	if (info.sflag == 0)
		node = add_dnodeint(stack, n);
	else if (info.sflag == 1)
		node = add_dnodeint_end(stack, n);
	if (!node)
	{
		fprintf(stderr, FAILURE_MALLOC);
		free_handle(1);
		exit(EXIT_FAILURE);
	}
}

/**
 * _pall - pall instruction handler
 * @stack: double pointer to the stack
 * @nline: the line number in the file
 */
void _pall(stack_t **stack, unsigned int nline)
{
	(void)nline;
	if (*stack)
		print_dlistint(*stack);
}

/**
 * _pint - pint instruction handler
 * @stack: double pointer to the stack
 * @nline: the line number in the file
 */
void _pint(stack_t **stack, unsigned int nline)
{
	stack_t *current = *stack;

	if (!current)
	{
		fprintf(stderr, FAILURE_PINT, nline);
		free_handle(1);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", current->n);
}

/**
 * _pop - pop instruction handler
 * @stack: double pointer to the stack
 * @nline: the line number in the file
 */
void _pop(stack_t **stack, unsigned int nline)
{
	stack_t *current = *stack;

	if (!current)
	{
		fprintf(stderr, FAILURE_POP, nline);
		free_handle(1);
		exit(EXIT_FAILURE);
	}

	delete_dnodeint_at_index(stack, 0);
}

/**
 * _add - add instruction handler
 * @stack: double pointer to the stack
 * @nline: the line number in the file
 */
void _add(stack_t **stack, unsigned int nline)
{
	int sum = 0;
	stack_t *nsum = NULL;
	stack_t *node0 = get_dnodeint_at_index(*stack, 0);
	stack_t *node1 = get_dnodeint_at_index(*stack, 1);

	if (dlistint_len(*stack) < 2)
	{
		fprintf(stderr, FAILURE_ADD, nline);
		free_handle(1);
		exit(EXIT_FAILURE);
	}

	sum = node0->n + node1->n;
	delete_dnodeint_at_index(stack, 0);
	delete_dnodeint_at_index(stack, 0);
	nsum = add_dnodeint(stack, sum);
	if (!nsum)
	{
		fprintf(stderr, FAILURE_MALLOC);
		free_handle(1);
		exit(EXIT_FAILURE);
	}
}
