#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <limits.h>
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, char *arg, unsigned int line_number);
} instruction_t;



#define NUM_INSTRUCTIONS (sizeof(instructions) / sizeof(instruction_t))

/* Function prototypes */
void execute_pall(stack_t **stack, char *arg, unsigned int line_number);
void execute_push(stack_t **stack, char *arg, unsigned int line_number);
void execute_pint(stack_t **stack, char *arg, unsigned int line_number);
void execute_pop(stack_t **stack, char *arg, unsigned int line_number);
void execute_nop(stack_t **stack, char *arg, unsigned int line_number);
void execute_swap(stack_t **stack, char *arg, unsigned int line_number);
void execute_add(stack_t **stack, char *arg, unsigned int line_number);

void execute_sub(stack_t **stack, char *arg, unsigned int line_number);
void execute_div(stack_t **stack, char *arg, unsigned int line_number);
void execute_mul(stack_t **stack, char *arg, unsigned int line_number);
void execute_mod(stack_t **stack, char *arg, unsigned int line_number);

void push(stack_t **stack, int value, unsigned int line_number);

void execute_instruction(stack_t **stack, char *opcode, char *arg,
						 unsigned int line_number);
void process_file(FILE *file, stack_t **stack);
void free_stack(stack_t *stack);

#endif /* MONTY_H */
