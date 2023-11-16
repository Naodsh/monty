#include "monty.h"
/**
 * execute_sub - Subtracts the top elem from the second top elem of the stack
 * @stack: Pointer to the stack
 * @line_number: Line number in the file
 * @arg: char pointer
 *
 */
void execute_sub(stack_t **stack, char *arg, unsigned int line_number)
{
	(void)(arg);

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n",
				line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n -= (*stack)->n;
	execute_pop(stack, arg, line_number);
}

/**
 * execute_div - Divides the second top element by the top element of the stack
 * @stack: Pointer to the stack
 * @line_number: Line number in the file
 * @arg: char pointer
 *
 */
void execute_div(stack_t **stack, char *arg, unsigned int line_number)
{
	int top;

	(void)(arg);

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	top = (*stack)->n;

	if (top == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n /= top;
	execute_pop(stack, arg, line_number);
}

/**
 * execute_mul - Multiplies the 2nd top element with the top elem of the stack
 * @stack: Pointer to the stack
 * @line_number: Line number in the file
 * @arg: char pointer
 *
 */
void execute_mul(stack_t **stack, char *arg, unsigned int line_number)
{
	(void)(arg);

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n",
				line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n *= (*stack)->n;
	execute_pop(stack, arg, line_number);
}

/**
 * execute_mod - Computes the reminder
 * @stack: Pointer to the stack
 * @line_number: Line number in the file
 * @arg: char pointer
 *
 */
void execute_mod(stack_t **stack, char *arg, unsigned int line_number)
{
	int top;

	(void)(arg);

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n",
				line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	top = (*stack)->n;

	if (top == 0)
	{
		fprintf(stderr, "L%u: division by zero\n",
				line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n %= top;
	execute_pop(stack, arg, line_number);
}
