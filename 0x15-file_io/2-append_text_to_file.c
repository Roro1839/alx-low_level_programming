#include "main.h"
#include <string.h>

/**
 * append_text_to_file - append text to an exiting file
 * @filename: is the name of the file
 * @text_content: is the NULL terminated string to add at the end of the file
 * Return: 1 on success and -1 on failure
 */

int append_text_to_file(const char *filename, char *text_content)
{
	int fd;

	if (!filename)
		return (-1);

	fd = open(filename, O_WRONLY | O_APPEND);
	if (fd == -1)
		return (-1);

	if (text_content)
	{
		if (write(fd, text_content, _strlen(text_content)) == -1)
			return (-1);
	}
	close(fd);
	return (1);
}
/**
 * _strlen - returns the length of a string
 * @s: string to count
 * Return: string length
 */

int _strlen(char *s)
{
	int c = 0;

	while (s[c])
		c++;

	return (c);
}
