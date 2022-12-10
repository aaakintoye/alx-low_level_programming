#include "main.h"

/**
 * read_textfile - Read a textfile and prints the contents to POSIX STDOUT
 * @filename: name of the file to read from
 * @letters: number of characters it should print to the STDOUT
 * Return: number of characters printed
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fp;
	ssize_t fpRead, fpWrite, fpClose;
	char *lineBuffer;

	if (filename == NULL)
		return (0);

	lineBuffer = malloc(sizeof(char) * letters);

	if (lineBuffer == NULL)
		return (-1);

	fp = open(filename, O_RDONLY);

	if (fp == -1)
		return (0);

	fpRead = read(fp, lineBuffer, letters);

	if (fpRead == -1)
		return (-1);

	fpWrite = write(STDOUT_FILENO, lineBuffer, fpRead);

	if (fpWrite == -1)
		return (-1);
	fpClose = close(fp);

	if (fpClose == -1)
		return (-1);

	return (fpRead);
}
