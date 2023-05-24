#include "monty.h"

/**
 * _sub - sub instruction handler
 * @stack: double pointer to the stack
 * @nline: the line number in the file
 */
void _sub(stack_t **stack, unsigned int nline)
{
	int sub = 0;
	stack_t *node = NULL;
	stack_t *node_0 = get_dnodeint_at_index(*stack, 0);
	stack_t *node_1 = get_dnodeint_at_index(*stack, 1);

	if (dlistint_len(*stack) < 2)
	{
		fprintf(stderr, FAILURE_SUB, nline);
		free_handle(1);
		exit(EXIT_FAILURE);
	}

	sub = node_1->n - node_0->n;
	delete_dnodeint_at_index(stack, 0);
	delete_dnodeint_at_index(stack, 0);
	node = add_dnodeint(stack, sub);
	if (!node)
	{
		fprintf(stderr, FAILURE_MALLOC);
		free_handle(1);
		exit(EXIT_FAILURE);
	}
}

/**
 * _div - div instruction handler
 * @stack: double pointer to the stack
 * @nline: the line number in the file
 */
void _div(stack_t **stack, unsigned int nline)
{
	int div = 0;
	stack_t *node = NULL;
	stack_t *node_0 = get_dnodeint_at_index(*stack, 0);
	stack_t *node_1 = get_dnodeint_at_index(*stack, 1);

	if (dlistint_len(*stack) < 2)
	{
		fprintf(stderr, FAILURE_DIV, nline);
		free_handle(1);
		exit(EXIT_FAILURE);
	}

	if (node_0->n == 0)
	{
		fprintf(stderr, ERROR_DIV, nline);
		free_handle(1);
		exit(EXIT_FAILURE);
	}

	div = node_1->n / node_0->n;
	delete_dnodeint_at_index(stack, 0);
	delete_dnodeint_at_index(stack, 0);
	node = add_dnodeint(stack, div);
	if (!node)
	{
		fprintf(stderr, FAILURE_MALLOC);
		free_handle(1);
		exit(EXIT_FAILURE);
	}
}

/**
 * _mul - mul instruction handler
 * @stack: double pointer to the stack
 * @nline: the line number in the file
 */
void _mul(stack_t **stack, unsigned int nline)
{
	int mul = 0;
	stack_t *node = NULL;
	stack_t *node_0 = get_dnodeint_at_index(*stack, 0);
	stack_t *node_1 = get_dnodeint_at_index(*stack, 1);

	if (dlistint_len(*stack) < 2)
	{
		fprintf(stderr, FAILURE_MUL, nline);
		free_handle(1);
		exit(EXIT_FAILURE);
	}

	mul = node_1->n * node_0->n;
	delete_dnodeint_at_index(stack, 0);
	delete_dnodeint_at_index(stack, 0);
	node = add_dnodeint(stack, mul);
	if (!node)
	{
		fprintf(stderr, FAILURE_MALLOC);
		free_handle(1);
		exit(EXIT_FAILURE);
	}
}

/**
 * _mod - mod instruction handler
 * @stack: double pointer to the stack
 * @nline: the line number in the file
 */
void _mod(stack_t **stack, unsigned int nline)
{
	int mod = 0;
	stack_t *node = NULL;
	stack_t *node_0 = get_dnodeint_at_index(*stack, 0);
	stack_t *node_1 = get_dnodeint_at_index(*stack, 1);

	if (dlistint_len(*stack) < 2)
	{
		fprintf(stderr, FAILURE_MOD, nline);
		free_handle(1);
		exit(EXIT_FAILURE);
	}

	if (node_0->n == 0)
	{
		fprintf(stderr, ERROR_DIV, nline);
		free_handle(1);
		exit(EXIT_FAILURE);
	}

	mod = node_1->n % node_0->n;
	delete_dnodeint_at_index(stack, 0);
	delete_dnodeint_at_index(stack, 0);
	node = add_dnodeint(stack, mod);
	if (!node)
	{
		fprintf(stderr, FAILURE_MALLOC);
		free_handle(1);
		exit(EXIT_FAILURE);
	}
}

/**
 * _swap - swap instruction handler
 * @stack: double pointer to the stack
 * @nline: the line number in the file
 */
void _swap(stack_t **stack, unsigned int nline)
{
	stack_t *temp = *stack, *node = NULL;
	int num;

	if (dlistint_len(*stack) < 2)
	{
		fprintf(stderr, FAILURE_SWAP, nline);
		free_handle(1);
		exit(EXIT_FAILURE);
	}

	temp = get_dnodeint_at_index(*stack, 0);
	num = temp->n;
	delete_dnodeint_at_index(stack, 0);
	node = insert_dnodeint_at_index(stack, 1, num);
	if (!node)
	{
		fprintf(stderr, FAILURE_MALLOC);
		free_handle(1);
		exit(EXIT_FAILURE);
	}
}
