#include "main.h"

/**
 * create_file - Creates a file.
 * @filename: A pointer to the name of the file to create.
 * @my_text_content: A pointer to a string to write to the file.
 *
 * Return: If the function fails - -1.
 *         Otherwise - 1.
 */
int create_file(const char *filename, char *my_text_content)
{
	int my_File, write_To_File, len = 0;

	if (filename == NULL)
		return (-1);

	if (my_text_content != NULL)
	{
		for (len = 0; my_text_content[len];)
			len++;
	}

	my_File = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	write_To_File = write(my_File, my_text_content, len);

	if (my_File == -1 || write_To_File == -1)
		return (-1);

	close(my_File);

	return (1);
}
