#include "monty.h"

/**
 * eexecute_instruction - execute instructions
 * @stack: Pointer to the stack
 * @arg: Argument associated with the push opcode
 * @opcode: opcode
 * @line_number: Line number in the file
 */
void execute_instruction(stack_t **stack, char *opcode, char *arg,
		 unsigned int line_number)
{
	instruction_t instructions[] = {
	{"push", execute_push},
	{"pall", execute_pall},
	{"pint", execute_pint},
	{"pop", execute_pop},
	{"swap", execute_swap},
	{"add", execute_add},
	{"nop", execute_nop},
};
	size_t i;

	for (i = 0; i < NUM_INSTRUCTIONS; i++)
	{
		if (strcmp(opcode, instructions[i].opcode) == 0)
		{

			instructions[i].f(stack, arg, line_number);
			return;
		}
	}

	fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
	free_stack(*stack);
	exit(EXIT_FAILURE);
}
/**
 * execute_push - Executes the push instruction
 * @stack: Pointer to the stack
 * @arg: Argument associated with the push opcode
 * @line_number: Line number in the file
 *
 * This function pushes an integer onto the stack.
 */
void execute_push(stack_t **stack, char *arg, unsigned int line_number)
{
	char *endptr;
	long value = strtol(arg, &endptr, 10);

	errno = 0;

	if ((errno == ERANGE && (value == LONG_MAX || value == LONG_MIN)) ||
		(errno != 0 && value == 0) || endptr == arg)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	if (*endptr != '\0')
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	if (value > INT_MAX || value < INT_MIN)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	push(stack, (int)value, line_number);
}

/**
 * push - Pushes an element to the stack.
 * @stack: Pointer to the stack.
 * @value: Value to push onto the stack.
 * @line_number: Line number of the instruction.
 * Return: void
 */

void push(stack_t **stack, int value, unsigned int line_number)
{
	stack_t *new_node = malloc(sizeof(stack_t));

	(void)(line_number);

	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = *stack;
	if (*stack)
		(*stack)->prev = new_node;
	*stack = new_node;
}

/**
 * execute_nop - Does nothing
 * @stack: Pointer to the stack
 * @line_number: Line number in the file
 * @arg: char pointer
 *
 * This function doesn't perform any operation.
 */
void execute_nop(stack_t **stack, char *arg, unsigned int line_number)
{
	(void)(stack);
	(void)(arg);
	(void)(line_number);
}
