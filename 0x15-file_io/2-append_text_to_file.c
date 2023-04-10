#include "main.h"

/**
 * append_text_to_file - appends text at the end of a file
 * @text_content: added content.
 * @filename: filename.
 * Return: 1 if the file exists. -1 if the fails does not existor if it fails.
 */

int append_text_to_file(const char *filename, char *text_content)

{
	int view;
	int i;
	int prnt;

	if (!filename)
		return (-1);

	view = open(filename, O_WRONLY | O_APPEND);

	if (view == -1)
		return (-1);

	if (text_content)
	{
		for (i = 0; text_content[i]; i++)
			;

		prnt = write(view, text_content, i);

		if (prnt == -1)
			return (-1);
	}

	close(view);

	return (1);
}
