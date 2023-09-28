#include "main.h"
#include <stdlib.h>

/**
 * read_textfile- Read text file print to STDOUT.
 * @filename: text file being read
 * @letters: number of letters to be read
 * Return: w- actual number of bytes read and printed
 *        0 when function fails or filename is NULL.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *buf;
	ssize_t my_file;
	ssize_t write_To_File;
	ssize_t read_My_File;

	my_file = open(filename, O_RDONLY);
	if (my_file == -1)
		return (0);
	buf = malloc(sizeof(char) * letters);
	read_My_File = read(my_file, buf, letters);
	write_To_File = write(STDOUT_FILENO, buf, read_My_File);

	free(buf);
	close(my_file);
	return (write_To_File);
}
