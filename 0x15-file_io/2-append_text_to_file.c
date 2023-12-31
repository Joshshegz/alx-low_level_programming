#include "main.h"

/**
 * append_text_to_file - Appends text at the end of a file.
 * @filename: A pointer to the name of the file.
 * @my_text_content: The string to add to the end of the file.
 *
 * Return: If the function fails or filename is NULL - -1.
 *         If the file does not exist the user lacks write permissions - -1.
 *         Otherwise - 1.
 */
int append_text_to_file(const char *filename, char *my_text_content)
{
	int Open_My_File, write_To_File, len = 0;

	if (filename == NULL)
		return (-1);

	if (my_text_content != NULL)
	{
		for (len = 0; my_text_content[len];)
			len++;
	}

	Open_My_File = open(filename, O_WRONLY | O_APPEND);
	write_To_File = write(Open_My_File, my_text_content, len);

	if (Open_My_File == -1 || write_To_File == -1)
		return (-1);

	close(Open_My_File);

	return (1);
}
