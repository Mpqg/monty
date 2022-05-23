#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
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
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct globals - global structure to use in the functions
 * @lifo: is stack or queue
 * @cont: current line
 * @arg: second parameter inside the current line
 * @head: doubly linked list
 * @fd: file descriptor
 * @buffer: input text
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct globals
{
	int lifo;
	unsigned int cont;
	char *arg;
	stack_t *head;
	FILE *f;
	char *buffer;
} global_t;

extern global_t varglobal;

void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void print_int(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int new_item);
void add(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);

void mul(stack_t **stack, unsigned int line_number);
void div_op(stack_t **stack, unsigned int line_number);
void mod(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void prints_char(stack_t **stack, unsigned int line_number);
void print_str(stack_t **stack, unsigned int line_number);
void rotl(stack_t **stack, unsigned int new_number);
void _rotr(stack_t **stack, unsigned int line_number);

void queue(stack_t **stack, unsigned int line_number);
void stack(stack_t **stack, unsigned int line_number);
void add_nodeint(stack_t **stack, unsigned int line_number);
void parser(char *cont, unsigned int line_number);
void (*get_opfun(char *tok_a))(stack_t **stack, unsigned int line_number);

void initialize_buffer(char *s, int size);
void initialize_array(char **s, int size);

void replace_emptylines(char *buff, char **copy);
int count_lines(char *s);
void lines_to_array(char *line, char **copy);

void free_dlistint(stack_t *head);
stack_t *add_dnodeint_end(stack_t **head, const int n);
stack_t *add_dnodeint(stack_t **head, const int n);
size_t print_dlistint(stack_t *h);
int delete_dnodeint_at_index(stack_t **head, unsigned int index);

void free_varglobal(void);

#define MALLOC_ERROR1(BUFF)
do{
	fprintf(stderr, "Error: malloc failed");
	exit(EXIT_FAILURE);
} while (0)

#define INSTRUCTION_ERROR(LINE, INSTRUCTION, STACK)
	do
{
	fprintf(stderr, "L%d: unknown instruction %s\n", LINE, INSTRUCTION);
	free_dlistint(STACK);
	exit(EXIT_FAILURE);
}
while (0)

#endif
