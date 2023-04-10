#include "main.h"
#include <stdio.h>

/**
 * err - checks if files can be opened.
 * @file_from: file_from.
 * @file_to: file_to.
 * @argv: arguments vector.
 * Return: no return.
 */

void err(int file_from, int file_to, char *argv[])

{
	if (file_from == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}
	if (file_to == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		exit(99);
	}
}

/**
 * main - checks the code.
 * @argc: number of arguments.
 * @argv: arguments vector.
 * Return: Always 0.
 */

int main(int argc, char *argv[])

{
	int file_from, file_to, code_red;
	ssize_t x, y;
	char set[1024];

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "%s\n", "Usage: cp file_from file_to");
		exit(97);
	}

	file_from = open(argv[1], O_RDONLY);
	file_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC | O_APPEND, 0664);
	err(file_from, file_to, argv);

	x = 1024;
	while (x == 1024)
	{
		x = read(file_from, set, 1024);
		if (x == -1)
			err(-1, 0, argv);
		y = write(file_to, set, x);
		if (y == -1)
			err(0, -1, argv);
	}

	code_red = close(file_from);
	if (code_red == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_from);
		exit(100);
	}

	code_red = close(file_to);
	if (code_red == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_from);
		exit(100);
	}
	return (0);
}
