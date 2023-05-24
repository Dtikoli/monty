#include "monty.h"

/**
 * _nop - nop instruction handler
 * @stack: double pointer to the stack
 * @nline: the line number in the file
 */
void _nop(stack_t **stack, unsigned int nline)
{
	(void)stack;
	(void)nline;
}

/**
 * _rotl - rotl instruction handler
 * @stack: double pointer to the stack
 * @nline: the line number in the file
 */
void _rotl(stack_t **stack, unsigned int nline)
{
	stack_t *temp = *stack;
	int num  = 0;

	(void)nline;

	if (*stack == NULL)
		return;
	temp = get_dnodeint_at_index(*stack, 0);
	num = temp->n;
	delete_dnodeint_at_index(stack, 0);
	add_dnodeint_end(stack, num);
}

/**
 * _rotr - rotr instruction handler
 * @stack: double pointer to the stack
 * @nline: the line number in the file
 */
void _rotr(stack_t **stack, unsigned int nline)
{
	stack_t *temp = *stack;
	int num = 0, len = dlistint_len(*stack);

	(void)nline;

	if (*stack == NULL)
		return;
	temp = get_dnodeint_at_index(*stack, len - 1);
	num = temp->n;
	delete_dnodeint_at_index(stack, len - 1);
	add_dnodeint(stack, num);
}

/**
 * _stack - stack instruction handler
 * @stack: double pointer to the stack
 * @nline: the line number in the file
 */
void _stack(stack_t **stack, unsigned int nline)
{
	(void)stack;
	(void)nline;
	info.sflag = 0;
}


/**
 * _queue - queue instruction handler
 * @stack: double pointer to the stack
 * @nline: the line number in the file
 */
void _queue(stack_t **stack, unsigned int nline)
{
	(void)stack;
	(void)nline;
	info.sflag = 1;
}
