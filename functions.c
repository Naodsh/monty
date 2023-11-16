#include "monty.h"

/**
 * execute_pall - Prints all the values on the stack.
 * @stack: Pointer to the stack.
 * @arg: not used in this func.
 * @line_number: Line number of the instruction.
 */
void execute_pall(stack_t **stack, char *arg, unsigned int line_number)
{
	stack_t *current = *stack;

	(void)(line_number);
	(void)(arg);

	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

/**
 * execute_pint - Prints the top values on the stack.
 * @stack: Pointer to the stack.
 * @arg: not used in this func.
 * @line_number: Line number of the instruction.
 */
void execute_pint(stack_t **stack, char *arg, unsigned int line_number)
{
	(void)(arg);
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}
/**
 * execute_pop - delte from the top on the stack.
 * @stack: Pointer to the stack.
 * @arg: not used in this func.
 * @line_number: Line number of the instruction.
 */
void execute_pop(stack_t **stack, char *arg, unsigned int line_number)
{
	stack_t *top;

	(void)(arg);

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	top = *stack;
	*stack = top->next;
	if (*stack != NULL)
	{
		(*stack)->prev = NULL;
	}

	free(top);
}
