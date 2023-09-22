#include "shell.h"

/**
  * cleanup_and_exit - Frees memory allocation
  * @buffer: Buffer to be freed
  * @arg: The array of arguments passed
  * @exit_code: Exit code value
  *
  */

void cleanup_and_exit(char *buffer, char *arg[], int exit_code)
{
	if (arg[0])
		free(arg[0]);

	if (buffer)
		free(buffer);

	exit(exit_code);
}

/**
  * prompt_user - Initializes the shell in various modes
  */

void prompt_user(void)
{
	char *print = "(CShell)$ ";

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, print, 10);
}

/**
  * read_input - Reads the stream from the buffer
  * @buffer: Input reads
  *
  * Return: 0 success, -1
  */

int read_input(char **buffer)
{
	size_t buf_size = 0;
	ssize_t read_lines;
	int i;

	read_lines = getline(buffer, &buf_size, stdin);

	if (read_lines == -1)
	{
		if (*buffer != NULL)
		{
			_putchar('\n');
			cleanup_and_exit(*buffer, NULL, 0);
		}
		else
		{
			_putchar('\n');
			exit(1);
		}
	}

	for (i = 0; (*buffer)[i]; i++)
	{
		if ((*buffer)[i] == '\n')
			(*buffer)[i] = 0;
	}

	return (read_lines == 0 ? -1 : 0);
}


/**
  * tokenize_input - Tokenize the input string
  * @buffer: Stream to tokenize
  * @arg: Args to pass in
  */

void tokenize_input(char *buffer, char *arg[])
{
	char *token;
	int i = 0;

	token = strtok(buffer, " \n");

	while (token && i < MAX_ARG_COUNT - 1)
	{
		arg[i++] = strdup(token);
		token = strtok(NULL, " \n");
	}

	arg[i] = NULL;
}

/**
  * execute_command - Handles the command execution
  * @path: Path of execution
  * @arg: Arguments passed
  */

void execute_command(char *path, char *arg[])
{
	pid_t child_pid;
	int status;

	child_pid = fork();

	if (child_pid == -1)
	{
		perror("Error, fork failed");
		cleanup_and_exit(NULL, arg, 98);
	}
	else if (child_pid == 0)
	{
		if (execve(path, arg, NULL) == -1)
		{
			perror("Error: execve failed");
			cleanup_and_exit(NULL, arg, 1);
		}
	}
	else
	{
		wait(&status);
	}
}
