#include "monty.h"
/**
 * process_file - Process lines from a file and execute instructions
 * @file: Pointer to the file to be processed
 * @stack: Pointer to the stack
 *
 * This function reads lines from a file, tokenizes each line into opcode
 * and argument, and executes corresponding instructions.
 */
void process_file(FILE *file, stack_t **stack)
{
	char line[100];
	unsigned int line_number = 0;

	while (fgets(line, sizeof(line), file) != NULL)
	{
		char *opcode = strtok(line, " \n\t$");
		char *arg = strtok(NULL, " \n\t$");

		line_number++;

		execute_instruction(stack, opcode, arg, line_number);
	}
}



/**
 * free_stack - Frees a stack.
 * @stack: Pointer to the stack.
 */
void free_stack(stack_t *stack)
{
	stack_t *current = stack;

	while (current)
	{
		stack_t *next = current->next;

		free(current);
		current = next;
	}
}
