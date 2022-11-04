#include "main.h"
#include <string.h>
/**
 * create_file - create a file
 *
 * @filename: the name of the file to create
 * @text_content: a NULL terminated string to write to the file
 *
 * Return: 1 on success, -1 on failure
 * if the file already exists, truncate it
 * if filename is NULL return -1
 * if text_content is NULL create an empty file
 */

int create_file(const char *filename, char *text_content)
{
	int ag;

	if (filename == NULL)
		return (0);
	if (text_content == NULL)
		ag = open(filename, O_TRUNC);
	else
	{
		ag = open(filename, O_CREAT | O_RDWR | O_APPEND, 00600);
		if (ag == -1)
			return (-1);
		ag = write(ag, text_content, strlen(text_content));
	}
	if (ag == -1)
		return (0);
	return (1);

}
