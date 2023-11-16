#include "monty.h"

/**
 * main - Monty interpreter main function
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 on success, EXIT_FAILURE on failure
 */
int main(int argc, char *argv[])
{
	FILE *file;
	stack_t *stack;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}
	stack = NULL;
	process_file(file, &stack);
	fclose(file);
	free_stack(stack);

	return (EXIT_SUCCESS);
}
