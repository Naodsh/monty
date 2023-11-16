#include "monty.h"

/**
 * execute_instruction - Executes an instruction based on opcode
 * @stack: Pointer to the stack
 * @opcode: Opcode to be executed
 * @arg: Argument associated with the opcode
 * @line_number: Line number in the file
 *
 * This function executes specific instructions based on the given opcode.
 * Handles various operations like push, pall, pint, pop, and unknown.
 */
void execute_instruction(stack_t **stack, char *opcode, char *arg,
		unsigned int line_number)
{
	if (strcmp(opcode, "push") == 0)
	{
		char *endptr;
		long value = strtol(arg, &endptr, 10);

		errno = 0;

		if ((errno == ERANGE && (value == LONG_MAX || value == LONG_MIN))
				|| (errno != 0 && value == 0) || endptr == arg)
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
	else if (strcmp(opcode, "pall") == 0)
		pall(stack, line_number);
	else if (strcmp(opcode, "pint") == 0)
		pint(stack, line_number);
	else if (strcmp(opcode, "pop") == 0)
		pop(stack, line_number);
	else
	{
		fprintf(stderr, "L%u: unknown instruction %s\n",
				line_number, opcode);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
}
