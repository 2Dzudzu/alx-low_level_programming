#include "main.h"

/**
 * create_file - creates a file
 * @filename: filename.
 * @text_content: content writed in the file.
 * Return: 1 if it success. -1 if it fails.
 */

int create_file(const char *filename, char *text_content)

{
	int view;
	int i;
	int prnt;

	if (!filename)
		return (-1);

	view = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);

	if (view == -1)
		return (-1);

	if (!text_content)
		text_content = "";

	for (i = 0; text_content[i]; i++)
		;

	prnt = write(view, text_content, i);

	if (prnt == -1)
		return (-1);

	close(view);

	return (1);
}
