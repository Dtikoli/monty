#include "monty.h"

/**
 * _sub - sub instruction handler
 * @stack: double pointer to the stack
 * @nline: the line number in the file
 */
void _sub(stack_t **stack, unsigned int nline)
{
	int sub = 0;
	stack_t *nsub = NULL;
	stack_t *node0 = get_dnodeint_at_index(*stack, 0);
	stack_t *node1 = get_dnodeint_at_index(*stack, 1);

	if (dlistint_len(*stack) < 2)
	{
		fprintf(stderr, FAILURE_SUB, nline);
		free_handle(1);
		exit(EXIT_FAILURE);
	}

	sub = node1->n - node0->n;
	delete_dnodeint_at_index(stack, 0);
	delete_dnodeint_at_index(stack, 0);
	nsub = add_dnodeint(stack, sub);
	if (!nsub)
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
	stack_t *ndiv = NULL;
	stack_t *node0 = get_dnodeint_at_index(*stack, 0);
	stack_t *node1 = get_dnodeint_at_index(*stack, 1);

	if (dlistint_len(*stack) < 2)
	{
		fprintf(stderr, FAILURE_DIV, nline);
		free_handle(1);
		exit(EXIT_FAILURE);
	}

	if (node0->n == 0)
	{
		fprintf(stderr, ERROR_DIV, nline);
		free_handle(1);
		exit(EXIT_FAILURE);
	}

	div = node1->n / node0->n;
	delete_dnodeint_at_index(stack, 0);
	delete_dnodeint_at_index(stack, 0);
	ndiv = add_dnodeint(stack, div);
	if (!ndiv)
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
	stack_t *nmul = NULL;
	stack_t *node0 = get_dnodeint_at_index(*stack, 0);
	stack_t *node1 = get_dnodeint_at_index(*stack, 1);

	if (dlistint_len(*stack) < 2)
	{
		fprintf(stderr, FAILURE_MUL, nline);
		free_handle(1);
		exit(EXIT_FAILURE);
	}

	mul = node1->n * node0->n;
	delete_dnodeint_at_index(stack, 0);
	delete_dnodeint_at_index(stack, 0);
	nmul = add_dnodeint(stack, mul);
	if (!nmul)
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
	stack_t *nmode = NULL;
	stack_t *node0 = get_dnodeint_at_index(*stack, 0);
	stack_t *node1 = get_dnodeint_at_index(*stack, 1);

	if (dlistint_len(*stack) < 2)
	{
		fprintf(stderr, FAILURE_MOD, nline);
		free_handle(1);
		exit(EXIT_FAILURE);
	}

	if (node0->n == 0)
	{
		fprintf(stderr, ERROR_DIV, nline);
		free_handle(1);
		exit(EXIT_FAILURE);
	}

	mod = node1->n % node0->n;
	delete_dnodeint_at_index(stack, 0);
	delete_dnodeint_at_index(stack, 0);
	nmode = add_dnodeint(stack, mod);
	if (!nmode)
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
	stack_t *current = *stack, *nswap = NULL;
	int n;

	if (dlistint_len(*stack) < 2)
	{
		fprintf(stderr, FAILURE_SWAP, nline);
		free_handle(1);
		exit(EXIT_FAILURE);
	}

	current = get_dnodeint_at_index(*stack, 0);
	n = current->n;
	delete_dnodeint_at_index(stack, 0);
	nswap = insert_dnodeint_at_index(stack, 1, n);
	if (!nswap)
	{
		fprintf(stderr, FAILURE_MALLOC);
		free_handle(1);
		exit(EXIT_FAILURE);
	}
}
