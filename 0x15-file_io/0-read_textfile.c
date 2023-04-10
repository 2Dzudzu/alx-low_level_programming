#include "main.h"

/**
 * read_textfile - reads a text file and prints the letters.
 * @filename: filename.
 * @letters: numbers of letters printed.
 * Return: numbers of letters printed. It fails, returns 0.
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	int ned;
	ssize_t x, y;
	char *vex;

	if (!filename)
		return (0);

	ned = open(filename, O_RDONLY);

	if (ned == -1)
		return (0);

	vex = malloc(sizeof(char) * (letters));

	if (!vex)
		return (0);

	x = read(ned, vex, letters);

	y = write(STDOUT_FILENO, vex, x);

	close(ned);

	free(vex);

	return (y);
}
