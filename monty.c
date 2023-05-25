#include "monty.h"

info_t info = INFO_INIT;

/**
 * parse_monty - a parser for the monty bytecode intepreter
 */
void parse_monty(void)
{
	int nline = 0, nbytes = 1024;
	char *_gets = NULL;
	void (*opcode_func)(stack_t **, unsigned int);

	while (1)
	{
		nline++;
		info.line = malloc(nbytes);
		if (!info.line)
		{
			fprintf(stderr, FAILURE_MALLOC);
			exit(EXIT_FAILURE);
		}
		_gets = fgets(info.line, nbytes, info.fp);
		if (!_gets)
			return;
		info.words = strtow(info.line);
		if (info.words[0] == NULL || info.words[0][0] == '#')
		{
			free_handle(0);
			continue;
		}
		opcode_func = get_func(info.words);
		if (!opcode_func)
		{
			fprintf(stderr, ERROR_UNKNOWN, nline, info.words[0]);
			free_handle(1);
			exit(EXIT_FAILURE);
		}
		opcode_func(&(info.stack), nline);
		free_handle(0);
	}
}

/**
 * main - the entry point for monty interpreter
 * @argc: number of command line arguments
 * @argv: string array of command line arguments arguments
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, ERROR_USAGE);
		exit(EXIT_FAILURE);
	}

	info.fp = fopen(argv[1], "r");
	if (!info.fp)
	{
		fprintf(stderr, ERROR_FILE, argv[1]);
		exit(EXIT_FAILURE);
	}

	parse_monty();
	free_handle(1);

	return (EXIT_SUCCESS);
}
