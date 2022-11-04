#include "main.h"

/**
 *read_textfile - reads a text file and prints
 *@filename: buffer
 *@letters: the number of letters it should read and print
 *
 *Return: size_t returns the actual number of letters it could read and print
 *if the file can not be opened or read, return 0
 *if filename is NULL return 0
 *if write fails or does not write the expected amount of bytes, return 0
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	ssize_t o, r, w;
	char *buff;

	if (filename == NULL)
		return (0);
	buff = malloc(sizeof(char) * letters);
	if (buff == NULL)
		return (0);
	o = open(filename, O_RDONLY);
	r = read(o, buff, letters);
	if (o == -1 || r == -1)
		return (0);
	w = write(STDOUT_FILENO, buff, r);
	if (w == -1 || w != r)
	{
		free(buff);
		return (0);
	}
	free(buff);
	close(o);
	return (w);
}

